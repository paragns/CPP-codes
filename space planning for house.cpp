#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
void dfs1(int x, int y, vector<vector<int>> &A, int &num){
	num++;
	A[x][y]=-1;
	for(int i=0;i<4;i++){
		int cx=x+dir[i][0];
		int cy=y+dir[i][1];
		if(A[cx][cy]==0)dfs1(cx,cy,A,num);
	}
	
}
void dfs2(int x, int y, vector<vector<int>> &A, int num){
	A[x][y]=num;
	for(int i=0;i<4;i++){
		int cx=x+dir[i][0];
		int cy=y+dir[i][1];
		if(A[cx][cy]==-1)dfs2(cx,cy,A,num);
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	int n; cin>>n;
	 	vector<vector<int>>A(n,vector<int>(n,0));
	 	for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
		 	cin>>A[i][j];
		 }
		}
	 	
	 	for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
		 	int num=0;
		 	if(A[i][j]==0){
			 dfs1(i,j,A,num);
			 if(num==1)num=0;
			 dfs2(i,j,A,num);
			 }
		 }
		}
cout<<endl;
	 	for(int i=0;i<n;i++){
		 for(int j=0;j<n;j++){
		 	cout<<A[i][j]<<" ";
		 }
		 cout<<endl;
		}

	 }
	
	
return 0;
}
