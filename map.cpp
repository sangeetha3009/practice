#include<iostream>
#include<map>
#include<string>
#include<cstring>

using namespace std;

int main(){
	char* pch;
	std::map<std::string,int> m;
	std::string sentence;
	std::getline(cin,sentence);
	pch=std::strtok(&sentence[0]," ");
	while(pch != NULL){
		cout<<pch<<endl;
		pch=strtok(NULL," ");
	}
	return 0;
}
