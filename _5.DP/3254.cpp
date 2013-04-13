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
#define N 12

int i,j,k,m,n,l;
int f[N+10][1<<N];
int E=100000000;

int main(){
    while (~scanf("%d%d", &n, &m)){
        clr(f, 0);
        f[0][0]=1;
        repf(i, 1, n){
            k=0;
            rep(j, m) scanf("%d", &l), k<<=1, k+=l;
            rep(j, 1<<m) if ((j|k)==k &&  (j&(j>>1))==0  )
                rep(l, 1<<m) if ( (l&j)==0) 
                    f[i][j]=(f[i][j]+f[i-1][l])%E;
        }
        int ans=0;
        rep(j, 1<<m) ans=(ans+f[n][j])%E;
        cout<<ans<<endl;
    }
    return 0;
}

