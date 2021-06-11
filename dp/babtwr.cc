#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main(void) {
	int n;
	while (cin >> n) {
		if (!n) break;

		vector<tuple<int, int, int>> v;
		while (n--) {
			int x,y,z;
			cin >> x >> y >> z;
			v.push_back({x,y,z}); v.push_back({x,z,y});
			v.push_back({y,z,x}); v.push_back({y,x,z});
			v.push_back({z,x,y}); v.push_back({z,y,x});
		}
		sort(v.begin(), v.end());

		// DP
		vector<int> best(v.size(), 0);
		int top = 0;
		for (int i = 0; i < best.size(); i++) {
			for (int j = 0; j < i; j++)
				if (get<0>(v[j]) < get<0>(v[i]) && get<1>(v[j]) < get<1>(v[i]))
					best[i] = max(best[i], best[j]);
			best[i] += get<2>(v[i]);
			if (best[i] > top) 
				top = best[i];
		}
		cout << top << endl;
	}
	return 0;
}