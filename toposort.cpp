#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>pred(n+1,0);
	vector<vector<int>>adj(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		pred[b]++;
	}
	set<int>s;
	vector<int>A;
	for(int i=1;i<=n;i++)if(pred[i]==0){s.insert(i);}
	while(!s.empty()){
		int sz=s.size();
		while(sz--){
			int t=*(s.begin());
			s.erase(s.begin());
			A.push_back(t);
			for(int i:adj[t]){
				pred[i]--;
				if(pred[i]==0)s.insert(i);
			}
		}
	}
	if(A.size()!=n)cout<<"Sandro fails.";
	else {
		for(int i:A)cout<<i<<" ";
	}
	return 0;
}
