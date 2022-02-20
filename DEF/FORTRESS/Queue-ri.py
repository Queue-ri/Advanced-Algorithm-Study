import sys
input = sys.stdin.readline

def main():
    wall, connected, children = [], [], []

    def inner(a, b): # check inner a
        d = (a[0]-b[0])**2 + (a[1]-b[1])**2
        return d < a[2]**2

    def grandchild(adx, bdx):
        for chdx in children[adx]:
            if inner(wall[chdx], wall[bdx]):
                if not grandchild(chdx, bdx):
                    children[chdx].append(bdx)
                    connected[bdx] = True
                return True
        return False

    def max_level(idx):
        if not children[idx]:
            return 0
        level = [max_level(chdx)+1 for chdx in children[idx]]
        level.sort(reverse=True)
        if len(level) > 1:
            nonlocal best
            best = max(best, level[0]+level[1])
        return level[0]

    for TC in range(int(input())):
        N = int(input())
        wall = [tuple(map(int, input().split())) for _ in range(N)]
        wall.sort(key=lambda x:x[2], reverse=True)
        connected = [False]*N
        children = [[] for _ in range(N)]

        for i in range(1, N):
            if not connected[i]: # b is not connected yet
                if not grandchild(0, i):
                    children[0].append(i)
        best = 0 # leaf to leaf
        print(max(max_level(0), best))


if __name__ == '__main__':
    main()
