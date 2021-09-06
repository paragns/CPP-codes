#include <bits/stdc++.h>
using namespace std;


int find_par(int x, vector<int >&par){
	if(par[x]==x)return x;
	else return find_par(par[x],par);
}
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;
	
	int g;
	cin>>g;
	
	int q;
	cin>>q;
	vector<int>origin(q);
		for(int i=0;i<q;i++)
			cin>>origin[i];
		
	cin>>q;
	
	vector<int>dest(q);
	for(int i=0;i<q;i++)
		cin>>dest[i];
			
			
	vector<int>par(n+1);
for(int i=1;i<=n;i++)par[i]=i;

		for(int i=g+1;i<=n;i++)
		for(int j=i*2;j<=n;j=j+i){
			int x=find_par(i,par);
			int y=find_par(j,par);
				if(x!=y) {
					x<y? par[y]=x:par[x]=y;	
					}
		}
	for(int i=0;i<q;i++){
		if(find_par(origin[i],par)==find_par(dest[i],par))cout<<1<<endl;
			else cout<<0<<endl;
		}			
return 0;
}
