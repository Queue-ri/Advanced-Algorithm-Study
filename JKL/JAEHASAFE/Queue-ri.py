import sys
input = sys.stdin.readline

def shifts(str, pattern):
    length = len(pattern)
    for i in range(len(str)):
        if str[i:i+length] == pattern:
            return i
    return -99999999999999999

def main():
    for TC in range(int(input())):
        N = int(input())
        state = [None]*(N+1)
        for k in range(N+1):
            state[k] = input().rstrip()

        turn = 0; sum = 0
        while turn < N:
            if turn & 1 == 1: # counter clockwise
                sum += shifts(state[turn] + state[turn], state[turn+1])
            else: # clockwise
                sum += shifts(state[turn+1] + state[turn+1], state[turn])
            turn += 1
        print(sum)

if __name__ == '__main__':
    main()
