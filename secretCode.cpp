#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
// Include headers as needed

using namespace std;

int main()
{
    int testcases;
    cin>>testcases;
    for(int i=0;i< testcases;i++){
        std::string str;
        cin>>str;
        cout<<"String "<<str<<endl;
        char array[27]={'*'};
        for(int i=1;i<27;i++){
            array[i]=str[i-1];
        }
        std::string testString;
        cin>>testString;
        cout<<endl;
        for(int i=0;testString[i]!='\0';i++){
            //cout<<"Value of i "<<i<<endl;
            if (testString[i] == '0'){
                int ii=testString[i+1]-'0';
                cout<<array[ii];

            }
            else{
                //cout<<"Value of i and i+2 "<<i<<" "<<i+2<<" "<<testString[i]<<" "<<testString[i+2]<<endl;
                std::string t=testString.substr(i,2);
                //cout<<"value of t "<<t<<endl;
                int ii=std::atoi(t.c_str());
                //cout<<"ii "<<ii<<endl;
                cout<<array[ii];
            }
            i+=1;
        }
    }
    cout<<endl;
    return 0;
}
