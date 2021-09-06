#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	while(n--){
		int x,y;
		cin>>x>>y;
		int key;
		cin>>key;
		vector<char>p;
		for(int i=0;i<x;i++)
			p.push_back('H');	
		for(int i=0;i<y;i++)
			p.push_back('V');
				
		while(key--){
			int i=x+y-1;
			int j=i;
			while(i>=1 and p[i]<=p[i-1]){
				i--;
			}
			swap(p[i],p[i-1]);
			reverse(p.begin()+i+1,p.end());
				
		}
		for(auto i:p)cout<<i;
				
	
		
		cout<<endl;
	}
 
 
return 0;
}
