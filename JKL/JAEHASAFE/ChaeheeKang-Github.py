def shift(txt,pat):
    for i in range(len(txt)):
        if txt[i:i+len(pat)]==pat:
            return i
    return False
        
C=int(input())
for _ in range(C):
    N=int(input())
    status=['']*(N+1)
    for i in range(N+1):
        status[i]=input()
        
    #돌리는 횟수
    turn=0
    #시계의 방향
    clock=False
    
    sum=0
    
    while turn<N:
        if clock:
            sum+=shift(status[turn]*2,status[turn+1])
            clock=False
        else:
            sum+=shift(status[turn+1]*2,status[turn])
            clock=True
        turn+=1
    print(sum)
