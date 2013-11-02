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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator

const double pi=acos(-1.);
int main(){
	int tests;
	scanf("%d", &tests);
	repf(test, 1, tests){
		double n, m, t, c;
		scanf("%lf%lf%lf%lf", &n, &m, &t, &c);
		double x=SQR(t)*m*n;
		double a=SQR(c)+SQR(t-c)*n*m+c*(t-c)*(n+m);
		double b=c*c*(n+m-2)+c*(t-c)*(n*(m-1)+m*(n-1));
		double d=SQR(c/2.)*pi*(n-1)*(m-1);
		c=x-a-b-d;
		if (test-1) puts("");
		printf("Case %d:\n", test);
		printf("Probability of covering 1 tile  = %.4f\x25\n", a/x*100);
		printf("Probability of covering 2 tiles = %.4f\x25\n", b/x*100);
		printf("Probability of covering 3 tiles = %.4f\x25\n", c/x*100);
		printf("Probability of covering 4 tiles = %.4f\x25\n", d/x*100);
		
	}
	return 0;
}

