import sys
import heapq
input = sys.stdin.readline

def main():
    a = b = 0
    def gen(A):
        num = (A[-1] * a + b) % 20090711
        A.append(num)
        return num

    for TC in range (int(input())):
        A = [1983]
        N, a, b = map(int, input().rstrip().split())
        minheap = []
        maxheap = [-1983]
        sum = 1983
        for i in range(1, N):
            d = gen(A)
            if len(minheap) < len(maxheap):
                heapq.heappush(minheap, d)
            else:
                heapq.heappush(maxheap, -d)
            if minheap[0] < -maxheap[0]:
                x = heapq.heappop(minheap)
                y = heapq.heappop(maxheap)
                heapq.heappush(minheap, -y)
                heapq.heappush(maxheap, -x)

            sum = (sum + -maxheap[0]) % 20090711

        print(sum)

if __name__ == '__main__':
    main()
