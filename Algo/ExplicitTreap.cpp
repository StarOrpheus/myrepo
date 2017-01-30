#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define mkp(a, b) make_pair(a, b)

class Treap
{
public:
	Treap* l = nullptr;
	Treap* r = nullptr;
	int key;
	int prior;
	int cnt = 1;

	Treap() {}
	Treap(int x) : key(x), prior(rand()) {};
};

int sizeOf(Treap* res)
{
    return (res == nullptr ? 0 : res->cnt);
}

void cnt(Treap* res)
{
    if(res == nullptr) return;
	res->cnt = sizeOf(res->l) + sizeOf(res->r) + 1;
}

Treap* merge(Treap* L, Treap* R)
{
	if(L == nullptr) return R;
	if(R == nullptr) return L;

	cnt(L);
	cnt(R);

	if(L->prior >= R->prior)
	{
		L->r = merge(L->r, R);
		cnt(L);
		return L;
	}
	else
	{
		R->l = merge(L, R->l);
		cnt(R);
		return R;
	}
}

pair<Treap*, Treap*> split(Treap* res, int key)
{
	if(res == nullptr) return mkp(nullptr, nullptr);

	if(sizeOf(res->l) <= key)
	{
		pair<Treap*, Treap*> rightSplit = split(res->r, key - sizeOf(res->l) - 1);
		res->r = rightSplit.F;
		rightSplit.F = res;
		cnt(rightSplit.F);
		cnt(rightSplit.S);
		return rightSplit;
	}
	else
	{
		pair<Treap*, Treap*> leftSplit = split(res->l, key);
		res->l = leftSplit.S;
		leftSplit.S = res;
		cnt(leftSplit.F);
		cnt(leftSplit.S);
		return leftSplit;
	}
}

Treap* add(Treap* root, int key, int pos)
{
	pair<Treap*, Treap*> spl = split(root, pos-1);
	spl.F = merge(spl.first, new Treap(key));
	return merge(spl.first, spl.second);
}

int get(Treap*& root, int pos)
{
	auto spl = split(root, pos);
	cerr << "# " << sizeOf(spl.F) << ":" << sizeOf(spl.S) << endl;
    if(sizeOf(spl.F) == 1)
    {
        int res = spl.F->key;
        root = merge(spl.F, spl.S);
        return res;
    }

	auto leftSpl = split(spl.F, pos-1);
	int result;

	result = leftSpl.S->key;

	root = merge(merge(leftSpl.F, leftSpl.S), spl.S);
	return result;
}

void printTreap(Treap* res)
{
    if(res == nullptr) return;

    printTreap(res->l);
    cerr << res->key << " ";
    printTreap(res->r);
}

int main()
{
	Treap* res = nullptr;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		res = add(res, x, i);

//	    printTreap(res);
//	    cerr << endl;
	}

    for(int i = 0; i < n; i++)
        cerr << get(res, i) << endl;
	return 0;
}
