int stairsJump(int N, int M){
	//lets suppose that he jumps 2 stairs all the time and on the last stair he can jump either 1 or 2 stairs.
	// 1 <= M <= N

	if(M == N)
		return 0;

	//if he can jump 2 stairs => do it, else jump 1 if only one stair step left 
	if(M + 2 < N){
		return 2;
	}
	return 1;
}