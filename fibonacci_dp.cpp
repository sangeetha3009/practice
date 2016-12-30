#include<iostream>
using namespace std;

int F[100]={-1};

int fib(int n){

	if (n <= 1)
		return n;
	else{
		if (F[n] != -1)
			return F[n];
		else{
			F[n]=fib(n-1)+fib(n-2);
			return F[n];
		}
	}

}

int main(){
	/*for(int i=0;i<100;i++){
		F[i]=-1;
	}*/
	int n;
	char t[10]={'0'};
	cout<<"Enter number "<<endl;
	cin>>n;
	int result=fib(n);
	cout<<"Result "<<result;
	return 0;
}
