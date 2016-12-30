#include <iostream>
using namespace std;


int findPairs(int *a,int n,int k){
	int numOfPairs=0;
	for(int i=0;i<n;i++){
		if (a[i] == -1)
			continue;
		int temp=a[i];
		a[i]=-1;
		for(int j=i+1;j<n;j++){
			if(a[j] == -1)
				continue;
			if((temp+a[j]) == k){
				numOfPairs+=1;
				a[j] = -1;
				break;
			}
		}
	}
	return numOfPairs;
}


int main(){
	int testcases,n,k,numberOfPairs;
	cin>>testcases;
	for(int i=0;i<testcases;i++){
		cin>>n;
		cin>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		numberOfPairs=findPairs(a,n,k);
		cout<<"Number of such pairs "<<numberOfPairs<<endl;

	}
	return 0;
}