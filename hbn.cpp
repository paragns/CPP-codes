bool check(int mid){
	int maxe=(mid/2);
	if(mid%2)maxe+=1;
	int curr=1;
	int i=0;
	for(i;i<n;i++){
		if(curr=maxe)break;
		if(A[i]>=curr){
			curr++;
		}
		else {
			curr=A[i];
			curr++;
		}
	}
	curr--;
	for(i;i<n;i++){
		if(curr==1)return 1;
		if(A[i]>=curr){
			curr--;
		}
		else {
			curr=A[i];
			curr--;
		}
		
	}
	return 0;
	
}
