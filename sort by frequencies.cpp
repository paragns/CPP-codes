#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool comp(vector<int>A, vector<int>B){
	if(A[1]>B[1])return 1;
	else if(B[1]>A[1])return 0;
	else return A[2]<B[2];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
		 unordered_map<int,vector<int>>mp;
		 
	 	for(int i=0;i<n;i++){
			int x; cin>>x;
		 	if(mp[x].size()==0)mp[x]={1,i};
		 	else {
			 	mp[x][0]++;
			 }
		}
		vector<vector<int>>A;
		for(auto i:mp){
			for(int j=0;j<i.second[0];j++) A.push_back({i.first,i.second[0],i.second[1]});
		 //cout<<i.first<<" "<<i.second[0]<<" "<<i.second[1]<<endl;
		}
	 	sort(A.begin(),A.end(),comp);
	 	for(int i=0;i<A.size();i++)cout<<A[i][0]<<" ";
	 }
	
	
return 0;
}
