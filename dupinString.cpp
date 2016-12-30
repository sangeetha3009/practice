#include<iostream>
#include<string>
using namespace std;

int main(){
	std::string str;
	cout<<"Enter string "<<endl;
	cin>>str;
	bool flag=false;
	int a[256]={0};
	for(int i=0;str[i]!='\0';i++){
		cout<<"a "<<a[str[i]]<<endl;
		cout<<"left shift "<<(1<<str[i])<<endl;
		if(a[str[i]] && (1<<str[i])){
			cout<<"Duplicate character present";
			flag=true;
			break;
		}
		else{
			a[str[i]]=1;
		}
	}
	if (flag == false)
		cout<<"No duplicates in string ";
	return 0;
}
