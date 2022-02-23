C=int(input())
def print_postorder(preorder,inorder,N):
   
    if N==0:
        return 0
    
    root=preorder[0]
    
    L=inorder.index(root)
    R= N-1-L
    
    print_postorder(preorder[1:L+1],inorder[:L+1],L)
    print_postorder(preorder[L+1:],inorder[L+1:],R)
    print(root,end=' ')
    

for _ in range(C):
    N=int(input())
    preorder=[0]*N
    inorder=[0]*N

    preorder=list(map(int,input().split()))
    inorder=list(map(int,input().split()))
    
    print_postorder(preorder,inorder,N)
