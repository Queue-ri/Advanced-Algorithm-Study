def quadtree(word):
    global idx   
    head=word[idx]
    idx+=1
    #b나 w에 도달했을때 해당 문자열 반환
    if head=='b' or head=='w':
        return head
    
    a=quadtree(word)
    b=quadtree(word)
    c=quadtree(word) 
    d=quadtree(word)
    
    #반복된 문자열은 3>4>1>2 순서로 결합
    return 'x'+c+d+a+b
    

C=int(input())

for _ in range(C):
    tree=input()
    idx=0
    print(quadtree(tree))
