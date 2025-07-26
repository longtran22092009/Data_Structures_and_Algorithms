#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"
#define DEBUG "debug.out"


const int mxN = 100005, INF = (int) 1e9+5;
const ll MOD = (ll) 1e9+7, LINF = (ll) 1e18;

int n, m;
vector <vector <pair <int, int>>> adj(mxN);
vector <ll> d(mxN, LINF);
ll mnCnt = 0, mxFlight = -1, mnFlight = LINF;

void Dijkstra(int s) {
    vector <ll> d(mxN, LINF), mxFlight(mxN, -1), mnFlight(mxN, LINF), mnCnt(mxN, 0);
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater<>> q;
    q.push({0, s});
    d[s] = 0;
    mnCnt[s] = 1;
    mnFlight[s] = 0;
    mxFlight[s] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        ll dis = q.top().first;
        q.pop();

        if (dis > d[u]) continue;
        for (auto &x : adj[u]) {
            int v = x.first, w = x.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});

                mnCnt[v] = mnCnt[u]; // Using path through u no longer v
                mnFlight[v] = mnFlight[u] + 1; // From u to v
                mxFlight[v] = mxFlight[u] + 1; // From u to v
            }
            else if (d[v] == d[u] + w) {
                // Both path valid so total we have d[v] and d[u] ways for the first ans second
                mnCnt[v] = (mnCnt[v] + mnCnt[u]) % MOD;
                // We can choose to go with current path through v or new path through u
                mnFlight[v] = min(mnFlight[v], mnFlight[u] + 1);
                mxFlight[v] = max(mxFlight[v], mxFlight[u] + 1);
            }
        }
    }
    
    cout << d[n] << " " << mnCnt[n] << " " << mnFlight[n] << " " << mxFlight[n] << endl; 
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    Dijkstra(1);  
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen(DEBUG, "w", stderr);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    clock_t start = clock();

    // ll t; cin >> t;
    // while (t--)
    solve();
    cerr << "Time: " << clock() - start << "ms\n";
}
