    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int a, b, k;
    	cin>>a>>b>>k;
    	int i, j;
    	vector<int> primes(b+1, 1);
    	primes[0]=0;
    	primes[1]=0;
    	for(i=2;i<=b;i++){
    		if(primes[i]==1){
    			for(j=2*i;j<=b;j+=i){
    				primes[j]=0;
    			}
    		}
    	}
    	for(i=1;i<=b;i++){
    		primes[i]+=primes[i-1];
    	}
    	int low=1, high=b-a+1;
    	while(low+1<high){
    		int mid=(low+high)/2;
    		bool flag=true;
    		for(i=a;i<=b-mid+1;i++){
    			if(primes[i+mid-1]-primes[i-1]<k){
    				flag=false;
    				break;
    			}
    		}
    		if(flag) high=mid;
    		else low=mid;
    	}
    	bool flag=true;
    	for(i=a;i<=b-low+1;i++){
    		if(primes[i+low-1]-primes[i-1]<k){
    			flag=false;
    			break;
    		}
    	}
    	if(flag){
    		cout<<low<<"\n";
    		return 0;
    	}
    	flag=true;
    	for(i=a;i<=b-high+1;i++){
    		if(primes[i+high-1]-primes[i-1]<k){
    			flag=false;
    			break;
    		}
    	}
    	if(flag){
    		cout<<high<<"\n";
    		return 0;
    	}
    	else cout<<"-1\n";
    	return 0;
    }
