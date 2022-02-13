import sys
input = sys.stdin.readline

def main():
    for TC in range(int(input())):
        str = input().rstrip()
        rstr = str[::-1]
        L = len(str)
        if str == rstr:
            print(L)
            continue

        LPS = [0]*L
        i = 1; j = 0
        while i < L:
            if str[i] == rstr[j]:
                j += 1
                LPS[i] = j
                i += 1
            elif j:
                j = LPS[j-1]
            else:
                i += 1

        print((L << 1) - LPS[L-1])

if __name__ == '__main__':
    main()
