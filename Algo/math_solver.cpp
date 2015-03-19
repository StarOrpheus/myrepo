struct ds{
    int F;
    int S;
    bool div = false;
};

ds md (int f, int s) {
    ds r;
    r.F = f;
    r.S = s;
    return r;
}

ds md (int f, int s, bool div) {
    ds r;
    r.F = f;
    r.S = s;
    r.div = div;
    return r;
}

int solve (string &s) {
    stack<ds> st;
    st.push(md(0, 0));
    int b = -1;
    int x;
    int i = 0;
    bool divs = false;
    while (i < s.size()) {
        if (i == b + 1) {
            if (s[i] == '(') st.top().F = 1;
            else if (s[i] != '-' && s[i] != '+') {
                if (!isdigit(s[i])) {
                    cout << "unexpected symbol " << s[i] << " at position " << i << ": " << s << endl;
                    return 0;
                }
                x = 0;
                while (i < s.size() && isdigit(s[i])) {
                    x = (x * 10) + s[i] - '0';
                    i++;
                }
                st.top().F = x;
                continue;
            }
        }
        if (s[i] == ')') {
            if (b + 1 == i) {
                cout << "empty brackets at position " << i << ": " << s << endl;
                return 0;
            }
            x = st.top().F + st.top().S;
            divs = st.top().div;
            st.pop();
            if (!st.size()) {
                cout << "redundant closing bracket at position " << i << ": " << s << endl;
                return 0;
            }
            if (divs) {
                if (!x || st.top().F % x) {
                    cout << "not divisible by " << x << " at position " << i << ": " << s << endl;
                    return 0;
                }
                st.top().F /= x;
            } else st.top().F *= x;
            divs = false;
            i++;
            continue;
        }
        if (s[i] == '(') {
            b = i;
            st.push(md(0, 0, divs));
            divs = false;
            i++;
            continue;
        }
        if (s[i] == '-') {
            st.top().S += st.top().F;
            if (i + 1 == s.size()) {
                cout << "unexpected end: " << s << endl;
                return 0;
            }
            if (s[i+1] == '(') {
                st.top().F = -1;
                i++;
                continue;
            }
            if (!isdigit(s[i+1])) {
                cout << "unexpected symbol " << s[i+1] << " at position " << i + 1 << ": " << s << endl;
                return 0;
            }
            x = 0;
            while (++i < s.size() && isdigit(s[i])) {
                x = (x * 10) + s[i] - '0';
            }
            st.top().F = -x;
            continue;
        }
        if (s[i] == '+') {
            st.top().S += st.top().F;
            if (i + 1 == s.size()) {
                cout << "unexpected end: " << s << endl;
                return 0;
            }
            if (s[i+1] == '(') {
                st.top().F = 1;
                i++;
                continue;
            }
            if (!isdigit(s[i+1])) {
                cout << "unexpected symbol " << s[i+1] << " at position " << i + 1 << ": " << s << endl;
                return 0;
            }
            x = 0;
            while (++i < s.size() && isdigit(s[i])) {
                x = (x * 10) + s[i] - '0';
            }
            st.top().F = x;
            continue;
        }
        if (s[i] == '*') {
            if (i + 1 == s.size()) {
                cout << "unexpected end: " << s << endl;
                return 0;
            }
            if (s[i+1] == '(') {
                i++;
                continue;
            }
            if (!isdigit(s[i+1])) {
                cout << "unexpected symbol " << s[i+1] << " at position " << i + 1 << ": " << s << endl;
                return 0;
            }
            x = 0;
            while (++i < s.size() && isdigit(s[i])) {
                x = (x * 10) + s[i] - '0';
            }
            st.top().F *= x;
            continue;
        }
        if (s[i] == '/') {
            if (i + 1 == s.size()) {
                cout << "unexpected end: " << s << endl;
                return 0;
            }
            if (s[i+1] == '(') {
                divs = true;
                i++;
                continue;
            }
            if (!isdigit(s[i+1])) {
                cout << "unexpected symbol " << s[i+1] << " at position " << i + 1 << ": " << s << endl;
                return 0;
            }
            x = 0;
            while (++i < s.size() && isdigit(s[i])) {
                x = (x * 10) + s[i] - '0';
            }
            if (!x || st.top().F % x) {
                cout << "not divisible by " << x << " at position " << i-1 << ": " << s << endl;
                return 0;
            }
            st.top().F /= x;
            continue;
        }
    }
    if (st.size() != 1) {
        cout << "incorrect brackets: " << s << endl;
        return 0;
    }
    return st.top().F + st.top().S;
}
