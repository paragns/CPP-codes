    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll int dp[20][20][2];
    ll d, cnt;
     
    ll digitdp(string &x,int pos, ll int curr, int check){
    	ll i, n=x.size();
    	if(curr >cnt) return 0;
    	if(pos==n && curr==cnt) return 1;
    	if(pos==n) return 0;
    	if(dp[pos][curr][check]!=-1) return dp[pos][curr][check];
    	
    	ll ans=0;
    	if(check==0){
    		int k=stoi(x.substr(pos,1));
    		for(i=0;i<k;i++){
    			if(i==d){
    				ans+=digitdp(x,pos+1, curr+1, 1);
    			}
    			else ans+=digitdp(x,pos+1, curr, 1);	
    		}
    		if(k!=d) ans+=digitdp(x,pos+1, curr, 0);
    		else ans+=digitdp(x,pos+1, curr+1, 0);
    	}
    	else{
    		ans+=digitdp(x,pos+1, curr+1, 1);
    		ans+=9*digitdp(x,pos+1, curr, 1);	
    	}
     
    	return dp[pos][curr][check]=ans;
     
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int t;
    	cin>>t;
    	while(t--){
    		memset(dp,-1,sizeof(dp));
    		ll low, high;
    		cin>>low>>high;
    		low--;
    		string a, b;
    		a=to_string(low);
    		b=to_string(high);
    		cin>>d>>cnt;
    		ll int l=digitdp(b,0,0,0);
    			memset(dp,-1,sizeof(dp));
    		ll int r=digitdp(a,0,0,0);
		cout<<l-r<<'\n';   	}
    	return 0;
    }
