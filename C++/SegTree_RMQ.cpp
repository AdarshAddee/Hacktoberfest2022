#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    struct SegTree {
        int l, r;
        int val;
    };
    constexpr int inf = 0x3f3f3f3f;
    vector<SegTree> tr(n << 2);
    function<void(SegTree &, SegTree, SegTree)> push_up = [&] (SegTree &root, SegTree ls, SegTree rs) {
        root.val = min(ls.val, rs.val);
    };
    function<void(int, int, int)> build = [&] (int root, int l, int r) {
        tr[root].val = inf;
        tr[root].l = l, tr[root].r = r;
        if (l == r) return tr[root].val = w[l], void();
        int mid = l + r >> 1;
        build(root << 1, l, mid); build(root << 1 | 1, mid + 1, r);
        push_up(tr[root], tr[root << 1], tr[root << 1 | 1]);
    };
    function<int(int, int, int)> query = [&] (int root, int l, int r) {
        if (l <= tr[root].l && tr[root].r <= r) 
            return tr[root].val;
        int res = inf;
        if (tr[root << 1].r >= l) res = min(res, query(root << 1, l, r));
        if (tr[root << 1 | 1].l <= r) res = min(res, query(root << 1 | 1, l, r));
        return res;
    };
    build(1, 1, n);
    int m; cin >> m;
    while (m -- ) {
        int l, r; cin >> l >> r;
        cout << query(1, l, r) << "\n";
    }
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; cin >> T;
    while (T -- ) solve();
    return 0;
}