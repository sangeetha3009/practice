#include <iostream>
using namespace std;

int equilibrium(int *a,int n){

	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+a[i];
	}
	int prevsum=0;
	for(int i=0;i<n;i++){
		int temp=sum;
		prevsum+=a[i];
		sum=sum-a[i];
		cout<<"temp "<<temp<<" prevsum "<<prevsum<<" sum "<<sum<<endl;
		if(prevsum > sum  && prevsum == temp)
			return i;

	}
	return -1;
}

int main(){
	
	int n,index;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
			cin>>a[i];
	}
	index=equilibrium(a,n);
	cout<<"Index "<<index<<" element "<<a[index];
	return 0;
}