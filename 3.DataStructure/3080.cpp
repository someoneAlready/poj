#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 10
#define M 60

int i,j,k,m,n,l;
char s[N+10][M+10];

bool ok(const char *t){
	repf(i, 2, n-1) if (strstr(s[i], t)==NULL) return false;
	return true;
}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d", &n);
		rep(i, n) scanf("%s", s[i]);
		string ans;
		rep(i, M){
			rep(j, M){
				int k=0;
				string t;
				while (s[0][i+k]==s[1][j+k] && i+k<M){
					t+=s[0][i+k]; 
					++k; 
					if (ok(t.c_str())){
						if (sz(t)>sz(ans) || (sz(t)==sz(ans) && t<ans)){
							ans=t;
						}
					}
					else break;
				}
			}
		}
		if (sz(ans)<3) puts("no significant commonalities");
		else cout<<ans<<endl;
	}
	return 0;
}


