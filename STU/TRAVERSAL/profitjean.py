import sys
input = sys.stdin.readline

def make_postorder(preorder, inorder):
    if not preorder:
        return
    root = preorder[0]
    middle = inorder.index(root)

    make_postorder(preorder[1:middle+1], inorder[0:middle])
    make_postorder(preorder[middle+1:], inorder[middle+1:])
    print(root, end=" ")

case = int(input())
for _ in range(case):
    n = int(input())
    preorder = list(map(int, input().split()))
    inorder = list(map(int, input().split()))
    make_postorder(preorder, inorder)
    print()