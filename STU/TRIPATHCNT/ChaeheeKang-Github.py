def path():
    for y in range(N - 2, -1, -1):
        for x in range(y+1):
            dp[y][x] = max(dp[y + 1][x], dp[y + 1][x + 1]) + tri[y][x]

            if dp[y + 1][x] == dp[y + 1][x + 1]:
                cnt[y][x] = cnt[y + 1][x] + cnt[y + 1][x + 1]
            elif dp[y + 1][x] > dp[y + 1][x + 1]:
                cnt[y][x] = cnt[y + 1][x]
            else:
                cnt[y][x] = cnt[y + 1][x + 1]
    #print(dp)
    print(cnt[0][0])

C = int(input())
for _ in range(C):
    N = int(input())
    tri = [list(map(int, input().split())) for _ in range(N)]
    dp = [[0]*N for _ in range(N)]
    cnt = [[0]*N for _ in range(N)]
    #초기화
    dp[N-1]=tri[N-1]
    cnt[N-1]=[1]*N
    path()
