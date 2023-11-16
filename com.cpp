#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
#define ar array
#define pi pair<int, int> 
#define pi pair<int, int> 
#define pl pair<ll,ll>
#define pd pair<ld,ld>
#define vi vt<int>
#define vl vt<ll>
#define vs vt<string>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define sz(x) (int)(x).size()
#define all(c) (c).begin(), (c).end()

#define INF 1e18
#define NINF -1 * 1e18
#define PI 3.141592653589793238462
#define MOD 1000000007

template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}

#define EACH(x, a) for(auto& x: a)

void print(int a) { cerr << a << endl; }
void print(ll a) { cerr << a << endl; }
void print(ull a) { cerr << a << endl; }
void print(bool a) { cerr << a << endl; }
void print(string a) { cerr << a << endl; }
void print(char a) { cerr << a << endl; }
void print(float a) { cerr << a << endl; }
void print(double a) { cerr << a << endl; }
template<class T> void print(vt<T> v) { cerr << "[ ";for (T i : v) {print(i);cerr << " ";} cerr << "]";}
template<class T> void print(set<T> s) { cerr << "[ ";for (T i : s) {print(i); cerr << " ";} cerr << "]";}
template <class T> void prar(T arr[], size_t size) { cerr << "[ "; for (size_t i = 0; i < size; ++i) { print(arr[i]); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "[ " << #x << " = "; print(x); cerr << " ]" << endl;
#define dbga(x, y) cerr << "[ " << #x << " = "; prar(x, y); cerr << " ]" << endl;
#else
#define debug(x)
#define dbga(x, y)
#endif

template<typename T_vector>
void print_vector(const T_vector &v, int start = -1, int end = -1) {if (start < 0) start = 0;if (end < 0) end = int(v.size());for (int i = start; i < end; i++) {cout << v[i] << (i < end - 1 ? ' ' : '\n');}}

void lcs(string X, string Y, int m, int n) {
    int a[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                a[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                a[i][j] = a[i - 1][j - 1] + 1;
            } else {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
    int index = a[m][n];
    string ans(index, '0');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            ans[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (a[i - 1][j] > a[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << a[m][n] << '\n';
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string X, Y;
    cin >> X >> Y;
    int m = sz(X);
    int n = sz(Y);
    lcs(X, Y, m, n);
    return 0;
}