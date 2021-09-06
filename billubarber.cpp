#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>shop;
vector<int> A;
int maxprof(int indx,int endt,int earn){
//	cout<<earn<<"*"<<endl;
	if(indx>=shop.size())return earn;
	else if(shop[indx][0]<endt)return maxprof(indx+1,endt,earn);
	else{
		int l=maxprof(indx+1,shop[indx][1],earn+shop[indx][2]);
		int m=maxprof(indx+1,endt,earn);
		
		return A[indx]=max(l,m);
	}
}
  
// Driver code
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int s,e,f;
		cin>>s;
		cin>>e;
		cin>>f;
		shop.push_back({s,e,f});
	}
	
	sort(shop.begin(),shop.end());
	for(int i=0;i<shop.size();i++){
		for(int j=0;j<shop[i].size();j++){
			cout<<shop[i][j]<<"-";
		}
		cout<<endl;
	}
	
	A.resize(n,0);
	int ans=maxprof(0,-1,0);
	//cout<<ans<<"**"<<endl;
	
	for(int i=0;i<A.size();i++)cout<<A[i]<<" ";
	
return 0;
}
