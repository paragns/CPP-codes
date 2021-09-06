#include <bits/stdc++.h>
using namespace std;
vector<string>A;
vector<string>B;
  int dx[]={-1,0,1,0};
  int dy[]={0,1,0,-1};
  bool safe(int x, int y){
  	if(x>=0 and x<A.size() and y>=0 and y<A[x].size())return 1;
  	else return 0;
  }
  
  int mark(int x, int y){
  //	cout<<x<<"*"<<y<<endl;
  	A[x][y]='0';
  	B[x][y]='0';
  	int ans=1;
  	for(int i=0;i<4;i++){
  		int cx=x+dx[i];
  		int cy=y+dy[i];
  		int t=1;
  		if(safe(cx,cy)){
  			if(A[cx][cy]==B[cx][cy]){
  				if(A[cx][cy]=='1'){
  					t= mark(cx,cy);
				  }
				else t= 1;  
			  }
			else t= 0;  
		  }
		if(t==0)ans=0;
	  }
	  return ans;
  }
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	A.resize(n);
	B.resize(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>B[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(A[i][j]=='1' and B[i][j]=='1'){
				ans+=mark(i,j);
				//cout<<i<<"*"<<j<<" "<<ans<<endl;
			}
	}
	
	cout<<ans;
return 0;
}
