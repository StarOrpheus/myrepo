class mqueue {
public:
    int getmax () {
        if (s1.empty()) return s2.top().S;
        if (s2.empty()) return s1.top().S;
        return max(s1.top().S, s2.top().S);
    }

    void push (int x) {
        s2.push(mp(x, s2.empty() ? x : max(x, s2.top().S)));
    }

    void pop () {
        if (s1.empty()) {
            int x = s2.top().F;
            while (!s2.empty()) {
                s1.push(mp(s2.top().F, (x=max(x, s2.top().F))));
                s2.pop();
            }
        }
        s1.pop();
    }

    void clear() {
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
    }

    int size() {
        return s1.size() + s2.size();
    }
private:
    stack<pair<int,int> > s1;
    stack<pair<int,int> > s2;
};
