int findCount(){
	int count = 0;

	for(int i =1;i<=1000;i++){
		if(digitSum(i)%17 == 0){
			count++;
		}
	}

	return count;
}

int digitSum(int n){
	int sum = 0;

	while(n){
		sum += n%10;
		sum/=10;
	}
	return sum;
}