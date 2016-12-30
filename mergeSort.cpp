#include <iostream>
using namespace std;

void merge(int *a,int *b,int start,int high,int mid){
	int i=start;
	int j=mid+1;
	int pivot=mid;
	int k=start;
	while (i <= pivot && j<=high){
		if (a[i] < a[j]){
			b[k]=a[i];
			i+=1;
			k+=1;
		}
        else if (a[i] == a[j]){
            b[k]=a[i];
            i+=1;
            k+=1;
            j+=1;
        }
		else{
			b[k]=a[j];
			j+=1;
			k+=1;
		}
	}
    if (j > high){
	   while(i<=pivot){
		  b[k]=a[i];
		  i+=1;
		  k+=1;
	   }
    }
    else{
	   while(j<=high){
		  b[k]=a[j];
		  j+=1;
		  k+=1;
	   }
    }
	for(int l=start;l<=high;l++){
		a[l]=b[l];
	}
	cout<<"output "<<endl;
	for(int l=start;l<=high;l++){
		cout<<a[l]<<" ";

    }
	

}

void mergeSort(int *a,int *b,int start,int end){
	if (start < end){
		int mid=(start+end)/2;
		cout<<"mid "<<mid;
		mergeSort(a,b,start,mid);
		cout<<"Mid before 2nd call "<<mid<<endl;
		mergeSort(a,b,mid+1,end);
		merge(a,b,start,end,mid);
	}


}

int main(){
	int n;
	cout<<"Enter the number of elements in array "<<endl;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	mergeSort(a,b,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}