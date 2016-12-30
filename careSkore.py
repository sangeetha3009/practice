if __name__=="__main__":
    try:
	ft=open("sample.txt","r")
	ft.next()
	with open("sample.txt","r") as fp:
	    for line in fp:
                if "st" in line:
  	            print line
		    t=ft.next()
		    if "st" not in t:
		        print t
    except Exception as e:
	pass
