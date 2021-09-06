        #include <bits/stdc++.h>
        using namespace std;
        # define ll long long
        #define mod 1000000007
        #define inf INT_MAX
        #define minf INT_MIN
        void multiply(vector<vector<ll int>> &A, vector<vector<ll int>>& B){
        	ll int m=A.size();
        	vector<vector<ll int>>C(m,vector<ll int>(m,0));
        	for(int i=0;i<m;i++){
        		for(int j=0;j<m;j++){
        			for(int k=0;k<m;k++){
        				C[i][j]= (C[i][j]%mod+(A[i][k]*B[k][j])%mod)%mod;
        			}
        		}
        	}
            	A=C;
            	return;
        }
        vector<vector<ll int>> exponent(vector<vector<ll int>> &A,ll int n){
        		if(n==1)return A;
        		vector<vector<ll int>> B=exponent(A,n/2);
        		multiply(B,B);
        		if(n%2) {
        			multiply(B,A);
        			return B;
        		}
        		else return B;
        }
        int main()
        {
        	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        	int T=1;
        	//cin>>T;
        	 while(T--){
        	 	ll int k,n; cin>>k>>n;
        	 	vector<ll int>A(n);
        		 for(ll int i=0;i<n;i++)cin>>A[i];
        		 ll int m=sqrt(n);
        		 
        	 	vector<vector<vector<ll int>>>matrices(n,vector<vector<ll int>>(m,vector<ll int>(m,0)));
        	 	
        		 for(int i=0;i<n;i++){
        	 		int indx=i;
        		  	for(int j=0;j<m;j++)
        		  		for(int l=0;l<m;l++){matrices[i][j][l]=A[indx];indx=(indx+1)%n;}
        		 }
        	 	reverse(matrices.begin()+1,matrices.end());
        	 	
        //	 	for(int i=0;i<n;i++){
        //		  	for(int j=0;j<m;j++){
        //		  		for(int l=0;l<m;l++)cout<<matrices[i][j][l]<<" ";
        //		  		cout<<endl;
        //		 	}
        //		 	cout<<endl;
        //		 }
        		ll int expo= k/(n),rem=k%(n);
        		vector<vector<ll int>>Res(m,vector<ll int>(m,0));
        		int x=0,y=0;
        		while(x<m and y<m){
        			Res[x][y]=1;
        			x++;y++;
        		}
        		auto ans=Res,temp=Res;
        		for(int i=0;i<n;i++){
        			multiply(Res,matrices[i]);
        			if(i==rem)temp=Res;
        		}
        		
        		
        //		for(int j=0;j<m;j++){
        //		  		for(int l=0;l<m;l++)cout<<Res[j][l]<<" ";
        //		  		cout<<endl;
        //		 	}
        		if(expo>0)ans=exponent(Res,expo); 	
        				
        			
        		multiply(ans,temp);
        		ll int sum=0;
        		for(int j=0;j<m;j++){
        	  		for(int l=0;l<m;l++)sum=(sum+ans[j][l])%mod;
        	  		//cout<<endl;
        	 	}
        	 	cout<<sum;
        	 }
        	
        	
        return 0;
        }
