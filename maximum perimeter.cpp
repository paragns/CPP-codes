#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int ans=0;
void kadane(vector<int> &top, vector<int>& p,int x, int y){
	int s=0, n=top.size();
	//for(int i:p)cout<<i<<" ";
//	cout<<endl;
	for(s;s<n;s++){
		if(top[s]==-1)continue;
		for(int i=s+1;i<n;i++){
			if(p[s]==-1 or p[i]==-1){
				break;
			}
			//cout<<s<<" "<<i<<endl;
			ans=max(ans,2*(i-s+ y-x));
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int r,c;
	 	cin>>r>>c;
	 	vector<vector<int>>A(r,vector<int>(c));
	 	for(int i=0;i<r;i++){
			string t; cin>>t;
			for(int j=0;j<c;j++){
				if(t[j]=='.')A[i][j]=1;
				else A[i][j]=-1;
			} 
		}
		for(int i=0;i<r-1;i++){
			vector<int>p(c,0);
			for(int j=i+1;j<r;j++){
				for(int k=0;k<c;k++){p[k]+=A[j][k];if(p[k]==-1 or A[j][k]==-1)p[k]=-1;}
				kadane(A[i],p,i,j);
			}
		}
		cout<<ans;
	}
return 0;
}
