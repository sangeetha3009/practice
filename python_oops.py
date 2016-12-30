class Customer(object):
    def __init__(self,name,actnumber):
    	self.name=name
	self.accnt=actnumber

if __name__ == "__main__":
    Sangeetha=Customer("Sangeetha",3)
    print Sangeetha.name
    print Sangeetha.accnt
