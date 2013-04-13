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
#define N 100
#define M 10

int i,j,k,m,n,l;
int f[2][1<<M+M];
int a[1<<M];

int main(){
    rep(i, 1<<M){
        n=i;
        while (n) a[i]+=n&1, n>>=1;
    }
    while (~scanf("%d%d", &n, &m) && n+m){
        vi v;
        rep(i, 1<<m) if ( !(i&(i>>1)) && !(i&(i>>2)) ) v.pb(i);
        clr(f[0], -1);
        f[0][0]=0;
        repf(i, 1, n){
            int k=0, e=i%2;
            clr(f[e], -1);
            rep(j, m){
                char ch=getchar();
                while (ch!='H' && ch!='P') ch=getchar();
                k=(k<<1)+(ch=='P');
            }
            
            rep(r, sz(v)) if ( (v[r]|k)==k)
                rep(s, sz(v)) if ( (v[s]& v[r])== 0)
                    rep(t, sz(v)) if ( (v[t]& v[r])==0 && (v[t]&v[s])==0 )
                        if (f[1-e][(v[t]<<m)+v[s]]!=-1){
                            checkmax(f[e][(v[s]<<m)+v[r]], f[1-e][(v[t]<<m)+v[s]]+a[v[r]]);
                        }
          //  rep(j, 1<<m+m) if (f[i][j]!=-1) cout<<j<<' '<<f[i][j]<<endl;
        
                    
        }
        int
         ans=0;
        rep(j, 1<<m+m) checkmax(ans, f[n%2][j]);
        cout<<ans<<endl;
    }
    return 0;
}

