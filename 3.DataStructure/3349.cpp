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
#define N 100000

int i,j,k,m,n,l;

int a[6], b[N+10][6], c[6];

bool equal(int *a, int *b){
	rep(i, 6) if (a[i]!=b[i]) return false;
	return true;
}

template<int SZ>
struct H{
	int h[SZ+10];
	H(){fill(h, -1); }
	int gao(int *a){
		ll ret=0;
		rep(i, 6) ret=(ret*131+a[i])%SZ;
		return ret;
	}
	int find(int *a){
		int k=gao(a);
		while (h[k]!=-1 && !equal(b[h[k]], a)){
			k=(k+1)%SZ;
		}
		return h[k];
	}
	int ins(int *a, int i){
		int k=gao(a);
		while (h[k]!=-1 && !equal(b[h[k]], a)){
			k=(k+1)%SZ;
		}
		h[k]=i;
	}
};
H<1000003> G;

int main(){
		scanf("%d", &n);
		map<string,int> mp;

		bool flag=false;
		while (n--){
			rep(i, 6) scanf("%d", &a[i]);
			memcpy(b[n], a, sizeof(a));
			
			repf(i, -1, 1) if (i!=0) 
				rep(j, 6){
					int ok=0;
					rep(k, 6){
					   	c[k]=a[(j+k*i+6)%6];
						if (ok==0){
							if (c[k]<b[n][k]) ok=1;
							else if (c[k]>b[n][k]) ok=-1;
						}
					}
					if (ok==1) memcpy(b[n], c, sizeof(c));
				}
			if (G.find(b[n])!=-1){
				flag=true; break;
			}
			else G.ins(b[n], n);
		}
		

		if (flag) puts("Twin snowflakes found.");
		else puts("No two snowflakes are alike.");
	
	return 0;
}


