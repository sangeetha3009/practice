#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class ll{
private:
	node* createnode(int element){
		node* temp=new(struct node);
		temp->data=element;
		temp->next=NULL;
		return temp;
	}
public:

	node* insert(node* n,int element){
		if (n == NULL){
			n=createnode(element);
		}
		else{
			node* ptr=n;
			while (ptr->next != NULL){
				ptr=ptr->next;
			}
			ptr->next=createnode(element);
		}
		return n;
	}

	void print(node* n){
		int count=0;
		if (n == NULL)
			cout<<"Empty " ;
		else{
			while(n!=NULL){
				cout<<n->data<<" ";
				n=n->next;
				count=count+1;
			}
		}
	}

	node* delet(node* head,int x){
		/*node* temp=head;
		cout<<"temp data "<<temp->data<<endl;
		cout<<"next to temp "<<temp->next->data<<endl;
		head=temp->next;
		return head;*/
		if (head == NULL)
			return head;
		else{
			node* temp=head;
			while(temp  !=NULL){
			if (temp->data > x && temp ->data == head ->data){
				node* ptr=temp->next;
				cout<<"ptrs data "<<ptr->data<<endl;
				temp=ptr;
				cout<<"ptrs data "<<temp->data<<endl;
				head=temp;
			}
			else if (temp->data > x){
					cout<<"Deleting temp "<<temp->data<<endl;

						temp->data=temp->next->data;
						temp->next=temp->next->next;
						cout<<"New temp "<<temp->data<<endl;
			}
			else{
				cout<<"Did u come here ?"<<endl;
				temp=temp->next;
				cout<<"temp -> data"<<temp->data<<endl;
			}
			}
			if(temp -> data > x){
				cout<<"U did't come here with "<<temp->data<<endl;
				temp=NULL;
				delete temp;
			}
			return head;
		}
	}

	node* del(node* head,int key){
		node* temp=head;
		if (head == NULL)
			return head;
		else{

			if(head -> data == key){
				node* temp=head;
				head=head->next;
				delete temp;
			}
			else{
				while(temp->next->data == key)
					temp=temp->next;

				node* temp2=temp->next;
				temp->next=temp->next;
				delete temp;
			}
			
			return head;
		}
	}


};

int main(){
	ll l;
	int cont=1,ch,element;
	int key=0;
	int k=0;
	node* head;
	while(cont != 0){
		cout<<"1. Insert "<<endl;
		cout<<"2. Print "<<endl;
		cout<<"3. Deelete "<<endl;
		cout<<"4.delete an element "<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter element to insert "<<endl;
				cin>>element;
				head=l.insert(head,element);
				break;
			case 2:
				l.print(head);
				//cout<<"Length "<<len<<endl;
				break;
			case 3:
				
				cout<<"Enter key to compare "<<endl;
				cin>>key;
				head=l.delet(head,key);
				cout<<"Element at head "<<head->data<<endl;
				l.print(head);
				break;
			case 4:

				cout<<"Enter key to compare "<<endl;
				cin>>k;
				head=l.del(head,k);
				l.print(head);
				break;

		}
		cout<<"Do you want to continue? press 0 to exit "<<endl;
		cin>>cont;
	}
	return 0;
}