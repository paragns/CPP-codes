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
	 	string A;
	 	cin>>A;
	 	string t;
	 	cin>>t;
	 	vector<int>mask(26);
	 	for(int i=0;i<26;i++)mask[i]=t[i]-'0';
	 	int k;
	 	cin>>k;
	 	int i=0,j=0,cnt=0,ans=0;
	 	while(j<A.size()){
			 while(j<A.size() and cnt<=k){
			 	ans=max(ans,j-i);
				if(!mask[A[j]-'a'])cnt++;
				j++; 	
			}
			if(cnt<=k and j==A.size())ans=max(ans,j-i);
			cout<<0<<" "<<j<<endl;
			while(cnt>k and i<j){
				if(!mask[A[i]-'a'])cnt--;
				i++;	
			}
			//ans=max(ans,j-i);
		}
		cout<<ans;
	}
return 0;
}
