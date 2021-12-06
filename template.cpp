#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
struct node{
    int val;
    vector<node*> A;
};
void LevelOrder(node *root) {

queue<node*>q;
q.push(root);
cout<<root->val<<” ”;
while(!q.empty()){

        node* t=q.front();
        q.pop();
        vector<node*>v=t->A;
        for(int i=0;i<v.size();i++){
    		q.push(v[i]);
    		cout<<v[i]->val<<” ”;
		}
}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	
	}
return 0;
}
