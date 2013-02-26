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
#define N 100
#define Q N*N

int i,j,k,m,n,l,c;
bool v[N+10][N+10];

struct P{
    int x,y;
    P(){}
    P(int x,int y):x(x),y(y){}
};

int head, tail, pre[Q+10];
P q[Q+10], f[Q+10];


void gao(P p, P r){
    if (!v[p.x][p.y]){
        v[p.x][p.y]=true, f[tail]=r, pre[tail]=head;
        q[tail++]=p;
    }
}

void bfs(){
    fill(v, 0), head=0, tail=1;
    v[0][0]=true; q[0]=P(0,0);
    while (head!=tail){
        if (q[head].x==c || q[head].y==c){
            vp v;
            v.clear();
            k=head;
            while (k) v.pb(f[k]), k=pre[k];
            
            printf("%d\n", sz(v));
            repd(k, sz(v)-1, 0){
                if (v[k].x==1){
                    if (v[k].y==0) puts("FILL(1)");
                    else puts("FILL(2)");
                }
                else if (v[k].x==2){
                    if (v[k].y==0) puts("DROP(1)");
                    else puts("DROP(2)");
                }
                else{
                    if (v[k].y==0) puts("POUR(1,2)");
                    else puts("POUR(2,1)");
                }
            }
            return;
        }
        if (q[head].x!=n) gao(P(n,q[head].y), P(1,0));
        if (q[head].y!=m) gao(P(q[head].x,m), P(1,1)); 
        if (q[head].x) gao(P(0,q[head].y), P(2,0));
        if (q[head].y) gao(P(q[head].x,0), P(2,1));
        k=min(q[head].x, m-q[head].y), gao(P(q[head].x-k, q[head].y+k), P(3,0));
        k=min(n-q[head].x, q[head].y), gao(P(q[head].x+k, q[head].y-k), P(3,1));
        head++;
    }
    puts("impossible");
}

int main(){
    while (~scanf("%d%d%d", &n, &m, &c)){
        bfs();
    }
    return 0;
}
