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
#define N 50000
struct P{
    double x, y;
    P(){}
    P(double x, double y):x(x),y(y){}
    P operator -(const P &p)const{return P(x-p.x, y-p.y); }
    double operator *(const P &p)const{return x*p.y-y*p.x; }
    double operator ^(const P &p){return x*p.x+y*p.y; }
    bool operator ==(const P &p){return x==p.x && y==p.y; }
    double len(){return x*x+y*y; }
    void input(){ scanf("%lf%lf", &x, &y); }
    void out(){ cout<<x<<' '<<y<<endl; }
};
#define eps 1e-8
int sgn(double d){ return d<-eps?-1:d>eps; }

int i,j,k,m,n,l;
P a[N+10], b[N+10], C;
bool cmp(const P a, const P b){
    return a.x==b.x?a.y<b.y:a.x<b.x;
}

int main(){
    while (~scanf("%d", &n)){
        rep(i, n) a[i].input();
        sort(a, a+n, cmp);
                
        m=0;
        rep(i, n){
            while (m>1 && (b[m-1]-b[m-2])*(a[i]-b[m-2])<=0) m--;
            b[m++]=a[i];
        }        
        int k=m;
        repd(i, n-2, 0){
            while (m>k && (b[m-1]-b[m-2])*(a[i]-b[m-2])<=0) m--;
            b[m++]=a[i];
        }
        if (m>1) m--;
        
        double ans=0; int j=0;
        
        
        rep(i, m) rep(j, m) checkmax(ans, (b[i]-b[j]).len());
        /*
        rep(i, m){
            while ( (b[i]-b[j]).len()<(b[i]-b[(j+1)%m]).len() ) j=(j+1)%m;
            checkmax(ans, (b[i]-b[j]).len());
        }
*/
        printf("%d\n",(int)ans);
    }
    return 0;
}
