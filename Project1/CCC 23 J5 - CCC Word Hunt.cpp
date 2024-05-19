#include<iostream>
#include<string>
using namespace std;
const int maxn = 105;
string W;
int r, c, ans;
char s[maxn][maxn];
int dfs1(int x, int y, int idx) {//情况1：垂直向下查找 
	if (idx == W.size())return 1;
	if (x<1 || y<1 || x>r || y>c)return 0;
	if (s[x][y] != W[idx])return 0;
	return dfs1(x + 1, y, idx + 1);
}
int dfs2(int x, int y, int idx) {//情况2：垂直向上查找 
	if (idx == W.size())return 1;
	if (x<1 || y<1 || x>r || y>c)return 0;
	if (s[x][y] != W[idx])return 0;
	return dfs2(x - 1, y, idx + 1);
}
int dfs3(int x, int y, int idx) {//情况3：水平向右查找 
	if (idx == W.size())return 1;
	if (x<1 || y<1 || x>r || y>c)return 0;
	if (s[x][y] != W[idx])return 0;
	return dfs3(x, y + 1, idx + 1);
}
int dfs4(int x, int y, int idx) {//情况4：水平向左查找 
	if (idx == W.size())return 1;
	if (x<1 || y<1 || x>r || y>c)return 0;
	if (s[x][y] != W[idx])return 0;
	return dfs4(x, y - 1, idx + 1);
}
int dfs5(int x, int y, int idx, int sel) {//情况5：对角线查找
	if (idx == W.size())return 1;
	if (x<1 || y<1 || x>r || y>c)return 0;
	if (s[x][y] != W[idx])return 0;
	if (sel == -1) {//第一次查找，可以往4个方向 
		return dfs5(x - 1, y - 1, idx + 1, 1) + dfs5(x - 1, y + 1, idx + 1, 2) + dfs5(x + 1, y - 1, idx + 1, 3) + dfs5(x + 1, y + 1, idx + 1, 4);
	}
	switch (sel) {
	case 1:
		return dfs5(x - 1, y - 1, idx + 1, 1);
	case 2:
		return dfs5(x - 1, y + 1, idx + 1, 2);
	case 3:
		return dfs5(x + 1, y - 1, idx + 1, 3);
	case 4:
		return dfs5(x + 1, y + 1, idx + 1, 4);
	}
}
int dfs6(int x, int y, int idx, int sel, bool flag) {//情况6：先查找一段，再折90°查找 
	if (s[x][y] != W[idx])return 0;
	if (idx == W.size() - 1 && flag)return 1;
	if (idx == W.size() - 1)return 0;
	if (x<1 || y<1 || x>r || y>c)return 0;
	if (sel == -1) {//第一次查找，可以往8个方向 
		int t1 = dfs6(x - 1, y, idx + 1, 1, 0) + dfs6(x + 1, y, idx + 1, 2, 0) + dfs6(x, y - 1, idx + 1, 3, 0) + dfs6(x, y + 1, idx + 1, 4, 0);
		int t2 = dfs6(x - 1, y - 1, idx + 1, 5, 0) + dfs6(x - 1, y + 1, idx + 1, 6, 0) + dfs6(x + 1, y - 1, idx + 1, 7, 0) + dfs6(x + 1, y + 1, idx + 1, 8, 0);
		return t1 + t2;
	}
	switch (sel) {
	case 1:
		if (flag) {
			return dfs6(x - 1, y, idx + 1, 1, flag);
		}
		return dfs6(x - 1, y, idx + 1, 1, 0) + dfs6(x, y - 1, idx + 1, 3, 1) + dfs6(x, y + 1, idx + 1, 4, 1);
	case 2:
		if (flag) {
			return dfs6(x + 1, y, idx + 1, 2, flag);
		}
		return dfs6(x + 1, y, idx + 1, 2, flag) + dfs6(x, y - 1, idx + 1, 3, 1) + dfs6(x, y + 1, idx + 1, 4, 1);
	case 3:
		if (flag) {
			return dfs6(x, y - 1, idx + 1, 3, flag);
		}
		return dfs6(x, y - 1, idx + 1, 3, flag) + dfs6(x - 1, y, idx + 1, 1, 1) + dfs6(x + 1, y, idx + 1, 2, 1);
	case 4:
		if (flag) {
			return dfs6(x, y + 1, idx + 1, 4, flag);
		}
		return dfs6(x, y + 1, idx + 1, 4, flag) + dfs6(x - 1, y, idx + 1, 1, 1) + dfs6(x + 1, y, idx + 1, 2, 1);
	case 5:
		if (flag) {
			return dfs6(x - 1, y - 1, idx + 1, 5, flag);
		}
		return dfs6(x - 1, y - 1, idx + 1, 5, flag) + dfs6(x - 1, y + 1, idx + 1, 6, 1) + dfs6(x + 1, y - 1, idx + 1, 7, 1);
	case 6:
		if (flag) {
			return dfs6(x - 1, y + 1, idx + 1, 6, flag);
		}
		return dfs6(x - 1, y + 1, idx + 1, 6, flag) + dfs6(x - 1, y - 1, idx + 1, 5, 1) + dfs6(x + 1, y + 1, idx + 1, 8, 1);
	case 7:
		if (flag) {
			return dfs6(x + 1, y - 1, idx + 1, 7, flag);
		}
		return dfs6(x + 1, y - 1, idx + 1, 7, flag) + dfs6(x - 1, y - 1, idx + 1, 5, 1) + dfs6(x + 1, y + 1, idx + 1, 8, 1);
	case 8:
		if (flag) {
			return dfs6(x + 1, y + 1, idx + 1, 8, flag);
		}
		return dfs6(x + 1, y + 1, idx + 1, 8, flag) + dfs6(x - 1, y + 1, idx + 1, 6, 1) + dfs6(x + 1, y - 1, idx + 1, 7, 1);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> W >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			//对于以(i,j)开头的隐藏字符串 
			ans += dfs1(i, j, 0);
			ans += dfs2(i, j, 0);
			ans += dfs3(i, j, 0);
			ans += dfs4(i, j, 0);
			ans += dfs5(i, j, 0, -1);
			ans += dfs6(i, j, 0, -1, 0);
		}
	}
	cout << ans;
	return 0;
}