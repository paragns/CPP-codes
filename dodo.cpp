#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

int check(int mid, auto &A, int k){
	int n=A.size();
	int cnt=0;
	for(int i=0;i<n;i++){
		if(abs(A[i+1]-A[i])<mid){cnt++;i++;}
	}
	if(cnt<k)return 0;
	 return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
//	cin>>T;
	while(T--){
	 	int n; cin>>n;
		int p; cin>>p;
	 	vector<int>A(p);
		for(int i=0;i<n;i++)cin>>A[i];
	 	sort(A.begin(),A.end());
		int high=1e9+1;
		int low=0;
		while(low<high){
			int mid=low+(high-low)/2;
			//cout<<mid<<" "<<check(mid,A,n)<<endl;
			if(check(mid,A,n)){
					high=mid;//ans=temp; 
				}
			else low=mid+1;
		}
		cout<<high;
	}
return 0;
}
