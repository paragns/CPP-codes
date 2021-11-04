#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	ll int sum=0;
	 	vector<double>A(n);
		for(int i=0;i<n;i++){
			 double x;
			 char t;
			 cin>>x>>t;
			 if(t=='L'){
			 	x+=0.01;
				 A[i]=-x;
				 sum-=(int)x;
			 }
			 else{
			 	x+=0.01;
			 	sum+=(int)x;
			 	A[i]=x;
			 }
		}
		ll int ans1=sum,ans2=sum;
		for(int i=0;i<n;i++){
			int tot=0,cnt=0;
			for(int j=i;j<n;j++){
				tot+=A[j];
				if(A[j]<0)cnt--;
				else cnt++;
				if(cnt==0){
					ans1=min(ans1,sum-tot);
					ans2=max(ans2,sum-tot);
				}
			}
		}
		ans1=abs(ans1);
		ans2=abs(ans2);
		ans1=max(ans1,ans2);
		cout<<ans1<<'\n';
	 	
	}
return 0;
}
