#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node*left;
	node*right;
	node(int x){
		val=x;
		left=right=NULL;
	}
};
int main(){
	int n; cin>>n;
	string A;
	cin>>A;
	node *curr=new node(1);
	node* prev=curr;
	for(int i=1;i<n;i++){
		if(A[i-1]=='L'){
			node* temp=prev->left;
			prev->left=new node(i+1);
			prev->left->right=prev;
			prev=prev->left;
			prev->left=temp;
			if(temp)temp->right=prev;
			
		}
		else{
			node* temp=prev->right;
			prev->right=new node(i+1);
			prev->right->left=prev;
			prev=prev->right;
			prev->right=temp;
			if(temp)temp->left=prev;
		}
	}
	while(curr->left!=NULL){
		curr=curr->left;
	}
	while(curr!=NULL){
		cout<<curr->val<<" ";
		curr=curr->right;
	}
	return 0;
	
}
