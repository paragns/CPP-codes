#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int ans;
bool check(string &A, int k){
	for(int i=0;i<A.size();i++){
		if(i+k<A.size() and A[i]!=A[i+k])return 0;
	}
	return 1;
}
void func(string &A, string &B, int k){
	string t="";
	int j=B.size()-1;
	for(int i=A.size()-1;i>=0;i--){
		if(A[i]=='1')t+=B[j];
		j--;
	}
	if(t.size()==0)return;
	if(check(t, k)){ans++; cout<<t<<endl;}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	ans=1;
	 	int n,k;
	 	cin>>n>>k;
	 	string A;
	 	cin>>A;
	 	int sz=(1<<n);
	 	//cout<<sz;
	 	for(int i=1;i<sz;i++){
			string c="";
			int m=i;
			while(m){
				if(m&1)c+='1';
				else c+='0';
				m=(m>>1);
			}
			func(c,A,k); 
		}
		cout<<ans;
	}
return 0;
}
// 10  cbab  a
