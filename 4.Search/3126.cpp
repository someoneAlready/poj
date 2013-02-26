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
#define N 9999

int i,j,k,m,n,l;
bool v[N+10];
int f[N+10];
int d[]={1, 10, 100, 1000};
int o[4];

void bfs(){
    queue<int> q; fill(f, -1);
    q.push(n), f[n]=0;
    while (!q.empty()){
        i=q.front();
        if (i==m) break;
        rep(k, 4) o[k]=i%(d[k]*10)/d[k];
        
        rep(k, 4) rep(l, 10){
            j=i+(-o[k]+l)*d[k];
            
            if (!v[j] && f[j]==-1){
                f[j]=f[i]+1;
                q.push(j);
                if (j==m) break;
            }
        }
        q.pop();
    }
    
    if (f[m]==-1) puts("Impossible");
    else printf("%d\n", f[m]);
}

int main(){   
    
    repf(i, 2, N) if(!v[i]){
        if (i<1000) v[i]=true;
        repf(j, 2, N/i) v[i*j]=true;
    }
    
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d%d", &n, &m);
        bfs();
    }
    return 0;
}
