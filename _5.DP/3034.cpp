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
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 20
#define TT 10 

template<class T>
T gcd(T a, T b){return b==0?a:gcd(b, a%b); }

int i,j,k,m,n,l;
int f[TT+10][N+10][N+10];
bool v[TT+10][N+10][N+10];
int d;

struct P{
    int x, y;
    P(){}
    P(int x, int y):x(x),y(y){}
    P operator -(const P&p)const{ return P(x-p.x, y-p.y); }
    P operator +(const P&p)const{ return P(x+p.x, y+p.y); }    
    bool operator !=(const P&p)const{ return x!=p.x || y!=p.y; }
    void out(){ cout<<x<<' '<<y<<endl; }
};

int gao(P i, P j, int t){
    int ret=0;
    P p=j-i;
    k=gcd(abs(p.x), abs(p.y));
    if(k) p.x/=k, p.y/=k;

    do{
        if (v[t][i.x][i.y]) ret++;
        i=i+p;
    }while (i!=j);
    
    if ((p.x!=0 || p.y!=0) && v[t][i.x][i.y]) ret++;
    return ret;
}

int main(){
    while (~scanf("%d%d%d", &n, &d, &m) && n+d+m){
        clr(v, 0);
        int x, y, t;
        while (m--){            
            scanf("%d%d%d", &x, &y, &t);
            v[t][x][y]=1;
        }

        clr(f, 0); int ans=0;
        repf(t, 1, 10)
            rep(i, n+10) rep(j, n+10) rep(x, n+10) rep(y, n+10)
            if (SQR(i-x)+SQR(j-y)<=SQR(d))
            {
                checkmax(f[t][i][j], f[t-1][x][y]+gao(P(i-5,j-5), P(x-5, y-5), t));
                checkmax(ans, f[t][i][j]);
            }
        cout<<ans<<endl;
    }
    return 0;
}

