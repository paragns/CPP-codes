#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int summer(int in, int s, int e, auto &A ){
	int sum=0;
	for(int i=s;i<e;i++){
		sum+=abs(A[i]-in);
	}
	return sum;
}
int check(int mid, auto &A, int w,int &ans){
	int s=0,e=0,sum=0,num=0;
	int prex=0;
	for(int i=0;i<A.size();i++){
		sum+=A[i];
		num++;
		e++;
		int x=summer((sum/num), s,e,A);
		//cout<<x<<"*"<<endl;
		if(x>mid){
			
			ans+=prex;
		//	cout<<ans<<" "<<prex<<endl;
			prex=0;
			w--;
			s=i;e=i+1;
			sum=A[i];
			num=1;
		}
		else{
			prex=x;
			if(i==A.size()-1)ans+=prex;
		}
		if(w<0)return 0;
	}
	w--;
	if(w<0)return 0;
	else return 1;
	
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
		
		int high=(A[n-1]-A[0])*n;
		int low=0;
		int ans=0;
		while(low<high){
			int mid=low+(high-low)/2;
			int temp=0;
			//cout<<mid<<"&"<<endl;
			if(check(mid,A,k,temp)){
					high=mid;ans=temp; 
					//cout<<mid<<" "<<ans<<endl;
				}
			else low=mid+1;
		}
		cout<<ans;
	}
return 0;
}
