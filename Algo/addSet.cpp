template<typename T, T null_val>
class MemeSet
{
private:

	struct Treap
	{
		Treap* l = nullptr;
		Treap* r = nullptr;

		T x;
		T add = null_val;
		int p;
		int cnt = 1;

		Treap() : p(rand()) {}
		Treap(T x) : x(x), p(rand()) {}
	};

	Treap*	__data;
	int 	__dptr = 0;
	Treap* 	root = nullptr;

	int sizeOf(Treap* v)
	{
		if (v == nullptr) return 0;

		return v->cnt;
	}

	void cnt(Treap* v)
	{
		if (v == nullptr) return;

		if (v->add != null_val)
		{
			v->x += v->add;
			if (v->l != nullptr)
				v->l->add += v->add;
			if (v->r != nullptr)
				v->r->add += v->add;
			v->add = null_val;
		}

		v->cnt = sizeOf(v->l) + sizeOf(v->r) + 1;
	}

	Treap* newTreap()
	{
		if (sizeof(__data) / sizeof (Treap) == __dptr)
		{
			Treap* nw = new Treap[int(__dptr * 1.5)];
			memcpy(nw, __data, sizeof(__data));
			delete[] __data;
			__data = nw;
		}

		return __data + __dptr++;
	}

	Treap* merge(Treap* l, Treap* r)
	{
		if (l == nullptr) return r;
		if (r == nullptr) return l;

		cnt(l);
		cnt(r);

		if (l->p > r->p)
		{
			l->r = merge(l->r, r);
			cnt(l);
			return l;
		} else 
		{
			r->l = merge(l, r->l);
			cnt(r);
			return r;
		}
	}

	pair<Treap*, Treap* > split(Treap* v, T key)
	{
		if (v == nullptr) return mkp(nullptr, nullptr);

		cnt(v);

		if (v->x <= key)
		{
			pair<Treap*, Treap* > spl = split(v->r, key);
			v->r = spl.F;
			spl.F = v;
			
			cnt(spl.F);
			cnt(spl.S);

			return spl;
		} else 
		{
			pair<Treap*, Treap* > spl = split(v->l, key);
			v->l = spl.S;
			spl.S = v;
			
			cnt(spl.F);
			cnt(spl.S);

			return spl;
		}
	}

	template<typename a, a b>
	friend ostream& operator<<(ostream& out, MemeSet<a, b>& st);

public:

	inline void inc(T val)
	{
		if (root != nullptr)
			root->add += val;
	}

	inline void insert(T x)
	{
		Treap* p = newTreap();
		p->x = x;

		pair<Treap*, Treap* > spl = split(root, x);
		root = merge(merge(spl.F, p), spl.S);
	}

	void print(ostream& out, Treap* v)
	{
		if (v == nullptr) return;

		print(out, v->l);
		out << v->x << " ";
		print(out, v->r);
	}

	MemeSet(int preserve_size = 2) 
	{
		__data = new Treap[preserve_size];
	}

	~MemeSet()
	{
		delete[] __data;
	}
};

template<typename T, T null_val>
ostream& operator<<(ostream& out, MemeSet<T, null_val>& st)
{
	st.print(out, st.root);
	return out;
}
