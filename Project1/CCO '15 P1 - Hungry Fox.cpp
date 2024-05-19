#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

#define ll long long
const int N = 1e5 + 10;
ll n, w, c[N];

//���ڽ��й��������Ա�������С�Ĳ�ֵ����a[1] �� a[n]�Ĳ�ֵ
//����: 1 3 5 7 9
//��ֵΪ 2 + 2 + 2 + 2 = 9 - 1
//���1 ��� w �� 1-n �ķ�Χ�ڣ���ô����Ӱ����
//���2 ��� w �� 1-n С ��ô������� w-n �ľ���ֵ
//���3 ��� w �� 1-n �� ��ô������� 1-w �ľ���ֵ
ll getMin() { return max(w - c[1], 0ll) + max(c[n] - w, 0ll); }

//�����Ĳ�ֵ ���� 1-n + 2-(n-1)..... �Ĳ�ĺ�
//���������Ⱥȵ�ˮ��ô�ڸտ�ʼ��ʱ���ؾͻ������ֽ��
ll getMax()
{
	ll l = 1, r = n, res1 = 0, res2 = 0, last = w;
	for (int i = 1; i <= n; i++) // ����
	{
		if (i % 2)
			res1 += max(abs(c[l] - w), abs(c[l] - last)), last = c[l++];
		else
			res1 += max(abs(c[r] - w), abs(c[r] - last)), last = c[r--];
	}
	last = w, l = 1, r = n;
	for (int i = 1; i <= n; i++) // ����
	{
		if (i % 2)
			res2 += max(abs(c[r] - w), abs(c[r] - last)), last = c[r--];
		else
			res2 += max(abs(c[l] - w), abs(c[l] - last)), last = c[l++];
	}
	return max(res1, res2);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), w = rd();
	for (int i = 1; i <= n; i++) c[i] = rd();
	sort(c + 1, c + n + 1);
	cout << getMin() << ' ' << getMax();
	return 0;
}