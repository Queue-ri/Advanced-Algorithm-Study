import sys
from collections import defaultdict
input = sys.stdin.readline

def dfs(vertex):
    global flag
    visited[vertex] = False
    adj = graph[vertex]
    for node in adj:
        if visited[node] == False:
            flag = False
        elif visited[node] == None:
            dfs(node)
    sequence.append(vertex)
    visited[vertex] = True


case = int(input().rstrip())
for _ in range(case):
    graph = defaultdict(set)
    N = int(input().rstrip())
    words = []
    visited = {}
    for _ in range(N):
        words.append(input().rstrip())
    # 이전 문자열과 비교하면서 다르다면 그래프에 추가시켜주기
    prev = ""
    for word in words:
        for i in range(min(len(prev), len(word))):
            if prev[i] != word[i]:
                graph[prev[i]].add(word[i])
                visited[prev[i]] = None
                visited[word[i]] = None
                break
        prev = word
    answer = [] #return value
    for vertex in visited.keys():
        if visited[vertex] == None:
            flag = True
            sequence = []
            dfs(vertex)
            if flag:
                answer.extend(sequence)
            else:
                break
    if flag:
        alphabet = [a if a not in answer else "" for a in 'abcdefghijklmnopqrstuvwxyz']
        answer.reverse()
        answer = "".join(answer+alphabet)
        print(answer)
    else:
        print("INVALID")


