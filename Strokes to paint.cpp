#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
vector<string>A;
bool is_safe(int i, int j){
	if(i>=0 and i<A.size() and j>=0 and j<A[i].size() and A[i][j]!='*')return 1;
	else return 0;
}
void color(int i, int j){
	//cout<<i<<" "<<j<<A[i][j]<<endl;
	char c=A[i][j];
	A[i][j]='*';
	for(int k=0;k<4;k++){
		int cx=i+x[k];
		int cy=j+y[k];
		if(is_safe(cx,cy) and A[cx][cy]==c)color(cx,cy);
	}
return;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n;
	 	cin>>n;
	 	A.resize(n);
	 	for(int i=0;i<n;i++){
		 	cin>>A[i];
		 }
		 
		 int ans=0;
		 
	 	for(int i=0;i<n;i++){
		 for(int j=0;j<A[i].size();j++){
		 	if(A[i][j]!='*'){color(i,j); ans++;}
		 }
		 }
	 	
	 	cout<<ans<<endl;
	 }
	
	
return 0;
}
