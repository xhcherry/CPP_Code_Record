#include<iostream>
#include<map>
#include<vector>
using namespace std;
bool isHu(map<int, int> mp, int num) {
	if (num <= 0)return true;
	while (mp[mp.begin()->first] == 0)mp.erase(mp.begin());
	map<int, int>::iterator it = mp.begin();
	if (num % 3 != 0 && (it->second) >= 2) {
		mp[it->first] -= 2;
		if (isHu(mp, num - 2))return true;
		mp[it->first] += 2;
	}
	if ((it->second) >= 3) {
		mp[it->first] -= 3;
		if (isHu(mp, num - 3))return true;
		mp[it->first] += 3;
	}
	if ((it->second) > 0 && mp[(it->first) + 1] > 0 && mp[(it->first) + 2] > 0) {
		mp[it->first]--;
		mp[(it->first) + 1]--;
		mp[(it->first) + 2]--;
		if (isHu(mp, num - 3))return true;
		mp[(it->first)]++;
		mp[(it->first) + 1]++;
		mp[(it->first) + 2]++;
	}
	return false;
}
int main() {
	map<int, int> mp;
	int tmp;
	for (int i = 0; i < 13; i++) {
		cin >> tmp;
		mp[tmp]++;
	}
	vector<int> ans;
	for (int i = 1; i < 10; i++) {
		if (mp[i] < 4) {
			++mp[i];
			if (isHu(mp, 14))
				ans.push_back(i);
			--mp[i];
		}
	}
	if (ans.empty())cout << 0 << endl;
	else {
		for (int i : ans)cout << i << ' ';
	}

	return 0;
}

