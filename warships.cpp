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
	 	int l,m;cin>>l>>m;
	 	vector<vector<int>>mp;
	 	for(int i=0;i<m;i++){
	 		vector<int>temp;
		 	for(int j=0;j<((i*i)%m+1);j++){
				temp.push_back(j); 
			}
			mp.push_back(temp);
		}
		
		int ans=1;
		vector<int>p(1001,0);
		p[2]=1;
		l--;
		while(l--){
			vector<int>q(1001,0);
			for(int i=0;i<p.size();i++){
				if(p[i]==1)
				for(int j:mp[i]){
					//cout<<j<<" ";
					if(q[j]==0){ans++;q[j]=1;}
				}
				
			}
			p=q;
		}
		cout<<ans%m;
	}
return 0;
}
