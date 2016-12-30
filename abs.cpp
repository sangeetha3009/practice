#include<iostream>
using namespace std;

class one{
public:
virtual void show()=0;
void pp(){
cout<<"Hello hello"<<endl;
}
};

class two:public one{
public:
 void show(){
cout<<"Hi";
}

};

int main(){
two t;
t.show();
t.pp();
}
