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
#define M 250

struct P{
    int x, y;
    P(){}
    P(int x, int y):x(x),y(y){}
    void input(){ scanf("%d%d", &x, &y); }
    P operator -(const P&p)const{return P(x-p.x, y-p.y); }
    int operator *(const P&p)const{ return x*p.y-y*p.x; }
    int operator ^(const P&p)const{ return x*p.x+y*p.y; }
};

int i,j,k,m,n,l;
vi a[M+10];
P p[M+10];

bool onSeg(P p, P a1, P a2){
    if ( (p-a1)*(p-a2)==0 && ((a1-p)^(a2-p) )<0) return true;
    return false;
}

bool isIntersection(P p1, P p2, P p3, P p4){
    int d1=(p2-p1)*(p3-p1), d2=(p2-p1)*(p4-p1);
    int d3=(p4-p3)*(p1-p3), d4=(p4-p3)*(p2-p3);
    if (d1==0 && d2==0 && (onSeg(p3, p1, p2) ^ onSeg(p4, p1, p2))) return true;
    if (d1*d2<0 && d3*d4<0) return true;
    return false;
}

bool ok(int i, int j){
    rep(k, i){
        rep(l, sz(a[k])){
            int w=a[k][l];
            if (isIntersection(p[i], p[j], p[k], p[w])) return false;
        }
    }
    return true;
}

bool vis[M+10], v[M+10];
void dfs(int i){
    vis[i]=v[p[i].x]=1;
    rep(k, sz(a[i])){
        int j=a[i][k];
        if (!vis[j]) dfs(j);
    }
}

bool solve(){
    rep(i, m) if (i%2==0){
        fill(v, 0), fill(vis, 0);
        dfs(i);
        if (v[0] && v[n]) return true; 
    }
    return false;
}

int main(){
    while (~scanf("%d%d", &n, &m) && n+m){
        rep(i, m) a[i].clear();
        rep(i, m){
            p[i].input();
            rep(j, i) if ((i-j)%2==0){
                P q=p[i]-p[j];
                if ( (abs(q.x)==1 && abs(q.y)==2) || (abs(q.x)==2 && abs(q.y)==1) ){
                    if (ok(i,j)) a[i].pb(j), a[j].pb(i);
                }
            }
        }        
        if (solve()) puts("yes");
        else puts("no");
    }
    return 0;
}

