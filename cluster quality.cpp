#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	vector<vector<int>>A(n,vector<int>(2,0));
	 	for(int i=0;i<n;i++){
		 	cin>>A[i][1];
		}
		cin>>n;
		 for(int i=0;i<n;i++){
		 	cin>>A[i][0];
		}
		
	 	int mm; cin>>mm;
	 	sort(A.begin(),A.end(),greater<vector<int>>());
		 
		ll int sum=0,ans=0;
	 	multiset<ll int>s;
	 	
		 for(int i=0;i<n;i++){
			 s.insert(A[i][1]);
			 int rel=A[i][0];
			 sum+=A[i][1];
			 if(s.size()==mm+1){
			 	//cout<<sum<<"%"<< *(s.begin())<<"%";
			 	sum-= *(s.begin());
				s.erase(s.begin());
			 	//cout<<sum<<"%"<<endl;
			 }
			 //cout<<sum<<"*"<<rel<<" ";
			 ans=max(ans,sum*rel);
		}
		cout<<ans;
	 }
	
	
return 0;
}
