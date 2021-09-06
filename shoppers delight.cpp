#include<bits/stdc++.h>
using namespace std;
using ll = long long;
# define mod 1000000007
vector<int>jeans;
vector<int>shoes;  
vector<int>skirt;
vector<int>top;
 
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	jeans.resize(n);
	for(int i=0;i<n;i++)
		cin>>jeans[i];
	
	int m;
	cin>>m;
	shoes.resize(m);
	for(int i=0;i<m;i++)
		cin>>shoes[i];
	
	int o;
	cin>>o;
	skirt.resize(o);
	for(int i=0;i<o;i++)
		cin>> skirt[i];
		
	int p;
	cin>>p;
	top.resize(p);
	
	for(int i=0;i<p;i++)
		cin>>top[i];
		
	ll bud;
	cin>>bud;	
		
		vector<ll >A,B;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				A.push_back((jeans[i]+shoes[j]));
	
		for(int i=0;i<o;i++)
			for(int j=0;j<p;j++)
				B.push_back((skirt[i]+top[j]));
		ll ans=0;
	sort(B.begin(),B.end());
	
	for( int i=0;i<A.size();i++){
		ans= (ans+ (upper_bound(B.begin(),B.end(),bud-A[i])- B.begin()));
	}
	
	cout<<ans;
	return 0;
}
