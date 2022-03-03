import sys
input = sys.stdin.readline
def search_kmp(n,h):
    length = len(h)
    for i in range(len(n)):
        if n[i:i+length] == h: # 문자열 슬라이싱으로 일치연산 진행가
            return i

def get_direction(s):
    answer = 0
    right = True
    for i in range(len(s)-1):
        if right:
            answer += search_kmp(s[i+1] * 2, s[i])
        else:
            answer += search_kmp(s[i] * 2, states[i+1])
        right = not right
    return answer

case = int(sys.stdin.readline().rstrip())
for _ in range(case):
    states = []
    n = int(input().rstrip())
    for _ in range(n+1):
        states.append(input().rstrip())
    print(get_direction(states))
