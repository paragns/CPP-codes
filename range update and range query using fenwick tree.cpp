   #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    const int N=1e5+5;
    vector<vector< int>>fenwics;
    void update(int indx,int x,int del){
    	for(x;x<N;x+=(x&-x)){
    		fenwics[indx][x]+=del;
    	}
    }
    int query(int indx, int x){
    	int sum=0;
    	for(x;x>0;x-=(x&-x)){
    		sum+=fenwics[indx][x];
    	}
    	return sum;
    }
    int index_sum(int x){
		return query(0,x)*x-query(1,x);
	}
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	fenwics.resize(2,vector< int>(N,0));
    	
		int n; cin>>n;
    	vector<int>A(n);
    	for(int i=0;i<n;i++)cin>>A[i];
    	
		for(int i=0;i<n;i++){
    		//1 based ind updation
			int l=i+1,r=l,val=A[i];
			update(0,l,val);
			update(0,r+1,-1*val);
			update(1,l,val*(l-1));
			update(1,r+1,-1*val*(r));
    	}
		int q; cin>>q;
    	//queries are also 1-based indexed
    	for(int i=0;i<q;i++){
    		int l,r,val,type;
    		cin>>type;
    		if(type==0){
				//range update
				cin>>l>>r>>val;
				update(0,l,val);
				update(0,r+1,-1*val);
				update(1,l,val*(l-1));
				update(1,r+1,-1*val*(r));
			}
			if(type==1){
				//range query
				cin>>l>>r;
				cout<<index_sum(r)-index_sum(l-1)<<endl;
			}		
    	}
    	return 0;
    }
