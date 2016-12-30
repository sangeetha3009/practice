#include<iostream>
using namespace std;
#include<string>


int main(){
	std::string str1;
	std::string str2;
	cout<<"Enter first string "<<endl;
	std::getline(cin,str1);
	cout<<"Lower "<<tolower(str1[0]);
	cout<<endl;
	cout<<"Enter second string "<<endl;
	std::getline(cin,str2);
	cout<<endl;
	int len1,len2;
	len1=str1.length();
	int array[256]={0};
	int i=0;
	bool flag=true;
	while(str1[i]!='\0'){
		array[str1[i]]+=1;
		i+=1;
	}
	i=0;
	while(str2[i]!='\0'){
		if(array[str2[i]] <= 0){
			flag=false;
			cout<<"Not an anagram ";
			break;
		}
		else{
		array[str2[i]]-=1;
		i+=1;
	   }
	}
	if(flag == true)
		cout<<"Strings are anagarams of each other ";
	return 0;
}
