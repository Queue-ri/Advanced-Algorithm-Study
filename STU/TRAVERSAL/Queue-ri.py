import sys
input = sys.stdin.readline

def postorder(preorder, inorder):
    if not preorder:
        return

    root = preorder[0]
    div = inorder.index(root)

    postorder(preorder[1:div+1], inorder[:div])
    postorder(preorder[div+1:], inorder[div+1:])
    print(root, end=' ')


def main():
    for TC in range(int(input())):
        N = int(input())
        preorder, inorder = [0]*N, [0]*N
        preorder = list(map(int, input().split()))
        inorder = list(map(int, input().split()))
        postorder(preorder, inorder)


if __name__ == '__main__':
    main()
