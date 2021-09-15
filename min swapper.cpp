#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int ans=0;
unordered_map<int , int>mp,sp;
void func(int i, int j, string &A){
	if(i>=j)return;
	if(ans==-1)return;
	if(mp[i]==1) return func(i+1,j,A);
	else if(mp[j]==1)return func(i,j-1,A);
	if(A[i]==A[j])return func(i+1,j-1,A);
	else{
		int k=j;
		while(k>i and A[k]!=A[i]){
			k--;
		}
		int a=j-k;
		k=j;
		while(k<j and A[k]!=A[j]){
			k++;
		}
		int b=k-i;
		if(){
			mp[k]=1;
			ans+=(j-k);
			return func(i+1,j,A);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	
	 	ans=0;
	 	string A;
	 	getline(cin,A);
	 	for(int i=0;i<A.size();i++)sp[A[i]]++;
	 	int flag=0;
		 for(auto i:sp){
		 	if(i.second%2!=0)flag++;
		 }
		 if(flag>1)ans= -1;
	 	func(0,A.size()-1,A);
	 	cout<< ans;
	}
return 0;
}
