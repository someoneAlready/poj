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
#define N 100

int i,j,k,m,n,l;
char s1[N+10], s2[N+10], b[10000][N*2+10];

void get(char &ch){
    ch=getchar();
    while (!isalpha(ch)) ch=getchar();
}

template<class T>
bool equal(T *a, T *b){
	rep(i, 2*n) if (a[i]!=b[i]) return false;
	return true;
}

template<int SZ, class T>
struct H{
	int h[SZ+10];
	void clear(){fill(h, -1); }
	int gao(T *a){
		ll ret=0;
		rep(i, 2*n) ret=(ret*131+a[i])%SZ;
		return ret;
	}
	int find(T *a){
		int k=gao(a);
		while (h[k]!=-1 && !equal(b[h[k]], a)){
			k=(k+1)%SZ;
		}
		return h[k];
	}
	int ins(T *a, int i){
		int k=gao(a);
		while (h[k]!=-1 && !equal(b[h[k]], a)){
			k=(k+1)%SZ;
		}
		h[k]=i;
	}
};
H<1000003, char> G;

int solve(){
    int ret=0;
    while(++ret){
        rep(i, n) b[ret][i*2]=s2[i], b[ret][i*2+1]=s1[i];
        if (equal(b[ret], b[0])) return ret;
        if (G.find(b[ret])!=-1) return -1;
        G.ins(b[ret], ret);
        rep(i, n) s1[i]=b[ret][i], s2[i]=b[ret][i+n];
    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){
        G.clear();
        scanf("%d", &n);
        rep(i, n) get(s1[i]);
        rep(i, n) get(s2[i]);
        rep(i, 2*n) get(b[0][i]);
        printf("%d %d\n", test, solve());
    }
    return 0;
}
