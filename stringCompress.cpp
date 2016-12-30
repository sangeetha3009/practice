#include<iostream>
using namespace std;

int main(){
	cout<<"Enter string";
	std::string a;
	cin>>a;
	std::string temp_string;
	int a_len=0;
	int temp_len=0;
	int i=0;
	while(a[i]!='\0'){
		a_len+=1;
		i=i+1;
	}
	int cnt_occurence=1;
	int j=0,temp=0,k=0;
	bool flag=false;
	for(int i=0;i<a_len;i++){
		char t=a[i];
		temp=i;
		if (flag==false)
			j=i+1;
		else
			j=j+1;
		if (a[i] == a[j]){
			cnt_occurence+=1;
			i=temp-1;
			flag=true;
			cout<<"cnt_occurence "<<cnt_occurence<<"i "<<i<<endl;
			continue;
		}
		else{
				temp_string[k]=a[i];
				k=k+1;

			if (cnt_occurence < 10){
				temp_string[k]='0'+cnt_occurence;
				cout<<"temp "<<temp_string[k]<<" "<<temp_string[k+1]<<endl;
				k+=1;
				j=0;

			}
			else{
				char char_num[32];
				char rev_num[32];
				int char_i=0;
				int temp_cnt=cnt_occurence;
				while (temp_cnt > 0){
					char_num[i]='0'+(temp_cnt%10);
					temp_cnt/=10;
					i+=1;
				}
				char_num[i]='\0';
				i-=1;
				int l=0;
				while(i >= 0){
					rev_num[l]=char_num[i];
					l+=1;
					i-=1;
				}
				rev_num[l]='\0';
				l=0;
				while(rev_num[l]!='\0'){
					temp_string[k]=rev_num[l];
					l+=1;
					k+=1;
				}
				flag=false;
				i=i+cnt_occurence-1;
				cout<<"value of i "<<i;
				cnt_occurence=1;//Reset


			}
		}
		
	}
	temp_string[k]='\0';

	cout<<"Final string "<<endl;
	for(int i=0;temp_string[i]!='\0';i++)
		cout<<temp_string[i];
	cout<<endl;
	return 0;
	}
	
