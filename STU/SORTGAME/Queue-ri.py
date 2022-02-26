import sys
from collections import deque
input = sys.stdin.readline

def main():
    cache = {} # ('series', distance)

    def normalize(series, N):
        res = [0]*N
        for i in range(N):
            cnt = 0
            for j in range(N):
                if series[j] < series[i]: cnt += 1
            res[i] = cnt
        return ''.join(str(i) for i in res)

    def bfs():
        for N in range(1, 9):
            start = ''.join(str(i) for i in range(N))
            cache[start] = 0
            q = deque()
            q.append(start)
            while q:
                cur = q.popleft()
                distance = cache[cur]
                for i in range(0, N):
                    for j in range(i+2, N+1):
                        sub = cur[i:j]
                        rev = cur[:i] + sub[::-1] + cur[j:]
                        if rev not in cache:
                            cache[rev] = distance + 1
                            q.append(rev)

    bfs()
    for TC in range(int(input())):
        N = int(input())
        series = normalize(list(map(int, input().split())), N)
        print(cache[series])

if __name__ == '__main__':
    main()