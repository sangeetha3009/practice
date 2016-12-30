def moveToEnd(b):
    i=j=len(b)-1
    while(i>=0):
        if(b[i]!=-1):
            b[j]=b[i]
            j-=1
        i-=1
    print(b)
    return j+1


s=[5,8,12,14]
b=[2,-1,7,-1,-1,10,-1]
bai=moveToEnd(b)
print(bai)
#mergeArr(s,b,bai)
