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

struct P{
    int ai, pi;
    void input(){ scanf("%d%d", &ai, &pi); }
};

int i,j,k,m,n,l;
P a[N+10];
int f[N+10];

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d", &n);
        repf(i, 1, n) a[i].input();
        reverse(a+1, a+1+n);
        fill(f, -1), f[0]=0;
        repf(i, 1, n){
            int k=0;            
            repd(j, i, 1){
                k+=a[j].ai;
                _checkmin(f[i], f[j-1]+(10+k)*a[j].pi);
            }
        }
        printf("%d\n", f[n]);
    }
    return 0;
}

