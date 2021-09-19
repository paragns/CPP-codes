#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    vector<int>a(n);
	    long long ans =0;
	    for(int i =0;i<n;i++)
	    {
	        cin>>a[i];
	        ans+=a[i];
	    }
	    
	    for(int s =1;s<=n-1;s++){
	        long long cans=0;
	        vector<int>b(n);
	        for(int i =0; i<n;i++)
	        {
	            b[i]=min(a[i],a[(i+1)%n]);
	            cans+=b[i];
	        }
	        a=b;
	        //for(int i:b)cout<<i<<"*";
	        //cout<<endl;
	        ans =min(ans,cans+x*s);
	      //  cout<<ans<<"*"<<'\n';
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}

