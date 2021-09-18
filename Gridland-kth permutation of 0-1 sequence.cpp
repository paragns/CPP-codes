    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
    ll fact[21];
    string Path(int x, int y, int k,string &s){
        if(k==0){ 
            for(int i=0;i<x;i++) s.push_back('H');
            for(int i=0;i<y;i++) s.push_back('V');
            return s;
        }
        ll nex=fact[x+y-1]/(fact[x-1]*fact[y]);
    	if(k<nex){
            s.push_back('H');
            return Path(x-1,y,k,s);
        }
        else{
            s.push_back('V');
            return Path(x,y-1,k-nex,s);
        } 
    }    
    int main(){
    	fast_io;
    	int n;
    	cin>>n;
        fact[0]=1;
        for(int i=1;i<21;i++){
            fact[i]= long(i)*fact[i-1];
        }
        while(n--){
            int x,y,k;
            cin>>x>>y>>k;
            string s="";
            cout<<Path(x,y,k,s)<<endl;
        }
    	
    	return 0;
    }
