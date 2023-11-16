#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
#define ar array
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

struct tripple {
	ll a;
	int b,c;
};

void solve() {
	
	//DATA
	int N;
	cin>>N;
	vt<tripple> v(N+1); // masa, iq, przynaleznosc
	v[0] = {0,0,0};
	for(int i = 1; i <= N; i++) {
		cin >> v[i].a >> v[i].b;
		v[i].c = 0;
	}
	
	
	//CHECK
	// for(auto x : v) {
	// 	cout << x.a << ' ' << x.b << ' ' << x.c << '\n';
	// }
	
	//STRUCTURES
	int ilosc_kol = 0;
	map<int, tripple> kol; // masa, iq_max, iq_min
	kol.insert({0, {0,0,0}});
	map<int, vi> kol_el;
	kol_el.insert({0, {0}});
	//SOLUTION
	while(cin) {
		string x; int a;
		cin >> x >> a;
		if(x == "IQ_MIN") {
			kol[0].c = v[a].b;
			cout << kol[v[a].c].c << '\n';
		} else if(x == "IQ_MAX") {
			kol[0].b = v[a].b;
			cout << kol[v[a].c].b << '\n';
		} else if(x == "JOIN") {
			int b; cin >> b;
			if(!((v[a].c==v[b].c) && (v[a].c != 0))) {
				if(v[a].c == 0) {
					if(v[b].c == 0) {
						ilosc_kol++;
						kol.insert({ilosc_kol,{v[a].a+v[b].a, max(v[a].b,v[b].b), min(v[a].b,v[b].b)}});
						kol_el.insert({ilosc_kol,{a,b}});
						v[a].c = ilosc_kol;
						v[b].c = ilosc_kol;
					} else {
						v[a].c = v[b].c;
						kol[v[b].c].a += v[a].a;
						kol[v[b].c].b = max(kol[v[b].c].b, v[a].b);
						kol[v[b].c].c = min(kol[v[b].c].c, v[a].b);
						kol_el[v[b].c].pb(a);
					}
				} else {
					if(v[b].c == 0) {
						v[b].c = v[a].c;
						kol[v[a].c].a += v[b].a;
						kol[v[a].c].b = max(kol[v[a].c].b, v[b].b);
						kol[v[a].c].c = min(kol[v[a].c].c, v[b].b);
						kol_el[v[b].c].pb(b);
					} else {
						if(sz(kol_el[v[a].c]) > sz(kol_el[v[b].c])) {
							int x = v[b].c;
							kol[v[a].c].a += kol[v[b].c].a;
							kol[v[a].c].b = max(kol[v[a].c].b, kol[v[b].c].b);
							kol[v[a].c].c = min(kol[v[a].c].c, kol[v[b].c].c);
							for(auto y : kol_el[v[b].c]) {
								v[y].c = v[a].c;
								kol_el[v[a].c].pb(y);
							}
							kol.erase(x);
							kol_el.erase(x);
						} else {
							int x = v[a].c;
							kol[v[b].c].a += kol[v[a].c].a;
							kol[v[b].c].b = max(kol[v[b].c].b, kol[v[a].c].b);
							kol[v[b].c].c = min(kol[v[b].c].c, kol[v[a].c].c);
							for(auto y : kol_el[v[a].c]) {
								v[y].c = v[b].c;
								kol_el[v[b].c].pb(y);
							}
							kol.erase(x);
							kol_el.erase(x);
						}
					}
				}
			}
		} else if(x == "MASA") {
			if(v[a].c != 0) {
				cout << kol[v[a].c].a << '\n';
			} else {
				cout << v[a].a << '\n';
			}
		}
	}
	
	
	//CHECK
	// for(auto x : kol) {
	// 	cout << x.ff << ": ";
	// 	cout << x.ss.a << ' ' << x.ss.b << ' ' << x.ss.c << '\n';
	// }
	// for(auto x : v) {
	// 	cout << x.a << ' ' << x.b << ' ' << x.c << '\n';
	// }
	// for(auto x : kol_el) {
	// 	cout << x.ff << ": ";
	// 	for(auto y : x.ss) {
	// 		cout << y << ' ';
	// 	}
	// 	cout << '\n';
	// }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}