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
#define N 5000
int i,j,k,m,n,l;
char s[N+10], t[N+10];
short int f[N+10][N+10];

int main(){
    while (~scanf("%d", &n)){
        scanf("%s", s);
        memcpy(t, s, sizeof(s)), reverse(t, t+n);
        
        repf(i, 1, n) repf(j, 1, n){
            f[i][j]=max(f[i][j-1], f[i-1][j]);
            if (s[i-1]==t[j-1]) checkmax(f[i][j],(short int)( f[i-1][j-1]+1));
        }
        printf("%d\n", n-f[n][n]);
    }
    return 0;
}

