#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++){
			cin>>A[i];
		}
		int ans=-1,incl=A[0],excl=0;;
		for(int i=1;i<n;i++){
			int new_incl=excl+A[i];
			int new_excl=incl;
			incl=new_incl;
			excl=new_excl;
		}
		cout<<max(incl,excl);
	}
return 0;
}
