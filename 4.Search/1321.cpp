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
#define N 8

int i,j,k,m,n,l;
char a[N+10][N+10];
bool row[N+10], col[N+10];
int ans, tot;

struct P{
    int x, y;
    P(){}
    P(int x,int y):x(x),y(y){}
    P operator +(P &p)const{ return P(x+p.x,y+p.y); }
    P operator -(P &p)const{ return P(x-p.x,y-p.y); }
    bool ok(){if (x>0 && y>0 && x<=n && y<=m)return true; return false; }
};

P s[N+10];

void dfs(int i, int j){
    if (j==0){
        ans++; return;
    }
    if (i+j>tot) return;
    if (i==tot) return;
    
    if (!row[s[i].x] && !col[s[i].y]){
        row[s[i].x]=col[s[i].y]=true;
        dfs(i+1, j-1);
        row[s[i].x]=col[s[i].y]=false;
    }        
    dfs(i+1, j);    
}

int main(){
    while (~scanf("%d%d", &n, &m) && n+m!=-2){
        ans=0; tot=0;
        repf(i, 1, n) repf(j, 1, n){
            a[i][j]=getchar();
            while (strchr("#.", a[i][j])==NULL) a[i][j]=getchar();
            if (a[i][j]=='#') s[tot++]=P(i,j);
        }
        fill(row, 0), fill(col, 0);
        
        dfs(0, m);
        
        printf("%d\n", ans);
    }
    return 0;
}
