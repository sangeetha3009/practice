#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int chk(string a){
    int len=a.length();
    int mid=(len/2);
    bool flag=true;
    if (a[0] == a[mid])
        return 0;
    l_mid=mid-1
    r_mid=mid;
    int i_mid=0;
    while(i_mid <= l_mid){
     if(a[i_mid] != a[l_mid])
         {
          flag=false;
          break;
	 }
     if(i_mid == l_mid){
	{
         if(a[i_mid] != a[i_mid-1]){
	    flag=false;
	    break;
	 }
	}
    }
    if(flag == true){
        for(int i=mid;i<len-1;i++){
            if(a[i]!=a[i+1]){
                flag=false;
                break;
            }
        }
    }
    if (flag == true)
        return 1;
    else
        return 0;
    
}
int count(string s) {
    int len=0,cnt=0,result=0;
    len=s.length();
    std::string test_str;
    if (len <= 1)
        return result;
    for(int i=0;i<len;i++){
        int pos=2;
        while((i+pos) <= len){
            std::string str;
	    //cout<<"Print strings "<<endl;
            str=s.substr(i,pos);
	    //cout<<str<<endl;
            if(chk(str))
                result=result+1;
	    cout<<"String is "<<str<<" result was "<<result<<" i was "<<i<<" pos was "<<pos<<endl;
            pos+=2;
        }
        
    }
    cout<<"Result "<<result;
    return result;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _s;
    getline(cin, _s);
    
    res = count(_s);
    fout << res << endl;
    
    fout.close();
    return 0;
}
