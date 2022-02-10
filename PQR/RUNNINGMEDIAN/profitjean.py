import sys
import heapq

case = int(sys.stdin.readline().rstrip())
for _ in range(case):
    n, a, b = map(int, sys.stdin.readline().rstrip().split())
    minHeap = []
    maxHeap = []
    value = 1983
    sum = 0

    for i in range(n):
        if len(minHeap) == len(maxHeap):
            heapq.heappush(maxHeap, -value)
        else:
            heapq.heappush(minHeap, value)
        if i == 0:
            sum += -maxHeap[0]
            value = (value * a + b) % 20090711
            continue
        # 최대힙 -maxHeap[0] <= minHeap[0]
        # else 최대 힙의 최대원소와 최소힙의 최소원소 swap
        if -maxHeap[0] > minHeap[0]:
            heapq.heappush(maxHeap, -heapq.heappop(minHeap))
            heapq.heappush(minHeap, -heapq.heappop(maxHeap))
        # 중간값은 항상 최대 힙의 root
        # 최대힙은 음수처리 해줬으므로 - 붙여서 표
        sum += -maxHeap[0]
        value = (value * a + b) % 20090711

    print(sum % 20090711)


