long long rabbitMultiplier(int k, int n){
	int rabbits = 1;
	for(int i =0;i<n;i++){
		rabbits *= 2;
		rabbits%=k;
	}
	return rabbits;
}