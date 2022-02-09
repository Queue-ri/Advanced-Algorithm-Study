import sys

case = int(sys.stdin.readline().rstrip())
for _ in range(case):
    brackets = sys.stdin.readline().rstrip()
    queue = []
    answer = "YES"

    for char in brackets:
        if char in ['(','[','{']:
            queue.append(char)
        elif len(queue) == 0:
            answer = "NO"
            break
        elif char == ')' and queue[-1] == '(':
            queue.pop()
        elif char == ']' and queue[-1] == '[':
            queue.pop()
        elif char == '}' and queue[-1] == '{':
            queue.pop()
        else:
            answer == "NO"
            break
    if len(queue) > 0:
        answer = "NO"
    print(answer)
