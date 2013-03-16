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
#define N 10
#define M 15

int i,j,k,m,n,l;
char a[N+10][M+10];
bool v[N+10][M+10];

int ans, tot;
struct P{
    int x, y;
    P(){}
    P(int x, int y):x(x),y(y){}
    P operator +(const P& p)const{ return P(x+p.x, y+p.y); }
};
P d[]={P(1,0), P(-1,0), P(0,1), P(0,-1)};

int dfs(P p, int flag){
    int ret=1;
    v[p.x][p.y]=true;
    rep(i, 4){
        P q=p+d[i];
        if (q.x>0 && q.y>0 && q.x<=N && q.y<=M && a[q.x][q.y]==a[p.x][p.y] && !v[q.x][q.y])
            ret+=dfs(q, flag);
    }
    if (flag) a[p.x][p.y]=' ';
    return ret;
}

void solve(){
    fill(v, 0), ans=0, tot=N*M;
    ans=0, tot=N*M;
    repf(step, 1, INT_MAX){
        fill(v, 0);
        int now=-1; P p;
        repf(j, 1, M) repf(i, 1, N) if (!v[i][j] && a[i][j]!=' '){
            int k=dfs(P(i, j), 0);
            if (now==-1 || k>now) now=k, p=P(i,j);
        }
        

        
        if (now<2) return;
        printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", step, p.x, p.y, now, a[p.x][p.y], SQR(now-2));
        ans+=SQR(now-2), tot-=now;
        fill(v, 0);
        dfs(p, 1);

     
        repf(j, 1, M){
            repf(i, 1, N) if (a[i][j]==' '){
                repf(k, i+1, N) if (a[k][j]!=' '){
                    swap(a[i][j], a[k][j]); break;
                }
                if (a[i][j]==' ') break;
            }            
        }
        repf(j, 1, M) if (a[1][j]==' '){
            repf(k, j+1, M) if (a[1][k]!=' '){
                repf(l, 1, N) swap(a[l][j], a[l][k]);
                break;
            }
            if (a[1][j]==' ') break;
        }

    }
}

int main(){
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){
        repd(i, N, 1){
            scanf("%s", a[i]);
            repd(j, M, 1) a[i][j]=a[i][j-1];
        }
        if (test-1) puts("");
        printf("Game %d:\n\n", test);
        solve();
        if (tot==0) ans+=1000;
        printf("Final score: %d, with %d balls remaining.\n", ans, tot);
    }
    return 0;
}

