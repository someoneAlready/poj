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

int i,j,k,m,n,l;
char s[N+10], t[N+10];
int f[N+10][N+10];
int d[5][5]={5,-1,-2,-1,-3,
            -1,5,-3,-2,-4,
            -2,-3,5,-2,-2,
            -1,-2,-2,5,-1,
            -3,-4,-2,-1,0};
        
void gao(char &c){
    if (c=='A') c=0;
    else if (c=='C') c=1;            
    else if (c=='G') c=2;
    else c=3;
}

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d%s%d%s", &n, s, &m, t);
        rep(i, n) gao(s[i]);
        rep(i, m) gao(t[i]);
        
        repf(i, 1, n) f[i][0]=f[i-1][0]+d[s[i-1]][4];
        repf(j, 1, m) f[0][j]=f[0][j-1]+d[t[j-1]][4];
        
        repf(i, 1, n) repf(j, 1, m){
            f[i][j]=max(f[i-1][j]+d[s[i-1]][4], f[i][j-1]+d[t[j-1]][4]);
            checkmax(f[i][j], f[i-1][j-1]+d[s[i-1]][t[j-1]]);
        }

        printf("%d\n", f[n][m]);
    }
    return 0;
}

