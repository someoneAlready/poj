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

int i,j,k,m,n,l;

ll solve(){
	ll tot=0, a1=0;
	n=9;
	repf(d, 1, 10){
		a1+=d;
		ll delta=a1*n+n*(n-1)*d/2;
		if (tot+delta>=m){
			m-=tot;
			ll x=1, y=n;

			while (x!=y){
				ll z=mid(x,y), si=a1*z+z*(z-1)*d/2;
				if (si>=m) y=z;
				else x=z+1;
			}
			ll si=a1*(x-1)+(x-1)*(x-2)*d/2;
			m-=si;

			tot=0, n=9, a1=1;
			repf(i, 1, 10){
				delta=i*n;
				if (tot+delta>=m){
					m-=tot;
					x=a1+(m-1)/i, y=m%i;
					if (y==0) y=i;
					vi v;
					while (x) v.pb(x%10), x/=10;

					return v[i-y];
				}
				tot+=delta;
				n*=10, a1*=10;
			}


		}
		tot+=delta;
		a1+=(n-1)*d;
		n*=10;       
	}

}

int main(){
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%d", &m);
		cout<<solve()<<endl;

	}
	return 0;
}
