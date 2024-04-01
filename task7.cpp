std::string intToHex(int n){
	std::string result;

	bool negative = false;

	if(n<0){
		n *= -1;
		negative = true;
	}

	char c = 0;
	int digit = 0;

	while(n){
		digit = n % 16;
		n /= 16;
		c = 0;

		switch(digit){
		case 10:
			c = 'A';
			break;
			
		case 11:
			c = 'B';
			break;
			
		case 12:
			c = 'C';
			break;
			
		case 13:
			c = 'D';
			break;

		case 14:
			c = 'E';
			break;

		case 15:
			c = 'F';
			break;
		default:
			c= std::to_string(digit);
			break;
		}
		result.push_back(c);
	}

	if(negative)
		result.push_back('-');

	std::reverse(result.begin(), result.end());

	return result;
}