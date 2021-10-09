#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
//vector<int>times;
int func(int node, vector<vector<int>> &adj){
	int n=adj[node].size();
	if(n==0)return 0;
	int ans=n;
	vector<int>temp;
	for(int i:adj[node]){
		temp.push_back(func(i,adj));
	}
	sort(temp.rbegin(),temp.rend());
//	cout<<node<<"->";
//	for(int i:temp)cout<<i<<" ";
//	cout<<endl;
	int cnt=1;
	for(int i=0;i<temp.size();i++){
		ans=max(ans,cnt+temp[i]);
		cnt++;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	vector<vector<int>>adj(26);
	 	//time.resize(26,0);
		 while(1){
			string A;
			getline(cin,A);
			if(A.size()==0)break;
			int x=A[0]-'A';
			int y=A[2]-'A';
			 adj[x].push_back(y);
		}
		cout<<func(0,adj);
	}
return 0;
}
/*
A,B
A,C
A,D
A,E
A,F
A,G
B,H
B,I
B,J
H,N
H,O
E,K
E,L
K,P
L,Q
G,M

*/
