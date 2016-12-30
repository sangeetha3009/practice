#include<iostream>
#include<stack>
using namespace std;

bool matching(char top,char str){
    int t=top;
    int s=str;
    cout<<"t and s "<<t<<" "<<s<<endl;
    if (t == (s+32))
        return true;
    else
        return false;
}
int findMatchingPair(string input) {
    stack <char> s;
    int t=0;
    int cnt=0;
    for(int i=0;input[i]!='\0';i++){
        t=input[i];
	cout<<"t "<<t<<endl;
        if (t >= 65 && t <= 90)
            s.push(input[i]);
        else if(t >= 97 && t <= 122){
	    cout<<"Yes i came in "<<t<<endl;
            if (matching(s.top(),input[i])){
                cout<<"Matching "<<input[i];
                cnt+=1;
            }
        }
    }
    return cnt;
}


int main(){
std::string s;
s="Abba";
int t=s[0];
int res=findMatchingPair(s);
cout<<"Output "<<res;
return 0;
}
