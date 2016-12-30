#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct doublell{
    int data;
    doublell *next;
    doublell *prev;
}*head;

class double_ll{
    private:
    
        doublell* createnode(int element){
          doublell* temp=new(struct doublell);
          temp->data =element;
          temp->next=NULL;
          temp->prev=NULL;
          return temp;
        }
    
    public:

        int mprevious(doublell* head,int element){
            int cnt=1;
            doublell* ptr=head;
            if (head == NULL)
                return 0;
            else if(head -> next == NULL && element > 1)
                return 0;

            else {
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                    cnt+=1;
                }

                if (element > cnt){

                    return 0;
                }
                if (element == 1)
                {
                    return ptr->data;
                }
                element -=1;
                while(element > 0 && ptr->prev != NULL){
                    ptr=ptr->prev;
                    element -=1;
                }
                cout << ptr->data << endl;
                return ptr->data;


            }

            
        }
    
        doublell* insert(doublell* head,int element){
            if (head == NULL){
                head=createnode(element);

            }
            else{
                doublell* ptr=head;
                doublell* temp;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                temp=createnode(element);
                temp->prev=ptr;
                ptr->next=temp;
                
                
            }
            return head;
            
            
        }
    
        void print(doublell* head){
            if (head == NULL)
            {
                cout<<"NIL"<<endl;
                return;
            }
            while(head != NULL){
                cout<<head->data<<" ";
                head=head->next;
            }
            cout<<endl;
        }
    
        double_ll(){
             head=NULL; 
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double_ll d;
    int flag=1,choice=0;
    int mthprevious;
    cin>>mthprevious;
    string response;
    std::getline(std::cin, response);
    cout<<" Response "<<endl;
    cout<<response<<endl;
    for(int i=0;response[i]!='\0';i++){
        if (response[i] == ' ')
            continue;
        int e=response[i]-'0';
        head=d.insert(head,e);
    }
    mthprevious=d.mprevious(head,mthprevious);
    if (mthprevious == 0)
        cout<< "NIL";
    else
        cout<<mthprevious<<endl;
}
