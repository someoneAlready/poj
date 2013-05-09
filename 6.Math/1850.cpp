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
#define N 10
#define M 26
int i,j,k,m,n,l;
char s[N+10];
int d[]={0,26,325,2600,14950,65780,230230,657800,1562275,3124550,5311735};
int f[N+10][M+10];
int now, end;

void gao(int dep){
    if (dep==1){
        rep(j, M) f[1][j]=1;
        return;
    }
    gao(dep-1);
    rep(i, M) repf(j, i+1, M-1) f[dep][i]+=f[dep-1][j];
}

void init(){
    gao(10);
}

int solve(){
    n=strlen(s);
    rep(i, n) if (i && s[i-1]>=s[i]) return 0;
    int ret=0;
    repf(i, 1, n-1) ret+=d[i];
    rep(i, n){
        repf(j, (i?s[i-1]-'a'+1:0), s[i]-'a'-1)
            ret+=f[n-i][j];
    }
    ret++;
    return ret;
}

int main(){
    init();
    gets(s);
    cout<<solve()<<endl;
}
