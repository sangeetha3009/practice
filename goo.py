import string

def solution(X):
    # write your code in Python 2.7
    list_number=list(str(X))
    x=0
    new_list=[]
    for i in range(len(list_number)-1):
        number=str(X)
        sum=int(list_number[i])+int(list_number[i+1])
	print "sum ",sum
        avg_val=round(sum/2,0)
        print avg_val
        replace_number=number[i]+number[i+1]
        new_str = string.replace(number, replace_number, str(avg_val))
        new_list.append(new_str)
        
        
    print max(new_list)
    return max(new_list)


solution(623315)
