    #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    	int n;
    vector<vector< int>>fenwics;
     
    void update(int indx,int x,int del){
    	for(x;x<=n;x+=(x&-x)){
    		fenwics[indx][x]+=del;
    	}
    }
     
    int query(int indx, int x){
    	if(x==1)return 0;
    	int sum=0;
    	for(x;x>0;x-=(x&-x)){
    		sum+=fenwics[indx][x];
    	}
    	return sum;
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    	string A;
    	cin>>A;
     
    	n=A.size();
    	fenwics.resize(26,vector< int>(n+1,0));
    	int q; cin>>q;
    	
    		for(int i=0;i<n;i++){
    			int alpha=A[i]-'a';
    			update(alpha,i+1,1);
    		}
    		for(int i=0;i<q;i++){
    			int x,y,z;
    			char p;
    			cin>>x;
    			if(x==2){
    				cin>>y>>z;
    				ll int ans=0;
    				for(int i=0;i<26;i++){
    					 int t=query(i,z)-query(i,y-1);
    					if(t>0)ans+=1;
    					//cout<<query(i,z)<<" "<<query(i,y-1)<<endl;
    				}
    				cout<<ans<<'\n';
    			}
    			else{
    				cin>>y>>p;
    				update(A[y-1]-'a',y,-1);
    				A[y-1]=p;
    				update(p-'a',y,1);
    			}
    		
    		}
    		
    	return 0;
    }
