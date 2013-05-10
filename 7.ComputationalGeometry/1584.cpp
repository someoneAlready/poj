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
#define eps 1e-10
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
    double operator ^(const P &p){return x*p.x+y*p.y; }
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

bool isPointInPolygon(P p, vp &a){
    int w=0;
    rep(i, n){
        int k=sgn((a[i+1]-a[i])*(p-a[i]));
        int d1=sgn(a[i].y-p.y);
        int d2=sgn(a[i+1].y-p.y);
        if (k>0 && d1<=0 && d2>0) w++;
        if (k<0 && d2<=0 && d1>0) w--;
    }
    if (w!=0) return 1;
    return 0;
}

void solve(){
    a.pb(a[0]);
    vi b;
    repf(i, 2, n+3){
        int k=sgn( (a[i%n]-a[(i-2)%n])*(a[(i-1)%n]-a[(i-2)%n]) );
        if (k!=0) b.pb(k);
        if (sz(b)>1 && b[sz(b)-1]*b[sz(b)-2]<0){
            puts("HOLE IS ILL-FORMED");
            return;
        }
    }
    
    if (!isPointInPolygon(P(c.x, c.y), a)){ 
        puts("PEG WILL NOT FIT"); return;
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
