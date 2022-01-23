import requests
import uuid
from bs4 import BeautifulSoup
import pandas as pd
from tabulate import tabulate
import sys
import time


URL = 'https://algospot.com/accounts/login/?next=/'
client = requests.session()

# Retrieve the CSRF token
client.get(URL)  # sets cookie
csrftoken = client.cookies['csrftoken']
login_data = dict(csrfmiddlewaretoken=csrftoken, username=sys.argv[1], password=sys.argv[2], next='/')

print('Request to ' + URL)
r = client.post(URL, data=login_data, headers=dict(Referer=URL))
print(r)
print()

#ID = input('Problem ID: ').upper()
ID = sys.argv[3].upper()
URL = 'https://algospot.com/judge/problem/submit/' + ID
client.get(URL)  # sets cookie
csrftoken = client.cookies['csrftoken']

#lang = input('Language: ')
lang = sys.argv[4]
#filepath = input('File path: ')
filepath = sys.argv[5]
file = open(filepath, mode='r')
code = file.read()
file.close()

comment = '//' if lang == 'c' or lang == 'cpp' else '#'
repo = 'https://github.com/Queue-ri/Advanced-Algorithm-Study'
info = comment + " This code was submitted by AOJI from " + repo + ".\n" + comment + " Please contact qriositylog@gmail.com if there's any problem."
submit_uuid = str(uuid.uuid4())
aoji_uuid = comment + " AOJI UUID: " + submit_uuid

src = aoji_uuid + '\n' + info + '\n\n' + code
print(src)

submit_data = dict(csrfmiddlewaretoken=csrftoken, language=lang, source=src)

print('Request to ' + URL)
r = client.post(URL, data=submit_data, headers=dict(Referer=URL))
print(r)
print()

# Parse and send judge result
URL = 'https://algospot.com/judge/submission/recent/?problem=' + ID + '&user=' + sys.argv[1] + '&language=' + lang + '&state='
r = client.get(URL)
html = r.text

soup = BeautifulSoup(html, "lxml")
table = soup.find('table')

df = pd.read_html(str(table))[0]
print(tabulate(df, headers='keys', tablefmt='psql'))

print('----')
JID_list = df['#'].tolist()

match_JID = -1
for JID in JID_list:
    URL = 'https://algospot.com/judge/submission/detail/' + str(JID)
    r = client.get(URL)
    html = r.text
    soup = BeautifulSoup(html, "lxml")
    src_section = soup.find('section', {'class': 'sourcecode'})
    codeblock = src_section.find('pre')

    try:
        #print(codeblock.findAll('span')[0])
        uuid_comment = str(codeblock.findAll('span')[0])
    except IndexError:
        pass

    if 'AOJI UUID' in uuid_comment:
        if lang == 'py3':
            parsed_uuid = uuid_comment[29:65]
        else:
            parsed_uuid = uuid_comment[31:67]
        print('Parsed: ' + parsed_uuid + ' from ' + str(JID))
        if parsed_uuid == submit_uuid:
            match_JID = JID
            break

if match_JID == -1:
    print("----")
    print('No match. Something went wrong..')
    exit(1)

match_df = df.loc[df['#'] == match_JID]

URL = 'https://algospot.com/judge/submission/recent/?problem=' + ID + '&user=' + sys.argv[1] + '&language=' + lang + '&state='

while match_df['결과'].values[0] == "컴파일중" or match_df['결과'].values[0] == "실행중":
    print("---")
    print("AOJ server is busy. Wait 5 seconds.")
    time.sleep(5)
    print("Update submission table.")

    r = client.get(URL)
    html = r.text

    soup = BeautifulSoup(html, "lxml")
    table = soup.find('table')

    df = pd.read_html(str(table))[0]
    print(tabulate(df, headers='keys', tablefmt='psql'))
    match_df = df.loc[df['#'] == match_JID]

print("----")
print('[AOJ Result]')
print('- Judge ID: ' + str(match_JID))
print('- Problem ID: ' + ID)
print('- Language: ' + lang)
print('- Result: ' + match_df['결과'].values[0])
print('- Performance: ' + str(match_df['수행시간'].values[0]))

with open(".github/aoji_report.md", "w", encoding="utf-8") as report:
    report.write("# AOJI Report\n")

    if match_df['결과'].values[0] == "정답":
        report.write("✔ **Your code has been accepted!**\n")
    else:
        report.write("❌ **UH OH...Your code has not been accepted.**\n")

    report.write("\n## 🎯 AOJ Result\n")
    report.write("|Judge ID|Problem ID|Language|Result|Performance|\n")
    report.write("|:------:|:--------:|:------:|:----:|:---------:|\n")
    report.write(f"|[{match_JID}](https://algospot.com/judge/submission/detail/{match_JID})|{ID}|{lang}|{match_df['결과'].values[0]}|{match_df['수행시간'].values[0]}|\n")

    if sys.argv[6] != str(match_df['수행시간'].values[0]):
        report.write("\n⚠ Performance doesn't match. (±4ms might be a temporary AOJ error)\n")

    report.write("\n## 🎯 Tested Commit\n")
    report.write("|Hash|Language|File Path|Performance|\n")
    report.write("|:--------:|:------:|:-------:|:---------:|\n")
    report.write(f"|{sys.argv[7][:7]}|{lang}|{filepath}|{sys.argv[6]}|\n")

    report.write("\n## 🎯 Submission Log\n")
    report.write("<details>\n")
    report.write("<summary>Click here to extend</summary>\n")
    report.write("<br/>\n\n")
    report.close()
