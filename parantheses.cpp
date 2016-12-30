#include <iostream>
#include<stack>
using namespace std;

int matching(char open,char close){
	if (open == '(' && close ==')')
		return 1;
	else if(open == '{' && close == '}')
		return 1;
	else if(open == '[' && close == ']')
		return 1;
	else
		return 0;
}

int main(){
	cout<<"Enter expression "<<endl;
	std::string exp;
	stack <char> s;
	cin>>exp;
	for(int i=0;exp[i]!='\0';i++){
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
				int t=matching(s.pop(),exp[i]);
				if (s.empty() || t == 0){
					cout<<"not matching "<<endl;
					break;
				}
				else
					s.pop();
		}
	}
	if (s.empty())
		cout<<"Matching "<<endl;
	else
		cout<<"not matching "<<endl;
	return 0;
}