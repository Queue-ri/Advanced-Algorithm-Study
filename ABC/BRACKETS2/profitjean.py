import sys

case = int(sys.stdin.readline().rstrip())
for _ in range(case):
    brackets = sys.stdin.readline().rstrip()
    stack = []
    answer = "YES"

    for char in brackets:
        if char in ['(','[','{']:
            stack.append(char)
        elif len(stack) == 0:
            answer = "NO"
            break
        elif char == ')' and stack[-1] == '(':
            stack.pop()
        elif char == ']' and stack[-1] == '[':
            stack.pop()
        elif char == '}' and stack[-1] == '{':
            stack.pop()
        else:
            answer == "NO"
            break
    if len(stack) > 0:
        answer = "NO"
    print(answer)
