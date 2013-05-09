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
#define PI acos(-1.)
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
#define N 1000
typedef int T;

struct P{
    T x, y;
    P(){}
    P(T x, T y):x(x),y(y){}
    P operator -(const P &p)const{return P(x-p.x, y-p.y); }
    T operator *(const P &p)const{return x*p.y-y*p.x; }
    T operator ^(const P &p){return x*p.x+y*p.y; }
    bool operator ==(const P &p){return x==p.x && y==p.y; }
    double len(){return sqrt(x*x+y*y); }
    void input(){ scanf("%d%d", &x, &y); }
    void out(){ cout<<x<<' '<<y<<endl; }
    bool operator <(const P &p)const{return x==p.x?y<p.y:x<p.x;}
};

int i,j,k,m,n,l;
vp a, b;

void ConvexHull(vp &a, vp &b){   
    sort(all(a)); 
    rep(i, n){
        while (sz(b)>1 && (b[sz(b)-1]-b[sz(b)-2])*(a[i]-b[sz(b)-2])<=0) b.pop_back();
        b.pb(a[i]);
    }
    int k=sz(b);
    repd(i, n-2, 0){
        while (sz(b)>k && (b[sz(b)-1]-b[sz(b)-2])*(a[i]-b[sz(b)-2])<=0) b.pop_back();
        b.pb(a[i]);
    }
    if (sz(b)>1) b.pop_back();
}

int main(){
    while (~scanf("%d%d", &n, &m)){
        a.clear(), b.clear();
        rep(i, n){
            P p;
            p.input(), a.pb(p);
        }
        ConvexHull(a, b);
        double ans=0;

        rep(i, sz(b))
            ans+=(b[(i+1)%n]-b[i]).len();
        
        ans+=m*2*PI;
        printf("%.0f\n", ans);
    }
    return 0;
}
