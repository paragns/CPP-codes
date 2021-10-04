#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool check(ll int mid,vector<ll int>&A,ll int &tar){
	for(ll int i=mid-1;i<A.size();i++){
		ll int val;
		if(i-mid<0)val=0;
		else val=A[i-mid];
		if((A[i]-val)>=tar )return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	ll int n; cin>>n;
	 	vector<ll int >A(n);
	 	for(int i=0;i<n;i++){
		 	cin>>A[i];
		 	if(i!=0)A[i]+=A[i-1];
		 }
	 	ll int tar; cin>>tar;
	 	if(A[A.size()-1]<tar){cout<<-1; return 0;}
		 
		ll int low=1, high=n;
	 	while(low<high){
			ll int mid=low+(high-low)/2;
			if(check(mid,A,tar))high=mid;
			else low=mid+1; 
		}
		cout<<high;
	}
return 0;
}
