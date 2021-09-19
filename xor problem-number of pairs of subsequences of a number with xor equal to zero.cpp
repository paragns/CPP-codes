#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	cin>>T;
	while(T--){ 	
	 	ll int x,y;
	 	cin>>x>>y;
	 	//12 102
	 	ll int ans=0;
	 	vector<ll int>A,B;
	 	while(x){
			A.push_back(x%10);
			x/=10; 
		}
		while(y){
			B.push_back(y%10);
			y/=10; 
		}
		reverse(A.begin(),A.end());
		reverse(B.begin(),B.end());
		//00101
		set<ll int>s;
		for(ll int i=1;i<(1<<A.size());i++){
			ll int t=i,j=A.size()-1;
			vector<ll int>temp;
			while(t){
				if(t&1)temp.push_back(A[j]);
				j--;
				t=t>>1;
			}
			ll int mul=1,num=0;
			for(int j=0;j<temp.size();j++){
				num +=mul*temp[j];
				mul*=10;
			}
			//cout<<num<<"|";
			s.insert(num);
		}
		for(ll int i=1;i<(1<<B.size());i++){
				ll int t=i,j=B.size()-1;
			vector<ll int>temp;
			while(t){
				if(t&1)temp.push_back(B[j]);
				j--;
				t=t>>1;
			}
			ll int mul=1,num=0;
			for(int j=0;j<temp.size();j++){
				num +=mul*temp[j];
				mul*=10;
			}
		//	cout<<num<<"|";
			if(s.find(num)!=s.end()){ans++; s.erase(num);}
		}
		cout<<ans<<"\n";
	}
return 0;
}
