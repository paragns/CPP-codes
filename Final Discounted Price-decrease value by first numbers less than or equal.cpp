#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	
	vector<int>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	vector<int>p(n);
	//p[n-1]=A[n-1];
	stack<int>s;
	
	for(int i=0;i<n;i++){
		if(s.empty() or A[i]>A[s.top()]){s.push(i); continue;}
		while(!s.empty() and A[i]<=A[s.top()]  ){
			
			int j=s.top();
			s.pop();
			p[j]=A[j]-A[i];
		}
		s.push(i);
	}

	while(!s.empty()){
		int j=s.top();
		p[j]=A[j];
		s.pop();
	}
	

	long long int sum=0;
	for(int i:p)
		{
			sum+=i;
			//cout<<i<<"&";
		}
		//cout<<endl;
		cout<<sum<<endl;
		
		
		
		vector<int>ans;
		for(int i=0;i<A.size();i++){
			if(p[i]==A[i])ans.push_back(i);
		}
		for(int i=0;i<ans.size()-1;i++){
			cout<<ans[i]<<" ";
		}
		cout<<ans[ans.size()-1];
return 0;
}
