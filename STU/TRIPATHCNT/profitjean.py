import functools
import sys

case = int(sys.stdin.readline().rstrip())
for _ in range(case):
    n = int(sys.stdin.readline().rstrip())
    triangle = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(n)]
    memo = dict()
    @functools.lru_cache(maxsize=None)
    def path(y,x):
        if y == n -1:
            return triangle[y][x]
        if (x,y) not in memo:
            memo[(y,x)] = max(path(y+1,x), path(y+1,x+1)) + triangle[y][x]
        return memo[(y,x)]

    memo2 = dict()
    @functools.lru_cache(maxsize=None)
    def count(y,x):
        if y == n -1:
            return 1
        if (y,x) not in memo2:
            result = 0
            if path(y+1,x) >= path(y+1,x+1):
                result += count(y+1,x)
            if path(y+1,x+1) >= path(y+1,x):
                result += count(y+1,x+1)
            memo2[(y,x)] = result
        return memo2[(y,x)]
    path(0,0)
    print(count(0,0))