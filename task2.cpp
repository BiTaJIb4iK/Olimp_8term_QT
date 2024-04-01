/*int minimum_distance_shopping(int d1, int d2, int d3){
	//shop and home are position x {1, 2, 3};
	//home 3 shop 1, shop 2.
	//each point n connectes 2 roads r1, r2 != n ; shop 2 and shop 1 are connected with road d3; home 3 has two roads d1 and d2;
	//max moves is 4 to visit all the shops and come back home;
	int mini = INT_MAX;

	travel(3, 0, false, false, d1, d2, d3, mini);

	return mini;
}

int travel(int pos, int moves, bool visited_shop1, bool visited_shop2, int d1, int d2, int d3, int& mini){
	if(moves)
}*/


long long minimumDistanceShopping(int d1, int d2, int d3){
	//hard code it
	long long mini = LLONG_MAX;

	//go shop shop home
	mini = std::min(mini, (long long)d1 + d2 + d3);

	//go shop1 shop2 shop1 home
	mini = std::min(mini, (long long)(d1 + d3) * 2);

	//other way around shop shop shop home
	mini = std::min(mini, (long long)(d2 + d3) * 2);

	//go shop home shop home
	mini = std::min(mini, (long long)(d1 + d2) * 2);

	return mini;
}
