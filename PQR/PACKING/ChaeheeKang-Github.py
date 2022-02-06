C=int(input())
def pack(dp,volume,urgency,N,W):
     for i in range(1,N+1):
        for j in range(1,W+1):
            if j<volume[i-1]:
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-volume[i-1]]+urgency[i-1])

def track(dp,volume,name,N,W,cnt):
    if N==0:
        print(a,str(cnt))
        return
    f=False
    if dp[N][W]!=dp[N-1][W]:
        W-=volume[N-1]
        cnt+=1
        f=True
    track(dp,volume,name,N-1,W,cnt)
    if f:
        print(name[N-1])
for _ in range(C):
    N,W=map(int,input().split())
    name=[]
    volume=[]
    urgency=[]
    ans=[]
    dp=[[0]*(W+1) for _ in range(N+1)]
    for i in range(N):
        n,v,u=input().split()
        name.append(n)
        volume.append(int(v))
        urgency.append(int(u))
        
    pack(dp,volume,urgency,N,W)
    a=dp[N][W]
    track(dp,volume,name,N,W,0)
