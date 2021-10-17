#include <bits/stdc++.h>
using namespace std;
// Driver code
vector<vector<int>>swapes={{0,1},{0,3},{1,2},{1,4},{2,5},{3,4},{3,6},{4,5},{4,7},{5,8},{6,7},{7,8}};
unordered_map<int,int>primes;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    
    primes[2]++;
    primes[3]++;
	primes[5]++;
	primes[7]++;
	primes[11]++;
	primes[13]++;
	primes[17]++; 
	  int T; cin>>T;
	while(T--){
		unordered_set<string>store; 
		string A,B;
		for(int i=0;i<9;i++){
			char c='0'+i+1;
			A.push_back(c);
		}
		for(int i=0;i<9;i++){
			int x;cin>>x;
		     char c='0'+x;
			//cout<<c<<" ";
			B.push_back(c);
		}
		queue<string>q;
		q.push(B);store.insert(B);
		int flag=0,ans=0;
		while(!q.empty()){
			int sz=q.size();
			ans++;
			//cout<<sz<<endl;
			while(sz--){
				string t=q.front();
				if(t==A){flag=1; break;}
				q.pop();
				for(int i=0;i<swapes.size();i++){
					int x=swapes[i][0],y=swapes[i][1];
					if(primes[(t[x]-'0')+(t[y]-'0')]){
						swap(t[x],t[y]); 
						if(store.find(t)==store.end()){q.push(t);store.insert(t);}
						swap(t[x],t[y]);
					}
				}
			}
				if(flag)break;
		}	
			if(flag)cout<<ans-1<<'\n';
			else cout<<-1<<'\n';
	}
return 0;
} 
