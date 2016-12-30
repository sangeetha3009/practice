//C++ program to find lowest common ancestors for 2 nodes in a binary tree

#include<iostream>
#include<limits.h>
using namespace std;

struct bst{
	int data;
	bst *left;
	bst *right;
} *root,*subroot;

class lca{
	
	private:
		bst* create(int element){
			bst* temp=new(struct bst);
			temp->data=element;
			temp->left=NULL;
			temp->right=NULL;
			return temp;
		}
	
	public:
		lca(){
			root=NULL;
			subroot=NULL;
		}
		
		bst* insert(bst* root,int element){
			if (root == NULL){
				root=create(element);
			}
			else{
				bst* ptr=root;
				if (element < root->data)
					root->left=insert(root->left,element);
				else
					root->right=insert(root->right,element);
			}
			return root;

		}
		
		void print(bst* root){
			if (root == NULL)
				return;
				cout<<root ->data <<" ";
				print (root ->left);
				print(root -> right);

			

		}

		int commonAncestor(bst* root,int element1,int element2){
			if (root == NULL)
				return 0;
			if(element1 < root->data && element2 > root->data)
				return root->data;
			if(element1> root->data && element2 < root ->data)
				return root -> data;
			if (element1 < root->data && element2 < root -> data){
				bst* ptr=root;
			if (root->left == NULL)
					return -1;
				if (root->left->data != element1 && root->left->data != element2)
					return commonAncestor(root->left,element1,element2);
				else
					return ptr->data;
			}
			if (element1 > root->data && element2 > root -> data){
				bst* ptr=root;
				if (root->right == NULL)
					return -1;
				if (root->right->data != element1 && root->right->data != element2)
					return commonAncestor(root->right,element1,element2);
				else
					return ptr->data;
			}
			return -1;
		}

		bool issubtree(bst *root,bst *subroot){
			if (root == NULL && subroot == NULL)
				return true;
			if (subroot == NULL)
				return true;
			if(root == NULL)
				return false;
			if(root ->data == subroot -> data){
				 return (issubtree(root->left,subroot->left) && issubtree(root->right,subroot->right));
			}
			else
				return (issubtree(root->left,subroot) || issubtree(root->right,subroot));
		}

		bool isbstutil(bst *root,int min,int max){
			if (root == NULL)
				return true;
			if (root->data < min || root ->data > max)
				return false;
			return (isbstutil(root->left,min,root->data) && isbstutil(root->right,root->data,max));
		}

		bool is_bst(bst *root){
			return (isbstutil(root,INT_MIN,INT_MAX));
		}

		bool isidentical(bst *root,bst *subroot){
			if (root == NULL && subroot == NULL)
				return true;
			else if (root == NULL || subroot == NULL)
				return false;
			else{
				if (root ->data == subroot ->data){
					return (isidentical(root->left,subroot->left) && isidentical(root->right,subroot->right));
				}
				else
					return false;
			}
		}

		bst* deleteLeaves(bst* root){
			bst* ptr;
			if(root != NULL){
				if(root->left == NULL && root->right == NULL){
					delete root;
					return NULL;
				}
				else
				{
					root->left=deleteLeaves(root->left);
					root->right=deleteLeaves(root->right);
				}

		}
		return root;
	}

	int search_inorder(int *inorder,int start,int end,int key){

		for(int i=start;i<=end;i++){
			if (inorder[i] ==  key)
				return i;
		}
		return -1;
	}

	bst* construct(int *inorder,int *preorder,int start,int end){
		bst* bst_in_pre;
		static int preorder_index=0;
		if (start > end)
			return NULL;
		bst_in_pre=create(preorder[preorder_index++]);
		if (start == end)
			return bst_in_pre;

		int index_inorder=search_inorder(inorder,start,end,bst_in_pre->data);
		bst_in_pre->left=construct(inorder,preorder,start,index_inorder-1);
		bst_in_pre->right=construct(inorder,preorder,index_inorder+1,end);

		return bst_in_pre;
	}


};

int main(){
	int element;
	int cont=1;
	int ch;
	lca l;
	lca subtree;
	while(cont != 0){
		cout<<"1. Insert "<<endl;
		cout<<"2. Print "<<endl;
		cout<<"3. common ancestor "<<endl;
		cout<<"4. Create a subtree "<<endl;
		cout<<"5. Printing sub-tree"<<endl;
		cout<<"6. Check if subtree is present in main tree"<<endl;
		cout<<"7. is binary tree "<<endl;
		cout<<"8. is identical "<<endl;
		cout<<"9. Delete all leaves of the tree "<<endl;
		cout<<"10. construct tree from inorder and preorder "<<endl;
		cin>>ch;
		switch(ch){
			case 1: 
				cout<<"Enter element to insert "<<endl;
				cin>>element;
				root=l.insert(root,element);
				break;
			case 2:
				l.print(root);
				break;
			case 3:
				int element1,element2,result;
				cout<<"Enter element 1 "<<endl;
				cin>>element1;
				cout<<"Enter element 2 "<<endl;
				cin>>element2;
				result=l.commonAncestor(root,element1,element2);
				cout<<"Common ancestor "<<result<<endl;
				break;
			case 4: 
				cout<<"Enter element to insert in subtree "<<endl;
				cin>>element;
				subroot=l.insert(subroot,element);
				break;
			case 5:
				cout<<"Printing subtree "<<endl;
				l.print(subroot);
				break;
			case 6:
				bool value;
				value=l.issubtree(root,subroot);
				cout<<"Is subtree? "<<value<<" "<<endl;
				break;
			case 7:
				bool val;
				val=l.is_bst(root);
				cout<<"Is binary tree ? "<<val<<" "<<endl;
				break;
			case 8:
				bool identical;
				identical=l.isidentical(root,subroot);
				cout<<"Is it identical? "<<identical<<endl;
				break;
			case 9:
				root=l.deleteLeaves(root);
				break;
			case 10:
				bst* bst_in_pre;
				cout<<"Enter number of elements in array "<<endl;
				int array_no;
				cin>>array_no;
				int inorder[array_no],preorder[array_no];
				for(int i=0;i<array_no;i++){
					cin>>inorder[i];
				}
				for(int i=0;i<array_no;i++){
					cin>>preorder[i];
				}
				bst_in_pre=l.construct(inorder,preorder,0,array_no-1);
				l.print(bst_in_pre);
				break;
				
		}
		cout<<"Do you want to continue? press 0 to exit "<<endl;
		cin>>cont;
	}
	return 0;
}