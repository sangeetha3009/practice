#include <iostream>
using namespace std;

int binarySearch(int *a,int key,int low,int high){
	while(low <= high){
		int mid=(high+low)/2;
		if(key == a[mid])
			return mid;
		if (key < a[mid])
			return binarySearch(a,key,low,mid-1);
		else
			return binarySearch(a,key,mid+1,high);
	}
	return -1;
}

int findingMid(int *a,int low,int high){
	if (low > high)
		return -1;
	int mid=(low+high)/2;
	if (mid < high && a[mid] > a[mid+1])
		return mid;
	if(mid > low && a[mid] < a[mid-1]){
		cout<< "Did u come here "<<(mid-1)<<endl;
		return (mid-1);
	}
	if(a[0] > a[mid])
		return findingMid(a,low,mid-1);
	else
		return findingMid(a,mid+1,high);
}

int search(int *a,int key,int low,int high){
	int pivot;
	pivot=findingMid(a,low,high);
	cout<<"Pivot "<<pivot<<endl;
	int out;
	if (pivot == -1){
    	cout<<"Array not rotated";
    	out=binarySearch(a,key,low,high);
	}
	else{
		if (a[0] > key )
			out=binarySearch(a,key,pivot+1,high);
	else
		out=binarySearch(a,key,0,pivot-1);
	
	}
	return out;

}

int main(){
	int a[]={9,10,15,18,0,2};
	int key;
	cout<<"ENter key "<<endl;
	cin>>key;
	int out= search(a,key,0,5);
	cout<<out;
	return 0;
}
