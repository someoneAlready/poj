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
#define N 30
int sgn(double d){ return d<-eps?-1:d>eps; }

struct P{
    double x, y;
    P(){}    
    P(double x, double y):x(x), y(y){}
    P operator -(const P &p){return P(x-p.x, y-p.y); }
    double operator *(const P &p){return x*p.y-y*p.x; }
    void out(){ printf("%.3f %.3f\n", x, y); }
};

void getIntersection(P p1, P p2, P p3, P p4, P &c){
    double d1=(p2-p1)*(p3-p1), d2=(p2-p1)*(p4-p1);
	c=P((p3.x*d2-p4.x*d1)/(d2-d1), (p3.y*d2-p4.y*d1)/(d2-d1));	
}

int i,j,k,m,n,l;

P bt[N+10], tp[N+10], lf[N+10], rt[N+10], c[N+10][N+10];


double gao(P p1, P p2, P p3, P p4){
    double ret=(p4-p1)*(p3-p1)+(p3-p1)*(p2-p1);
    return ret/2;
}

void solve(){

    bt[0]=lf[0]=P(0,0), bt[n+1]=rt[0]=P(1,0);
    tp[0]=lf[n+1]=P(0,1), tp[n+1]=rt[n+1]=P(1,1);
    double ret=0;
    repf(i, 0, n+1) repf(j, 0, n+1){
        getIntersection(tp[i], bt[i], lf[j], rt[j], c[i][j]);    
        if (i && j){
            checkmax(ret, gao(c[i-1][j-1], c[i-1][j], c[i][j], c[i][j-1]));
        }
    }
    printf("%.6f\n", ret);
}

void init(){
    double d;
    repf(i, 1, n) scanf("%lf", &d), bt[i]=P(d, 0);
    repf(i, 1, n) scanf("%lf", &d), tp[i]=P(d, 1);
    repf(i, 1, n) scanf("%lf", &d), lf[i]=P(0, d);
    repf(i, 1, n) scanf("%lf", &d), rt[i]=P(1, d);
}
    
int main(){
    while (~scanf("%d", &n) && n){
        init();
        solve();        
    }
    return 0;
}

