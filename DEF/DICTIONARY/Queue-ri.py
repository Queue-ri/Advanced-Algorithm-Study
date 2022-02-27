import sys
from collections import defaultdict
input = sys.stdin.readline

def main():
    adj = None
    visited = None
    order = None

    def check(order):
        order = order[::-1]
        for i in range(1, len(order)):
            j = i-1
            if adj[order[i]][order[j]]: return False
        return order

    def dfs(c):
        visited[c] = 1
        for e in adj[c]:
            if not visited[e]:
                dfs(e)
        order.append(c)

    for TC in range(int(input())):
        adj = defaultdict(lambda: defaultdict(int))
        N = int(input())
        words = []
        for i in range(N): words.append(input().rstrip())
        for i in range(1, N): # adj initialization
            j = i-1
            L = min(len(words[j]), len(words[i]))
            for k in range(L):
                if words[j][k] != words[i][k]:
                    adj[words[j][k]][words[i][k]] = 1
                    break # following characters are meaningless

        visited = defaultdict(int)
        order = []
        for c in reversed('abcdefghijklmnopqrstuvwxyz'):
            if not visited[c]: dfs(c)
        order = check(order)
        print(''.join(order) if order else 'INVALID HYPOTHESIS')

if __name__ == '__main__':
    main()