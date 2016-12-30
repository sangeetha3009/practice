#include<iostream>

using namespace std;

void perm(std::string str,int start,int end){
	char t;
	if(start ==  end){
		cout<<str<<endl;
	}
	else{
		for(int i=start;i<=end;i++){
			t=str[start];
			str[start]=str[i];
			str[i]=t;
			perm(str,start+1,end);
			t=str[start];
			str[start]=str[i];
			str[i]=t;

		}
	}
}

int main(){
    std::string str;
    cout<<"Enter string "<<endl;
    cin>>str;
    int length=str.length();
    cout<<"The permutations are "<<endl;
    perm(str,0,length-1);
    return 0;
}