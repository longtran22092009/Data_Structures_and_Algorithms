#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll LINF = (ll) 1e18, MOD = (ll) 1e9+7;

bool cmp(pair <int, int> a, pair <int, int> b) {
    return a.first + a.second < b.first + b.second;
}

priority_queue <int> lq;
priority_queue <int, vector <int>, greater<int>> rq;
ll lsum, rsum;
ll pre[mxN];

void insert(int x) {
    int median = (lq.size() ? lq.top() : INF);

    if (x <= median) {
        lq.push(x);
        lsum += x;
    }
    else {
        rq.push(x);
        rsum += x;
    }

    if (rq.size() + 1 < lq.size()) {
        int tmp = lq.top(); 
        lq.pop();
        rq.push(tmp);
        lsum -= tmp;
        rsum += tmp;
    }
    else if (lq.size() < rq.size()) {
        int tmp = rq.top(); 
        rq.pop();
        lq.push(tmp);
        rsum -= tmp;
        lsum += tmp;
    }
}


void solve() {
    int k, n; cin >> k >> n;

    ll same_side = 0;
    vector <pair <int, int>> v;

    for (int i = 0; i < n; i++) {
        char a, b;
        int x, y;
        cin >> a >> x >> b >> y;
        if (a == b) same_side += abs(x - y);
        else v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);
    n = v.size();
    same_side += n;

    lsum = rsum = 0;
    for (int i = 0; i < n; i++) {
        insert(v[i].first);
        insert(v[i].second);
        pre[i] = rsum - lsum;
    }

    ll ans = pre[n-1];
    if (k == 2) {
        while (lq.size()) lq.pop();
        while (rq.size()) rq.pop();
        lsum = rsum = 0;

        for (int i = n-1; i >= 1; i--) {
            insert(v[i].first);
            insert(v[i].second);

            ans = min(ans, rsum - lsum + pre[i-1]);
        }
    }

    cout << same_side + ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin); 
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    // clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    // cerr << "Time: " << clock() - start << "ms\n";
}
