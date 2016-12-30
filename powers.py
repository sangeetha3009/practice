
y=0

def e(a,b):
    print "a--->",a," b----->",b
    if (b==0):
        return 1
    if b%2 == 1:
	return a*e(a,b-1)
    else:
	global y
        print "Value at y",y
   	y=e(a,b/2)
       	return y*y

	    

if __name__ == "__main__":
    a=input("Enter number")
    b=input("Enter exp")
    t=e(a,b)
    print "Result ",t
