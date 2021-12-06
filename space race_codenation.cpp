#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007
#define ll long long
int main(){
	int A; cin>>A;
	vector<int>Xj(A),Xe(A+1);
	Xj[0]=1;
	Xj[1]=1;
	for(ll int i=2;i<A;i++){
		Xj[i]=(Xj[i-1]+Xj[i-2])%mod;
	}
	Xe[0]=1;
	unordered_map<ll int , vector<ll int>>mp1, mp2;
	for(int i=0;i<A;i++){
		for(ll int bit=0;bit<32;bit++){
			if((ll int)pow(2,bit)&Xj[i]){
				ll int ind1=min(A,i+( int)pow(2,bit));
				ll int ind2=min(A,i+( int )pow(2,bit+1)+1);
				
				mp1[i].push_back(ind1);
				mp2[i].push_back(ind2);
			}
		}
	}
	for(int i=0;i<A;i++){
		if(i>=2)Xe[i]=(Xe[i]+Xe[i-1])%mod;
		for(ll int j=0;j<mp1[i].size();j++){
			Xe[mp1[i][j]]=(Xe[mp1[i][j]]+Xe[i])%mod;
		}
		for(ll int j=0;j<mp2[i].size();j++){
			Xe[mp2[i][j]]=(Xe[mp2[i][j]]-Xe[i]+mod)%mod;
		}
	}
	Xe.pop_back();
	for(auto i:Xe)cout<<i<<" ";
	
return 0;
}
