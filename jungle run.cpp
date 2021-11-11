#include <bits/stdc++.h>
using namespace std;
int n;
bool safe(int x, int y){
	if(x>=0 and x<n and y>=0 and y<n)return 1;
	return 0;
}
vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
int func(int x, int y, auto &A){
	if(A[x][y]==2)return 0;
	int ans=INT_MAX;
	for(int i=0;i<4;i++){
		int cx=x+dir[i][0],cy=y+dir[i][1];
		if(safe(cx,cy) and A[cx][cy]!=-1){
			ans=min(ans,1+func(cx,cy,A));
		}
	}
	return ans;
}
int main() {
	cin>>n;
	vector<vector<int>>A(n,vector<int>(n,0));
	int x,y;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char t;
			cin>>t;
			if(t=='S')x=i, y=j;
			if(t=='E')A[i][j]=2;
			if(t=='T')A[i][j]=-1;
		}
	}
	cout<<func(x,y,A);
	return 0;
}
