/* gen.cpp */
#include <bits/stdc++.h>
using namespace std;

//====== BITWISE ======//
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ON(x, i) ((x) | MASK(i))
#define OFF(x, i) ((x) & ~MASK(i))
#define LASTBIT(mask) ((mask) & -(mask))
#define SUBMASK(sub, mask) for (int sub = (mask); sub >= 1; sub = (sub - 1) & (mask))

//====== MISC ======//
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

#define fi first
#define se second
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define compress(c) sort(all(c)); c.erase(unique(all(c)), c.end());
#define Longgggg ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)

//====== FILE ======//
const string MAIN  = "main";
const string BRUTE = "brute";
//==================//

const int NTEST = 1000;
const int NTYPE = 5;

// -1: chạy random nhiều test
// seed cụ thể: chạy lại đúng test WA
const ll ONLY_SEED = -1;
mt19937_64 rng;

ll Rand(ll L, ll R) {
    assert(L <= R);
    return uniform_int_distribution<ll>(L, R)(rng);
}

void genTest(int type) {
    ofstream inp("input.txt");

    // =========================
    // CODE SINH TEST Ở ĐÂY
    // =========================

    inp.close();
}

bool checkTest() {
    return (system(("fc /W " + MAIN + ".out " + BRUTE + ".out > nul").c_str()) == 0);
}

/*
    Dùng khi output không duy nhất.

    Ví dụ:
    - main in một hoán vị hợp lệ
    - main in một đường đi bất kỳ
    - main in một nghiệm bất kỳ

    Khi đó không dùng fc trực tiếp, mà tự đọc input.txt, main.out, brute.out rồi check.
*/
bool generalCheckTest() {
    ifstream inp("input.txt");
    ifstream out(MAIN + ".out");
    ifstream ans(BRUTE + ".out");

    // Viết checker ở đây nếu cần.
    return true;
}

int main() {
    Longgggg;
    ull baseSeed = chrono::steady_clock::now().time_since_epoch().count();

    if (ONLY_SEED != -1) baseSeed = ONLY_SEED;
    cout << "baseSeed = " << baseSeed << endl;

    FOR(tc, 1, NTEST) {
        ull seed;

        if (ONLY_SEED != -1) seed = ONLY_SEED;
        else seed = baseSeed + tc;

        rng.seed(seed);
        int type = seed % NTYPE;
        genTest(type);

        cout << "TEST " << tc << " (seed = " << seed << ", type = " << type << "):\n";
        int code1 = system((MAIN + ".exe < input.txt > " + MAIN + ".out").c_str());
        int code2 = system((BRUTE + ".exe < input.txt > " + BRUTE + ".out").c_str());

        if (code1 != 0) {
            cout << "MAIN RUNTIME ERROR\n";
            system("copy input.txt bad.inp > nul");

            cout << "\nINPUT:\n";
            system("type input.txt");

            return 0;
        }

        if (code2 != 0) {
            cout << "BRUTE RUNTIME ERROR\n";
            system("copy input.txt bad.inp > nul");

            cout << "\nINPUT:\n";
            system("type input.txt");

            return 0;
        }

        bool ok = checkTest();
        // bool ok = generalCheckTest();

        if (!ok) {
            cout << "WRONG ANSWER\n";
            system("copy input.txt bad.inp > nul");

            cout << "\nINPUT:\n";
            system("type input.txt");

            cout << "\nMAIN:\n";
            system(("type " + MAIN + ".out").c_str());

            cout << "\nBRUTE:\n";
            system(("type " + BRUTE + ".out").c_str());

            return 0;
        }

        cout << "ACCEPTED\n\n";
        if (ONLY_SEED != -1) break;
    }

    cout << "ALL TESTS PASSED :D\n";
    return 0;
}
