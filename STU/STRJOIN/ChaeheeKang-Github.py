def strjoin(l):
    cnt=0
    while (len(l)>2):
        s=0
        l.sort(reverse=True)
        s=l[-1]+l[-2]
        cnt+=s
        l.pop()
        l.pop()
        l.append(s)
    cnt+=l[0]+l[1]
    print(cnt)
    
c=int(input())
for _ in range(c):
    n=int(input())
    l=list(map(int,input().split()))
      
    strjoin(l)
