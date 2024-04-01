long long sumUpperTriangle(std::vector<int> arr){
	int n = arr.size();
	int sum = 0;

	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(j>=i){
				sum += static_cast<long long>(arr[i] * arr[j]);
			}
		}
	}

	return sum;
}