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
#define N 500000

int i,j,k,m,n,l;
int a[N+10];
vi s, t;

ll mergeSort(int x, int y){
	if (x==y) return 0;
	int z=mid(x, y);
	ll ret=mergeSort(x, z)+mergeSort(z+1, y);

	s.clear(), t.clear();
	repf(i, x, z) s.pb(a[i]);
	repf(i, z+1, y) t.pb(a[i]);

	int i=0, j=0, k=x;
	while (i<sz(s) && j<sz(t)){
		if (s[i]<=t[j]) a[k++]=s[i++];
		else{
		   	a[k++]=t[j++], ret+=sz(s)-i;
		}
	}
	while (i<sz(s)) a[k++]=s[i++];
	while (j<sz(t)) a[k++]=t[j++];

	return ret;
}

int main(){
	while (~scanf("%d", &n) && n){
		rep(i, n) scanf("%d", &a[i]);
		cout<<mergeSort(0, n-1)<<endl;
	}
	return 0;
}


