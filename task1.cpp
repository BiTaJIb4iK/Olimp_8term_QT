int DmutroLossesCalculation(int N){
	/*
	0 <= N <= 1018

	d-
	d-
	n
	d+
	d-
	n
	d+

	loop
	d-
	n
	d+
	*/
	int losses = 0;

	//check for prelooped sequence
	if(N<7){
		losses += 3;
	}else if(N < 2){
		losses += N;
	}

	//remove preloop
	N -= 7;

	//calculate losses for each 3 games placed in a loop
	if(N > 0){
		losses += N / 3;
		N%=3;
	}

	//calculate losses for last incomplete loop
	if(N>0){
		losses++;
	}

	return losses;
}