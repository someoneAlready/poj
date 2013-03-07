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
#define N 300
#define M 600
#define L 25

int i,j,k,m,n,l;
int f[N+10];
char s[N+10];
string t[M+10];
int len[M+10], g[M+10][N+10];

void init(){
    fill(g, -1);
    rep(i, m){
        rep(j, n){
            int l=0;
            repf(k, j, n-1){
                if (t[i][l]==s[k]) l++;
                if (l==len[i]){
                    g[i][j]=k; break;
                }
            }
        }
    }
}

int gao(int l, int r){
    l--, r--;
    rep(i, m) if (g[i][l]!=-1 && g[i][l]<=r) return r-l+1-len[i];
    return r-l+1;
}

int dp(){
    fill(f, -1), f[0]=0;
    repf(i, 1, n){
        repf(j, 0, i-1) if (f[i]==-1 || f[j]<f[i])
             _checkmin(f[i], f[j]+gao(j+1, i));        
    }
    return f[n];
}
    
bool cmp(string s, string t){ return sz(s)>sz(t);}

int main(){
    while (~scanf("%d%d", &m, &n)){
        gets(s);
        while (strlen(s)==0) gets(s);
        
        rep(i, m) cin>>t[i];
        sort(t, t+m, cmp);
        rep(i, m) len[i]=sz(t[i]);
        init();
        printf("%d\n", dp());
    }
    return 0;
}

