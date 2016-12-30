def solution(A): 
    n = len(A)
    print "n ",n
    L = [-1] + A
    print "before sort ",L
    L.sort()
    print "Afters ort ",L
    count = 0
    pos = (n + 1) // 2
    print "pos ",pos
    candidate = L[pos]
    for i in xrange(1, n + 1):
        if (L[i] == candidate):
            count = count + 1
        else:
	    break

    if (2*count > n):
        return candidate
    return -1


A=[2,2,2,2,4,5]
t=solution(A)
print "Candiadte ",t
