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
#define N 31

int i,j,k,m,n,l;
ll c[N+10][N+10];

int gao(int n){
    vi v;
    while (n) v.pb(n&1), n>>=1;
    int ret=0;
    repf(i, 2, sz(v)-1){
        repf(j, 0, i/2-1)
            ret+=c[i-1][j];
    }
   
    k=1;
    repd(i, sz(v)-2, 0){
        if (v[i]){
            repf(j, 0, sz(v)/2-k)            
                ret+=c[i][j];
            k++;
        }
    }
    if (k<=sz(v)/2) ret++;
    return ret;
}

int main(){
    c[0][0]=1;
    repf(i, 1, N){
        c[i][0]=1;
        repf(j, 1, i) c[i][j]=c[i-1][j]+c[i-1][j-1];
    }

    int a, b;
    while (~scanf("%d%d", &a, &b)){
        
        printf("%d\n", gao(b)-gao(a-1));
    }
    return 0;
}
