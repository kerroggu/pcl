#include "../codes/header.hpp"

int T;
int b;

template <class T>
void tell(T x) {
    dump(x);
    cout << x << endl;
    fflush(stdout);
}

int judge_case(string a) {
    dump(a);
    for (int cnt = 1; cnt <= 150; cnt++) {
        if (cnt % 10 == 1) {
            reverse(all(a));
        }

        string query;
        cin >> query;
        if (sz(query) != b) {
            tell(a[stoi(query) - 1]);
        } else {
            if (query == a) {
                tell("Y");
                return 0;
            } else {
                tell("N");
                dump("judge-ans", a);
                dump("contestant-ans", query);
                throw("WA");
            }
        }
        cnt += 1;
    }
    throw("query's limit exceeded");
}

signed main() {
    // input case
    cin >> T >> b;
    tell(T);
    tell(b);
    vector<string> A(T);
    rep(t, T) { cin >> A[t]; }

    // judge
    rep(i, T) { judge_case(A[i]); }

    // TODO: check contestant code is continuing to needles queries.
    return 0;
}
