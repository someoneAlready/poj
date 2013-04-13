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
#define N 26
#define M 2000

int i,j,k,m,n,l;
int a[N+10]; 
char s[M+10];
int f[M+10][M+10];

int main(){
    while (~scanf("%d%d", &n, &m)){
        clr(s, 0);
        rep(i, m){
            s[i]=getchar();
            while (!isalpha(s[i])) s[i]=getchar();
        }
        rep(i, n){
            char c=getchar();
            while (!isalpha(c)) c=getchar();
            scanf("%d%d", &j, &k), a[c-'a']=min(j, k);
        }
        clr(f, 0);
        repf(i, 1, m) repf(j, 1, m){
            f[i][j]=max(f[i-1][j], f[i][j-1]);
            if (s[i-1]==s[m-j])
                checkmax(f[i][j], f[i-1][j-1]+a[s[i-1]-'a']);

        }
        int tot=0;        
        rep(i, m) tot+=a[s[i]-'a'];

        printf("%d\n", tot-f[m][m]);
    }    
    return 0;
}

