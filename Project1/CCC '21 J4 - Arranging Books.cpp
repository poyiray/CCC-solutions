#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string shelf;
	cin >> shelf;
	int l_cnt = count(shelf.begin(), shelf.end(), 'L'),
		m_cnt = count(shelf.begin(), shelf.end(), 'M');

	int l_in_m = 0, l_in_s = 0, m_in_l = 0, m_in_s = 0;
	for (int i = 0; i < shelf.size(); i++) {
		if (i < l_cnt) {
			if (shelf[i] == 'M') m_in_l++;
		}
		else if (i < l_cnt + m_cnt) {
			if (shelf[i] == 'L') l_in_m++;
		}
		else {
			if (shelf[i] == 'L') l_in_s++;
			else if (shelf[i] == 'M') m_in_s++;
		}
	}
	cout << l_in_s + l_in_m + m_in_l + m_in_s - min(l_in_m, m_in_l) << '\n';
	return 0;
}