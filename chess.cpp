#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>dir={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
bool safe(int x, int y){
	if(x>=0 and x<n and y>=0 and y<n)return 1;
	return 0;
}
double func(int x, int y, int k){	
double ans=0;
if(k==0){
	if(safe(x,y))return 1;
	else return 0;
}
for(int i=0;i<8;i++){
	int cx=x+dir[i][0],cy=y+dir[i][1];
	ans+=func(cx,cy,k-1)/(8.0);
}
}
int main(){
int x,y,k;
cout<<fixed;
cout<<setprecision(3);
cin>>n>>x>>y>>k;
cout<<func(x,y,k)*100;
return 0;
}
