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
#define N 100000

int i,j,k,m,n,l;

struct P{
    int x, y;
};
struct node{
    int name;
    node *next;
};

template <int SZ>
struct BIT{
    int a[SZ];
public:
    void clear(){ clr(a, 0); }
    void ins(int x, int k){
        while (x<=n)
            a[x]+=k, x+=x&-x;
    }
    int qry(int x){
        int ret=0;
        while (x>0)
            ret+=a[x], x-=x&-x;
        return ret;
    }
};


node *a[N+10], pool[N*2+10];
int px;
P p[N+10];
bool v[N+10];
int dfs_clock;
char s[100];
BIT<N+10> bit;

void add(int j, int k){
    pool[++px].name=k;
    pool[px].next=a[j];
    a[j]=& pool[px];
}

void solve(){
    scanf("%d", &m);
    bit.clear(); clr(v, 1);
    repf(i, 1, n) bit.ins(p[i].y, 1);
    while (m--){
        scanf("%s%d", s, &k);
        if (s[0]=='C'){
            v[k]=!v[k];
            if (v[k]) bit.ins(p[k].y, 1);
            else bit.ins(p[k].y, -1);
        }
        else if (s[0]=='Q'){
            printf("%d\n", bit.qry(p[k].y)-bit.qry(p[k].x-1));
        }
    }
}

void dfs(int i, int fa){
    p[i].x=dfs_clock+1;
    for(node *p=a[i]; p; p=p->next){
        if (p->name!=fa) dfs(p->name, i);
    }
    p[i].y=++dfs_clock;
}

int main(){
    while (~scanf("%d", &n) && n){       
        repf(i, 1, n) a[i]=NULL; 
        px=-1;
        rep(i, n-1) scanf("%d%d", &j, &k), add(j, k), add(k, j);
        dfs_clock=0, dfs(1, 0);
        solve();
    }    
    return 0;
}

