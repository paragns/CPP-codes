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
	 	int n,m;
	 	cin>>n>>m;
	 	vector<int>A(n+1,0);
	 	for(int i=0;i<m;i++){
			int x,y,k;
			cin>>x>>y>>k;
			A[x]+=k;
			A[y+1]-=k; 	
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=A[i];
			A[i]=sum;
		}
		A.pop_back();
	 	
	 	for(int i:A)cout<<i<<" ";
	 	cout<<"maximum element is:"<<*max_element(A.begin(),A.end());
	 }
	
	
return 0;
}
