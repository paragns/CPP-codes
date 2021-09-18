    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll int dp[20][20][2][2];
    ll int d, cnt;
     //if check ==1 smaller no is taken so ub =9 can be choosen
    
	ll int digitdp(string &x,int pos, ll int curr, int check,bool start){
		ll i, n=x.size();
    	if(curr >cnt) return 0;
    	if(pos==n && curr==cnt) return 1;
    	if(pos==n) return 0;
    	if(dp[pos][curr][check][start]!=-1) return dp[pos][curr][check][start];
    	
    	ll int ans=0;
    	ll int ub;
		check==1? ub=9:ub=(x[pos]-'0');
		// 
    	int dig=0;
        if(!start) ans+=digitdp(x,pos+1,curr,check or !(ub==dig),start);
        else ans+=digitdp(x,pos+1,curr+(d==dig),check or !(ub==dig),start);
            
        for(dig=1;dig<=ub;dig++){
            ans+=digitdp(x,pos+1,curr+(d==dig),check or !(ub==dig),1);
        }
        //check=0->ub=8
        //check=1->ub=9
      
    	return dp[pos][curr][check][start]=ans;
     
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int t;
    	cin>>t;
    	while(t--){
    		memset(dp,-1,sizeof(dp));
    		ll int low, high;
    		cin>>low>>high;
    		low--;
    		string a, b;
    		a=to_string(low);
    		b=to_string(high);
    		cin>>d>>cnt;
    		ll int l=digitdp(b,0,0,0,0);
    		
    		memset(dp,-1,sizeof(dp));
    		ll int r=digitdp(a,0,0,0,0);
    	cout<<l-r<<'\n';
    		
    	}    
    	return 0;
    }
   
