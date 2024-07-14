#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

typedef struct BST
{
	int x, cnt, h, size;
	BST *l, *r;
}*tree;

tree root = NULL;

inline int Height(tree t) { return t ? t->h : 0; };
inline int Size(tree t) { return t ? t->size : 0; };
void update(tree t)
{
	if (!t) return;
	t->h = max(Height(t->l), Height(t->r)) + 1;
	t->size = Size(t->l) + Size(t->r) + t->cnt;
}

tree RR(tree t)
{
	tree temp = t->r;
	t->r = temp->l;
	temp->l = t;
	update(t);
	update(temp);
	return temp;
}

tree LL(tree t)
{
	tree temp = t->l;
	t->l = temp->r;
	temp->r = t;
	update(t);
	update(temp);
	return temp;
}

tree RL(tree t)
{
	t->r = LL(t->r);
	return RR(t);
}

tree LR(tree t)
{
	t->l = RR(t->l);
	return LL(t);
}

tree adjust(tree t)
{
	if (!t) return t;
	if (Height(t->r) - Height(t->l) >= 2)
	{
		if (Height(t->r->r) >= Height(t->r->l)) return RR(t);
		else return RL(t);
	}
	if (Height(t->l) - Height(t->r) >= 2)
	{
		if (Height(t->l->l) >= Height(t->l->r)) return LL(t);
		else return LR(t);
	}
	return t;
}

void ins(tree &t, int x)
{
	if (!t)
	{
		t = new BST;
		t->h = t->cnt = t->size = 1;
		t->x = x;
		t->l = t->r = NULL;
		return;
	}
	
	if (x < t->x) ins(t->l, x);
	else if (x > t->x) ins(t->r, x);
	else if (x == t->x) t->cnt++, t->size++;
	update(t);
	t = adjust(t);
}

void del(tree &t, int x)
{
	if (!t) return;
	if (t->x == x)
	{
		if (t->cnt > 1) { t->cnt--, t->size--; return; }
		if (!t->r)
		{
			tree temp = t;
			t = t->l;
			delete temp;
		}
		else
		{
			tree temp = t->r;
			while (temp->l) temp = temp->l;
			t->x = temp->x;
			t->cnt = temp->cnt;
			temp->cnt = 1;
			del(t->r, t->x);
		}
	}
	else if (x < t->x) del(t->l, x);
	else if (x > t->x) del(t->r, x);
	update(t);
	t = adjust(t);
}

void ldr(tree t)
{
	if (!t) return;
	ldr(t->l);
	for (int i = 1; i <= t->cnt; i++) cout << t->x << " ";
	ldr(t->r);
}

int getrank(int x)
{
	int rank = 1; tree k = root;
	while (k)
	{
		if (x < k->x) k = k->l;
		else if(x > k->x)
		{
			rank += Size(k->l) + k->cnt;
			k = k->r;
		}
		else return Size(k->l) + rank;
	}
	return -1;
}

int getnum(int rank)
{
	tree k = root;
	while (k)
	{
		if (rank > Size(k->l) + k->cnt)
		{
			rank -= Size(k->l) + k->cnt;
			k = k->r;
		}
		else if (rank <= Size(k->l)) k = k->l;
		else return k->x;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n = rd(), m = rd();
	for (int i = 1; i <= n; i++)
	{
		int x = rd();
		ins(root, x);
	}

	int last = 0;
	while (m--)
	{
		char opt = getchar(); getchar(); int x = rd();
		if (opt == 'I') ins(root, x ^ last);
		else if (opt == 'R') del(root, x ^ last);
		else if (opt == 'S')
		{
			last = getnum(x ^ last);
			cout << last << '\n';
		}
		else if (opt == 'L')
		{
			last = getrank(x ^ last);
			cout << last << '\n';
		}
	}
	ldr(root);
	return 0;
}