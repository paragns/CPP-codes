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
	 	string A;
	 	
	 	cin>>A;
	 	if(A.size()<=1)return A.size();
	 	char a=A[0];
		 int cnt=1,ans=-1;
		for(int i=1;i<A.size();i++){
			if(A[i]==A[i-1])cnt++;
			else cnt=1;
			if(cnt>ans)ans=cnt, a=A[i];
		}
		cout<<a;
	 }
	
	
return 0;
}
