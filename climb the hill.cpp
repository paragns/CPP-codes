    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    int main() {
        ios::sync_with_stdio(false);cin.tie(0);
        int n;
    	cin>>n;
    	vector<int> v(n);
    	for(int i=0;i<n;i++){
    		cin>>v[i];
    	}
    	priority_queue<int>p1;
    	ll cost1=0,cost2=0;
    	p1.push(v[0]);
    for(int i=1;i<n;i++){
    		if(v[i]<p1.top()){
    			cost1 += p1.top()-v[i];
    			cout<<p1.top()<<" ";
				p1.pop();
    			p1.push(v[i]);
    			cout<<v[i]<<" "<<cost1<<endl;
    		}
    		p1.push(v[i]);
    	}
    priority_queue<int>p2;
    	p2.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
    		if(v[i]<p2.top()){
    			cost2 += p2.top()-v[i];
    			p2.pop();
    			p2.push(v[i]);
    		}
    		p2.push(v[i]);
    	}
     	cout<<cost1<<" "<<cost2<<endl;
    	return 0;
    }
