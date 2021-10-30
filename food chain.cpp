#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int check(int mid,vector<int>&A, int k){
	int sum=0,num=0,s=0,cnt=0;
	for(int i=0;i<A.size();i++){
		sum+=A[i];
		num++;
		double x=sum/num;
		//cout<<x<<" ";
		if(max(A[i]-x,x-A[s])>mid){
			cnt++;
			s=i;
			num=1;
			sum=A[i];
		}
			if(i==A.size()-1)cnt++;
	}
	//cout<<cnt<<endl ;
	if(cnt>k)return 0;
	else return 1;
}
int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	cin>>T;
	while(T--){
	 	int n; cin>>n;
		int k; cin>>k;
	 	vector<int>A(n);
		for(int i=0;i<n;i++)cin>>A[i];
	 	sort(A.begin(),A.end());
	
		int high=(A[n-1]-A[0]);
		int low=0;
		while(low<high){
			int mid=low+(high-low)/2;
			//cout<<mid<<"&"<<endl;
			if(check(mid,A,k))high=mid; 
			else low=mid+1;
		}
		cout<<high<<"\n";
	}
return 0;
}
