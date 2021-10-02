#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1e6+1;
vector<int>fenwick(N,0);
map<int , int >mp;
bool comp(vector<int>A, vector<int>B){
	return(A[1]>B[1]);
}
void compress(vector< int> &A){
	for(auto i:A)mp[i]=0;
	ll int t=1;
	for(auto i:mp)mp[i.first]=t++;
	for(int i=0;i<A.size();i++)A[i]=mp[A[i]];
}
void update(int x, int val){
	for(x;x<N;x+=(x&(-x))){
		fenwick[x]+=val;
	}
}
int query(int x){
 	 int sum=0;
	for(x;x>0;x-=(x&(-x))){
		sum+=fenwick[x];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	vector<vector<int>>B(n,vector<int>(2)),A(2,vector<int>(n));
	 	for(int i=0;i<n;i++)cin>>B[i][0];
	 	for(int i=0;i<n;i++)cin>>B[i][1];
	 	sort(B.begin(),B.end());
	 	
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++)A[i][j]=B[j][i]; 
		}
	 compress(A[1]);
		 int q;
	 	cin>>q;

	 	vector<vector<int>>que;
	 	int c=0;
	 	while(q--){
			int l,r;
			cin>>l>>r;
			 int ind=upper_bound(A[0].begin(),A[0].end(),l)-A[0].begin();
			 auto it=mp.upper_bound(r);
			 int val=it->second;
			 if(it==mp.end())val=N;
			 //cout<<c<<" "<<ind<<" "<<" "<<it->first<<" "<<it->second<<endl;
			 que.push_back({c++,ind,val});
			 
		}
		
		sort(que.begin(),que.end(),comp);		
		for(int i=n-1,j=0;i>=0;i--){
			update(A[1][i],1);
			//cout<<que[j][1]<<"**";
			while(j<que.size() and que[j][1]==i ){
				//cout<<i<<"*";
				que[j].push_back((n-i)-query(que[j][2]-1));
				j++;
			}
		}
		sort(que.begin(),que.end());
		for(int i=0;i<que.size();i++)cout<<que[i][3]<<"\n";
	}
return 0;
}
