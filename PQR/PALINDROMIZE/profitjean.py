import sys
input = sys.stdin.readline

def generate_partial(s1, s2):
    N = len(s1)
    ret = [0] * N
    begin, matched = 1, 0

    while begin < N:
        if s1[begin] == s2[matched]:
            matched += 1
            ret[begin] = matched
            begin += 1
        else:
            if matched == 0:
                begin += 1
            else:
                matched = ret[matched-1]
    return ret[N-1]


case = int(input().rstrip())
for _ in range(case):
    palindrome = input().rstrip()
    rpalindrome = palindrome[::-1]
    if palindrome == rpalindrome:
        print(len(palindrome))
        continue

    cross = generate_partial(palindrome, rpalindrome)
    print(len(palindrome)*2 - cross)