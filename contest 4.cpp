#include <bits/stdc++.h>
using namespace std;  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int x;
cin>>x;
int n;
cin>>n;   
vector<int>A(n);
for	(int i=0;i<n;i++)
	cin>>A[i];
	
stack<int>s;

vector<int>prev(n);

int i=0;
s.push(i);
prev[i]=-1;
i++;

while(i<n and !s.empty()){
		
		while(A[s.top()]>=A[i]){
			s.pop();
			if(s.empty())break;
		}
		if(s.empty())prev[i]=-1;
		else prev[i]=s.top();
		s.push(i);
		i++;
}

stack<int>p;
s=p;
vector<int>aft(n);
i=n-1;
s.push(i);
aft[i]=n;
i--;

while(i>=0 and !s.empty()){
		
		while(A[s.top()]>=A[i]){
			s.pop();
			if(s.empty())break;
		}
		if(s.empty())aft[i]=n;
		else aft[i]=s.top();
		s.push(i);
		i--;
}

for(int i=0;i<n;i++){
	aft[i]=aft[i]-prev[i]-1;
	aft[i]=aft[i]>=x? x:aft[i];
}

int ans=-1;
for(int i=0;i<n;i++){
	if(aft[i]==x){
		ans=max(ans, A[i]);
	}
}

cout<<ans;
}

