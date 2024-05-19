//�Ƚ��ѵ�һ���� ��Ҫ˼·�����ҳ�һ������������������ ������k��¼��ͷi��¼��β(˫ָ��)
//֮��� j ���е��� ���ҵ��� k ָ�������һ�����±��ʱ�� ���� j �� [k,i] �����λ�ý��в�ͬ�Ĳ���
//��� j > i ��ôֻҪ ��ʵֻҪ ʹ�� L [k,j] ���� ����Ҫ�� i �����κβ��� ͬʱ������������ȼ��ǵ͵� ��Ϊ��Ҫȷ��֮ǰ�Ĳ����ȱ�ִ�� �����Ų��Ḳ�ǵ�֮ǰ����ֵ
//��� j < k ֻҪ ʹ�� R [j, i] ���� ͬʱΪ�˱�֤ j ���ڵ���ֵ ����֮ǰ�Ĳ��������� �������������������ȼ�
//��� j ���� [k,j] ���ʱ��ֻ��Ҫ L [k, j] + R [j, i] ��������������ᱻ֮ǰ�Ĳ���Ӱ�� ֱ��ʹ��push_back
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

const int N = 4e5;

struct RES
{
	char c;
	int l, r;
};

int a[N], b[N], n, i, j, k;
deque<RES> res;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for (int i = 0; i < n; i++) a[i] = rd();
	for (int i = 0; i < n; i++) b[i] = rd();

	while (i < n)
	{
		while (b[i] == b[k] && i < n) i++; i--;
		while (b[k] != a[j] && j < n) j++;
		if (j >= n) { cout << "NO"; return 0; }
		if (j > i)
		{
			res.push_back({ 'L', k, j });
		}
		else if(j < k)
		{
			res.push_front({ 'R', j, i });
		}
		else if (j >= k && j <= i)
		{
			if(k != j) res.push_back({ 'L', k, j });
			if(j != i) res.push_back({ 'R', j, i });
		}
		k = ++i;
	}
	cout << "YES\n" << res.size() << '\n';
	for (auto& ans : res)
		cout << ans.c << " " << ans.l << " " << ans.r << '\n';

	return 0;
}