import sys
import heapq

case = int(sys.stdin.readline().rstrip())
for _ in range(case):
    n = int(sys.stdin.readline().rstrip())
    arr = map(int, sys.stdin.readline().rstrip().split())
    str = []
    length = 0
    for i in arr:
        heapq.heappush(str, i)
    for i in range(n-1):
        length1 = heapq.heappop(str)
        length2 = heapq.heappop(str)
        length = length + length1 + length2
        heapq.heappush(str, length1 + length2)
    print(length)
