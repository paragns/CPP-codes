
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
	 	int n,s,k; cin>>n;
	 	vector<int>A(n),vis(n);
	 	for(int i=0;i<n;i++){
			cin>>A[i];
		}
		cin>>s>>k;
		multiset<int,greater<int>>s1,s2;
		for(int i=0;i<k;i++){
			s1.insert(A[i]);
			vis[i]=1;
		}
		for(int i=0;i<k;i++){
			if(!vis[n-i-1])s2.insert(A[n-i-1]);
		}
		int l=k,r=n-k-1;
		ll int ans=0;
		while(s--){
			int x=*(s1.begin());
			int y=*(s2.begin());
			if(x>=y){
				//cout<<x<<endl;
				ans+=x;
				s1.erase(s1.begin());
				if(l<=r){s1.insert(A[l]); l++;}
			}
			else{
			//	cout<<y<<endl;
				ans+=y;
				s2.erase(s2.begin());
				if(l<=r){s2.insert(A[r]);r--;}
			}
		}
		cout<<ans;
	}
return 0;
}
