#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node* next;
	node(int x){
		val=x;
		next=NULL;
	}
};
int main(){
	node*A=NULL;
	node*B=A;
	for(int i=0;i<11;i++){
		int x; cin>>x;
		if(!B){B=new node(x); A=B;}
		else{
			B->next=new node(x);
			B=B->next;
		}
	}
	int n=11/2+1;
		int a=INT_MAX,prev=-1;
	while(n--){
		node* pres=A;
		while(pres){
			if(pres->val>prev and pres->val<a)a=pres->val;
			pres=pres->next;
		}
		prev=a;
		a=INT_MAX;
	}
	cout<<prev;
	
// 1 2 3 4 5 6 7 8 9 10
return 0;
}
