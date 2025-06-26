#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


const int mxN = 100005, INF = (int) 1e9+5;
map <string, int> idx = {{"noun", 0}, {"intransitive-verb", 1}, {"transitive-verb", 2}, {"conjunction", 3}};

void solve() {
    // 1. noun + intransitive verbs -> 1n + 1iv
    // 2. noun + transitive verbs + noun(s) -> 1n + 1v + Nn(s)
    int N, C, P; cin >> N >> C >> P;
    // Maximum number of sentence are min(C, P)
    vector <vector <string>> words(4); // {noun, intransitive, transitive, conjunction}
    for (int i = 1; i <= N; i++) {
        string s, type; cin >> s >> type;
        words[idx[type]].push_back(s);
    }

    // x: type 1, y: type 2
    int mxx = -1, mxy = -1, mxw = 0;
    int sentence = P + min(P, (int) words[3].size());

    for (int x = 0; x <= (int) min(words[0].size(), words[1].size()); x++) {
        for (int y = 0; y <= (int) min(words[0].size()/2, words[2].size()); y++) {
            if (x+y > sentence) continue; // Too much sentences for the period or the conjunction that we have
            if (((x + 2 * y) + x + y) <= mxw) continue; // Less word than another way
            // Do not have enough words
            if((int) words[0].size() < (x+2*y) || (int) words[1].size() < x || (int) words[2].size() < y) continue;
            mxx = x;
            mxy = y;
            mxw = ((x + 2 * y) + x + y);
        }
    }

    int numberOfWord = (mxx + 2 * mxy) + mxx + mxy;
    int useConjunction = min((int) words[3].size(), (mxx + mxy)/2);
    int moreNoun = min(C, (int) words[0].size() - (mxx + 2 * mxy));
    // Remain noun will add after a type 2 sentence
    if (mxy > 0) numberOfWord += moreNoun; 
    // Conjunction in use
    numberOfWord += useConjunction; 
    // cout << sentence << " " << mxx << " " << mxy << endl;
    if (numberOfWord <= 0) {
        cout << "0\n\n";
        return;
    }
    cout << numberOfWord << endl;

    int ni = 0, ivi = 0, tvi = 0, ci = 0;
    bool combine = false;
    for (int i = 1; i <= mxx+mxy; i++) {
        if (i != 1) cout << " ";
        if (i <= mxx) { // Type 1
            cout << words[0][ni++] << " " << words[1][ivi++];
            if (ci < useConjunction && !combine) { // Still remain conjunction
                cout << " " << words[3][ci++]; // a conjunction b.
                combine = true;
            }
            else {
                cout << "."; // a. b.
                combine = false;
            }
        }

        else { // Type 2
            cout << words[0][ni++] << " " << words[2][tvi++] << " " << words[0][ni++];
            if (ci < useConjunction && !combine) { // Still remain conjunction
                cout << " " << words[3][ci++]; // a conjunction b.
                combine = true;
            }
            else {
                if (i == mxx+mxy) for (int j = 1; j <= moreNoun; j++) cout << ", " << words[0][ni++];
                cout << "."; // a. b.
                combine = false;
            }
        }
    }
    cout << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t; cin >> t;
    while (t--)
        solve();
}
