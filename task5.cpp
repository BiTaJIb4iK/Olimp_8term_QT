std::string floatToTheBoat(x, y, x1, y1, x2, y2){
	std::pair<float, float> TL, TR, BL, BR;
	BL.first = x1;
	BL.second = y1;

	TR.first = x2;
	TR.second = y2;

	TL.first = BL.first;
	TL.second = TR.second;

	BR.first = TR.first;
	BR.second = BL.second;


	std::pair<float, float> swimmer = {x, y};

	float dist[8] = {
		findDistance(swimmer, BL),
		findDistance(swimmer, BR),
		findDistance(swimmer, TR),
		findDistance(swimmer, TL),

		findDistance(swimmer, findCenterTwoPoints(TL, TR)),
		findDistance(swimmer, findCenterTwoPoints(BR, TR)),
		findDistance(swimmer, findCenterTwoPoints(BL, BR)),
		findDistance(swimmer, findCenterTwoPoints(BL, TL))
	}



	switch(std::min_element(dist, dist + 8) - dist){
		case 0:
			return "South-West";
			break;
		case 1:
			return "South-East";
			break;
		case 2:
			return "North-East";
			break;
		case 3:
			return "North-West";
			break;
		case 4:
			return "North";
			break;
		case 5:
			return "East";
			break;
		case 6:
			return "South";
			break;
		case 7:
			return "West";
			break;
	}

	return "Error";

}

float findDistance(std::pair<float, float>& p1, std::pair<float, float>& p2){
	return std::sqrt(std::pow(p2.first - p1.first, 2) + std::pow(p2.second - p1.second));
}


std::pair<float, float> findCenterTwoPoints(std::pair<float, float>& p1, std::pair<float, float>& p2){
	return {(p1.first + p2.first)/2, (p1.second + p2.second)/2};
}