import heapq

C=int(input())
    
for _ in range(C):
    N,a,b=list(map(int,input().split()))
    ret=1983
    minHeap=[]
    maxHeap=[]
    sum=0
    for _ in range(N):
        if len(minHeap)==len(maxHeap):
            heapq.heappush(maxHeap,-ret)
        else:
            heapq.heappush(minHeap,ret)
        
        if minHeap and maxHeap and minHeap[0] < -maxHeap[0]:
            t1=-heapq.heappop(maxHeap)
            t2=-heapq.heappop(minHeap)
            heapq.heappush(maxHeap,t2)
            heapq.heappush(minHeap,t1)
        sum+=-maxHeap[0]
        ret=(ret*a+b)%20090711
    print(sum%20090711)
