//floyd warshall;
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
	int t=1;
	int n,e;
	cin>>n>>e;
	vector<vector<ll int>>mat(n+1,vector<ll int>(n+1,inf));//remember to take long long;
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		mat[x][y]=w;
		// mat[y][x]=w;  for undirected graph;
 	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j){mat[i][j]=0;continue;}
				if(mat[i][j]>mat[i][k]+mat[k][j])mat[i][j]=mat[i][k]+mat[k][j];
			}

	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout<<mat[i][j]<<" ";
			cout<<endl;
}
return 0;
}
