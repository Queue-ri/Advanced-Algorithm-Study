import sys
input=sys.stdin.readline

C=int(input())
def LPS(s,revs):
    leng=len(s)
    pat=[0]*leng
    i=1
    j=0
    while i < leng:
        if s[i]==revs[j]:
            j+=1
            pat[i]=j
            i+=1
        else:
            if j!=0:
                j=pat[j-1]
            else:
                pat[i]=0
                i+=1
    print((leng*2)-pat[leng-1])
                
for _ in range(C):
    S=input().rstrip()
    S_reverse=S[::-1]
    
    if S==S_reverse:
        print(len(S))
    else:
        LPS(S,S_reverse)
