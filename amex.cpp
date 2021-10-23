#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<int>>A,st;
int p,q,u,v;
vector<vector<int>>dp;
int func(int r, int num, int cost, int ind,int x,int y){
	//cout<<r<<" "<<num<<" "<<cost<<endl;
	if(r==st.size())return 0;
	if(ind>=st[r].size() or cost>900)return func(r+1,num,0,0,x,y);
	
	int ans=func(r,num,cost,ind+1,x,y);
	if(cost+A[st[r][ind]][0]<=900 and num!=x)ans=max(ans,A[st[r][ind]][1]+func(r,num+1,cost+A[st[r][ind]][0],ind+1,x,y));
	if(cost+A[st[r][ind]][0]<=900 and num==x)ans=max(ans,y*A[st[r][ind]][1]+func(r,num+1,cost+A[st[r][ind]][0],ind+1,x,y));
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	int ct;cin>>ct;
	 	vector<int>temp(n);
	 	for(int i=0;i<n;i++){
			cin>>temp[i];
		}
		for(int i=0;i<ct;i++){
			int x, y;
			cin>>x>>y;
			A.push_back({x,y});
		}
		cin>>p>>q>>u>>v;
		int ind=0;
		for(int i=0;i<n;i++){
			vector<int>t;
			for(int j=0;j<temp[i];j++){
				t.push_back(ind++);
			}
			st.push_back(t);
		}
		
		int ans1=func(0,1,0,0,p,q);
		int ans2=func(0,1,0,0,u,v);
		if(ans1>ans2)cout<<"Alice"<<" "<<ans1-ans2;
		else{
			cout<<"Bob"<<" "<<ans2-ans1;
		}

	}
return 0;
}
