#include<iostream>
#include<string>
using namespace std;

int main(){
cout<<"Enter String "<<endl;
std::string str;
std::getline(cin,str);
int length=str.length();
for(int i=0;i<length;i++){
str[i]=std::tolower(str[i]);
}
cout<<"lowercase "<<str<<endl;
int i=67108864;
cout<<i;
return 0;
}
