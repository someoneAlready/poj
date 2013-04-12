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
#define N 2000

template<int SZ>
class UFS{
    int f[SZ+10];
public:
    void clear(int n){ repf(i, 1, n) f[i]=i; }
    int find(int i){
        if (f[i]==i) return i;
        return f[i]=find(f[i]);
    }
    void unions(int i, int j){
        i=find(i), j=find(j);
        f[i]=j;
    }
};

int i,j,k,m,n,l;
UFS<N> ufs;
int op[N+10];

bool gao(){
    bool ret=true;
    scanf("%d%d", &n, &m);
    ufs.clear(n); clr(op, 0);
    
    while (m--){
        scanf("%d%d", &i, &j);
        if (!ret) continue;
        if (ufs.find(i)==ufs.find(j)) ret=false;
        if (op[i]) ufs.unions(op[i], j);
        if (op[j]) ufs.unions(op[j], i);
        op[i]=j, op[j]=i;
    }
    return ret;
}

int main(){
    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){       
        printf("Scenario #%d:\n", test);
        if (gao()) puts("No suspicious bugs found!");
        else puts("Suspicious bugs found!");
        puts("");
    }
    return 0;
}

