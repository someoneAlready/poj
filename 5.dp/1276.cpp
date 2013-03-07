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
#define V 100000

int i,j,k,m,n,l,v;
bool f[V+10];

void gao(int k){
    repd(i, v, k) if (f[i-k]) f[i]=1;
}

int main(){
    while (~scanf("%d%d", &v, &n)){
        fill(f, 0); f[0]=1;
        rep(i, n){
            int ni, di;
            scanf("%d%d", &ni, &di);
            rep(i, 1<<20){
                if (ni>=i) gao(i*di), ni-=i;
                else{
                    gao(ni*di); break;
                }
            }
        }
        repd(i, v, 0) if (f[i]){
            printf("%d\n", i); break;
        }
    }
    return 0;
}

