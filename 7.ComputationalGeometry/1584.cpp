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
#define eps 1e-8
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

int sgn(double d){ return d<-eps?-1:d>eps; }

struct C{
    double x, y, r;
    void input(){ scanf("%lf%lf%lf", &r, &x, &y); }
};

struct P{
    double x, y;
    P(){}
    P(double x, double y):x(x),y(y){}
    P operator -(const P &p){return P(x-p.x, y-p.y); }
    double operator *(const P &p){return x*p.y-y*p.x; }
    double operator ^(const P &p){return x*p.x-y*p.y; }
    bool operator ==(const P &p){return x==p.x && y==p.y; }
    double len(){return sqrt(x*x+y*y); }
    void input(){ scanf("%lf%lf", &x, &y); }
};

int i,j,k,m,n,l;
C c;
vector<P> a;

double dis(P a, P b, P p){
    if (a==b) return (p-a).len();
    if (sgn((p-a)^(b-a))<0) return (p-a).len();
    else if (sgn((p-b)^(a-b))<0) return (p-b).len();
    else return fabs((p-a)*(a-b))/(a-b).len();
}

void solve(){
    a.pb(a[0]);
    vi b;
    repf(i, 2, n){
        b.pb( sgn( (a[i]-a[i-2])*(a[i-1]-a[i-2]) ));
        if (i>2 && b[i-2]*b[i-3]<0){
            puts("HOLE IS ILL-FORMED");
            return;
        }
    }
    rep(i, n){
        if (sgn(dis(a[i], a[i+1], P(c.x, c.y))-c.r)<0){
            puts("PEG WILL NOT FIT");
            return;
        }
    }
    puts("PEG WILL FIT");
}

int main(){
    while (~scanf("%d", &n) && n>=3){
        c.input(), a.clear();
        rep(i, n){
            P p; 
            p.input(), a.pb(p);
        }
        solve();
    }
    return 0;
}

