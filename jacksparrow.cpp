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
	int T=1;
	//cin>>T;
	 while(T--){
	 	vector<vector<int>>A(5,vector<int>(5)),B;
	 	B=A;
	 	for(int i=0;i<5;i++){
		 for(int j=0;j<5;j++)cin>>A[i][j];
		 }
		 	
	 	
	 	for(int i=0;i<5;i++){
		 for(int j=0;j<5;j++)cin>>B[i][j];
		 }
		 cout<<endl;
		 
	 	for(int i=0;i<5;i++){
		 for(int j=0;j<5;j++)cout<<A[i][j]*B[i][j]<<" ";
		 cout<<endl;
		 }
		 cout<<endl;
	 	
	 }
	
	
return 0;
}
