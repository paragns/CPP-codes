#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN

int check(int mid, auto &A, int k){
	int pos=A[0]+mid;
	int cnt=1;
	int n=A.size();
	for(int i=0;i<n;i++){
		if(abs(A[i]-pos)>mid){
			pos=pos+A[i];
			cnt++;
		}
	}
	if(cnt>k)return 0;
	 return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	while(T--){
	 	int n; cin>>n;
	 	vector<int>A(n);
		for(int i=0;i<n;i++)cin>>A[i];
		int k; cin>>k;
		int high=1e9+1;
		int low=0;
		//int ans=0;
		while(low<high){
			int mid=low+(high-low)/2;
			if(check(mid,A,k)){
					high=mid;//ans=temp; 
				}
			else low=mid+1;
		}
		cout<<high;
	}
return 0;
}
