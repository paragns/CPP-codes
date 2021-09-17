#include <BITs/stdc++.h>
using namespace std;
#define ll long long
ll int n;
vector<ll int>BIT;
void update(ll int x, ll int del){
for(x;x<=n;x+=x&-x)
	BIT[x]+=del;
}
ll int query(int x){
	ll int sum=0;
	for(x;x>0;x-=x&-x)
		sum+=BIT[x];
	return sum;	
} 

 int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
	ll int T;
        cin>>T;
        while(T--){
        	 cin>>n;
    		vector<ll int>LIT(n+1,0);    	 
            vector<int>A(n+1),B(n);
            for(int i=0;i<n;i++){
				int x;
				cin>>x;
				A[x]=i+1;
			}
            for(int i=0;i<n;i++){
				int x;
				cin>>x;
				B[i]=A[x];
			}
			BIT=LIT;
			
			//for(int i=0;i<n;i++) cout<<B[i]<<" ";
            //cout<<endl;
            
			vector<int>left(n,0),right(n,0);
             for(int i=0;i<n;i++){	
				left[i]=query(B[i]);
				update(B[i],1);
			} 
            BIT=LIT;
			for(int i=n-1;i>=0;i--){
				update(B[i],1);
				right[i]=query(n)-query(B[i]);
			}
			
            ll int ans=0;
			//for(int i=0;i<n;i++) cout<<left[i]<<" ";
           // cout<<endl;
           // for(int i=0;i<n;i++) cout<<right[i]<<" ";
            
            for(int i=0;i<n;i++){
				ans+=left[i]*right[i];  	  	
			}
			cout<<ans<<"\n";
        }
	
return 0;
}
	

        
