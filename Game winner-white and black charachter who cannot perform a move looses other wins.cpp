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
	//cin>>t;
	 while(t--){
		string A;
		cin>>A;
		int n=A.size();
		int start=0,wendy=0,bob=0;
		for(int i=1;i<n-1;i++){
			if(A[i-1]=='w' and A[i+1]=='w' and A[i]=='w')wendy++;
		}
		//cout<<wendy; 	
	 	
	 	start=0;
		for(int i=0;i<n;i++){
		if(A[i-1]=='b' and A[i+1]=='b' and A[i]=='b')bob++;
		}
		//cout<<bob; 
	 	if(bob>=wendy)cout<<"bob";
	 	else cout<<"wendy";
	 }
	
	
return 0;
}
