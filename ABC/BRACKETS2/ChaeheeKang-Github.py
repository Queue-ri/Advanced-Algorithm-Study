C=int(input())
opening=['(','{','[']
closing=[')','}',']']

for _ in range(C):
    formula=list(input())
    openStack=[]
    df=True
    for i in range(len(formula)):
        if formula[i] in opening:
            openStack.append(formula[i])
        else:
            if len(openStack)==0:
                df=False
                break
            if opening.index(openStack[-1])==closing.index(formula[i]):
                openStack.pop()
            else:
                df=False
                break
    if df:
        if len(openStack)==0:
            print("YES")
        else:
            print("NO")
    else: print("NO")
