#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <tuple>

//void print(std::vector<int>& v, int n) {
//	std::cout << n << '-';
//	for (int i = 0; i < v.size(); i++) {
//		std::cout << v[i] << ' ';
//	}
//	std::cout << '\n';
//}

void findDirections(int& maxi, int& mini) {
	//There are no loops in sequances

	std::unordered_map<int, std::vector<int>> directions;

	directions[1] = { 2, 5, 4 };
	directions[2] = { 3, 5, 4, 7 };
	directions[3] = { 6, 8 };
	directions[4] = { 5, 7 };
	directions[5] = { 6, 7 };
	directions[6] = { 8, 9 };
	directions[7] = { 8 };
	directions[8] = { 5, 9 };

	std::queue<std::tuple<int, std::vector<int>, std::vector<bool>>> q;
	std::vector<bool> used_stations(10, 0);

	q.push({ 1, {}, used_stations });

	mini = INT_MAX;
	maxi = INT_MIN;

	//There is loop in the route system. Maximum road length is INFINITE
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			auto temp = q.front();
			auto used = std::get<2>(temp);
			auto route = std::get<1>(temp);
			auto pos = std::get<0>(temp);
			q.pop();

			route.push_back(pos);
			used[pos] = true;

			//print(route, pos);

			if (pos == 9) {
				mini = std::min(mini, (int)route.size());
				maxi = std::max(maxi, (int)route.size());
			}
			else {
				for (int j = 0; j < directions[pos].size(); j++) {
					if (used[directions[pos][j]] == false) {

						used[directions[pos][j]] = true;
						q.push({ directions[pos][j], route, used});
						used[directions[pos][j]] = false;
					}
				}
			}

		}
		//std::cout << '\n';
	}

	return;
}

int main()
{
	int mini = 0, maxi = 0;

	findDirections(maxi, mini);
	std::cout << maxi << ' ' << mini << '\n';

	
}
