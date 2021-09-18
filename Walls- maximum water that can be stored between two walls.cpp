    #include <bits/stdc++.h>
    using namespace std;
    # define inf 1000000001
    int main()
    {
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	long long int t;
    	cin>>t;
    	while(t--){
    		long long int n;
    		cin>>n;
    		vector<vector<long long int>>A(n,vector<long long int>(2,0));
    		vector<long long int>walls(n);
    		for(long long int i=0;i<n;i++){
    			long long int x;
    			cin>>x;
    			walls[i]=x;
    			A[i][0]=x;
    			A[i][1]=i;
    			//A[i].push_back({x,i});
    		}
    		sort(A.begin(),A.end(),greater<vector<long long int>>());
    		vector<long long int>B(n);
    		for(long long int i=0;i<n;i++){
    			B[i]=A[i][1];	
    		}
    		long long int mine=inf,maxe=-inf;
    		vector<long long int>a(n),b(n);
    		for(long long int i=0;i<n;i++){
    			a[i]=mine;
    			b[i]=maxe;
    			if(mine>B[i])mine=B[i];
    			if(maxe<B[i])maxe=B[i];
    			//cout<<a[i]<<"*"<<b[i]<<"&"<<endl;
    		}
    		a[0]=b[0]=B[0];
    		long long int ans=-1;
    		for(long long int i=n-1;i>=0;i--){
    			long long int x=max(abs(B[i]-a[i]),abs(B[i]-b[i]))-1;
    			ans=max(ans,walls[B[i]]*x);
    		}
    		long long t=0;
    		cout<<max(t,ans)<<endl;
    	
    	}
    	
    	
    return 0;
    }
