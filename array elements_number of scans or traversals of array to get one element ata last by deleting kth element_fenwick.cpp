#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=2000;
vector<int>fenwick;
void update(int x,int val){
	for(x;x<N;x+=(x&(-x))){
		fenwick[x]+=val;
	}
}
int query(int x){
	int sum=0;
	for(x;x>0;x-=x&(-x)){
		sum+=fenwick[x];
	}
	return sum;
}
int bins(int low, int high, int val){
	while(low<high){
		//cout<<"*";
	 	int mid=low+(high-low)/2;
	 	if(query(mid)>=val)high=mid;
	 	else low=mid+1;
	}
	return high;
}
int main(){
	fenwick.resize(N);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	for(int i=1;i<=n;i++){
		 	int t; cin>>t;
			update(i,1);
		}
	 	int x; cin>>x;
		int tot=query(n);
		int prev=0,ans=0;
		
		while(tot!=1){
			int ele=x;
			int num=query(prev);	
			if(tot-num>=ele){
				int ind=bins(prev, n,ele);
				cout<<ind<<endl;
				update(ind,-1);
				prev=ind;
				tot=query(n);
				continue;
			}
			ele=ele-(tot-num);
			prev=0; ans++;
			ans+=(ele/tot);
			ele=(ele%tot);		
		//	cout<<prev<<" "<<n<<" "<<ele<<endl;
			if(ele==0){ele=tot; ans--;}
			int ind=bins(prev,n,ele);
			update(ind,-1);
			prev=ind;
			cout<<ind<<endl;
			tot=query(n);
		}
		cout<<ans;
	}
return 0;
}
