import sys
input = sys.stdin.readline

def main():
    pair = '(){}[]'

    def check(str):
        st = []
        for ch in str:
            if ch in '({[':
                st.append(ch)
            elif st:
                if st[-1] == pair[pair.find(ch)-1]:
                    st.pop()
                else:
                    print('NO')
                    return
            else:
                print('NO')
                return
        if not st:
            print('YES')
        else:
            print('NO')

    for TC in range (int(input())):
        check(input().rstrip())

if __name__ == '__main__':
    main()
