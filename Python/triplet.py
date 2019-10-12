from itertools import groupby
T=int(input(""))
while T>0:
    g=input()
    g1=list(g)
    c1=0
    c2=0
    for i in g:
        if i=='R':
            c1+=1
        else:
            c2+=1
    if(c1==c2 and len(g)<5):
        print("yes")
        T-=1
        continue
    l=[[k, len(list(g2))] for k, g2 in groupby(g)]
    c=0
    co=0
    for i in l:
        if i[0]=='R' and i[1]>1:
            if(i[1]==2):
                co+=1
            else:
                c=1
        elif i[0]=='G' and i[1]>1:
            if(i[1]==2):
                co+=1
            else:
                c=1
    if c==0 and co<3 and c1==c2:
        print("yes")
    else:
        print("no")

    T-=1
