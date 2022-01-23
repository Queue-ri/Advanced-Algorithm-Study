from queue import PriorityQueue

TC = int(input())
for _ in range(TC):
    pq = PriorityQueue()
    len = int(input())
    list = input().split()
    for i in range(len):
        pq.put(int(list[i]))

    price = 0
    while(pq.qsize() > 1):
        a = pq.get()
        b = pq.get()
        price += (a + b)
        pq.put(a + b)

    print(price)
    
