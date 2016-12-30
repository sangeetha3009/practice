#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::string str;
    std::getline(cin,str);
    int length=str.length();
    int alpha_bits=67108863;
    int char_bits=67108863;
    for(int i=0;i<length;i++){
        str[i]=std::tolower(str[i]);
    }
    for(int i=0;i<length;i++){
	if(str[i]<97 && str[i]>122)
	    continue;
	else{        
            char_bits &=~(1 << (str[i]-97));
	    cout<< "For letter "<<str[i]<<" Numeric value "<<(str[i]-97)<<endl;
	    cout<<"char_bits "<<char_bits;
	}
		
    }
    cout<<char_bits<<endl;
    if (char_bits == 0)
	cout<<"Panagram ";
    else
        cout <<"Not a panagram ";
    return 0;
}

