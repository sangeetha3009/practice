if __name__ == "__main__":
	b=raw_input("Enter the string")
	listWords=b.split(' ')
	dict_words={}
	cnt=0
        for x in listWords:
	    print x
	    if x in dict_words:
	    	cnt=dict_words.get(x)
		print "key ",x," value ",cnt
		dict_words[x]=(cnt+1)
	    else:
		cnt=1
		dict_words[x]=cnt
	print "Dictionar ",dict_words
	print "Max key ",max(dict_words,key=dict_words.get)		

