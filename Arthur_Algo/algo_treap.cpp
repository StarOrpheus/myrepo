struct item {
    int x;
    int y;
    int l;
    int r;
    int k;
};

item t[300300];

void init(int v, int x) {
    t[v].x = x;
    t[v].y = rand();
    t[v].l = t[v].r = 0;
    t[v].k = !!v;
}

void upd_cnt(int v) {
    t[v].k = (v == 0) ? 0 : t[t[v].l].k + t[t[v].r].k + 1;
}

void merge(int &v, int l, int r) {
    if (!l || !r) {
        v = l ? l : r;
    } else if (t[l].y > t[r].y) {
        v = l;
        merge(t[l].r, t[l].r, r);
    } else {
        v = r;
        merge(t[r].l, l, t[r].l);
    }
    upd_cnt(v);
}

void split(int v, int &l, int &r, int key) {
    if (!v) {
        l = r = 0;
        return;
    }
    if (t[t[v].l].k + 1 <= key) {
        l = v;
        split(t[v].r, t[l].r, r, key - t[t[v].l].k - 1);
    } else {
        r = v;
        split(t[v].l, l, t[r].l, key);
    }
    upd_cnt(l);
    upd_cnt(r);
}
