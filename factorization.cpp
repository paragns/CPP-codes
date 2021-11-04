void factorize(int n){
	int nofdiv = 1;
	map<int, int>mp;
	for(int i=2;i*i<=n;i++)
	if(n % i == 0){
		int cnt = 0;
		while(n % i == 0)cnt++ , n /= i;
		mp[i] = cnt;
		nofdiv *= (cnt + 1);
	}
	
	if(n > 1) mp[n] = 1 , nofdiv *= 2;
}

