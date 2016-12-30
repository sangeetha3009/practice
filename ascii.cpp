#include<iostream>
using namespace std;

int main(){
int i=9;
char a='1';
cout<<typeid(i+'0').name()<<(i+'0');
return 0;
}
