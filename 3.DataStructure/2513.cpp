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
#define N 500000

int i,j,k,m,n,l;
char b[N+10][11];
int x[N+10], u[N+10], fa[N+10], deg[N+10];
int ufs=0;

char s[101];

int find(int i){
    if (fa[i]==i) return i;
    return fa[i]=find(fa[i]);
}

bool solve(){
    int tot=0;
    rep(i, m+1)
         if (deg[i]&1) tot++;
    if (tot!=2 && tot!=0) return false;
    if (ufs==m) return true;
    return false;
}

bool cmp(int i, int j){
    int k=strcmp(b[i], b[j]);
    if (k<0) return true;
    return false;
}

int main(){
   // freopen("input.txt", "r", stdin);
    char ch;
    while ((ch=getchar())!=EOF){
        if (isalpha(ch)) b[n][k++]=ch;
        else{
            if (k!=0) n++, k=0;
        }
    }
    if (k!=0) n++;
    rep(i, n) x[i]=i;
    sort(x, x+n, cmp);
    m=0;
    repf(i, 0, n-1){
        if (i && strcmp(b[x[i]], b[x[i-1]])!=0) m++;
        u[x[i]]=m;
    }
    rep(i, n) fa[i]=i;
    i=0;
    
    
    while (i<n){
        deg[u[i]]++, deg[u[i+1]]++;
        j=find(u[i]), k=find(u[i+1]);
        if (j!=k) fa[j]=k, ufs++;
        i+=2;
    }

    if (solve()) puts("Possible");
    else puts("Impossible");
  //  while (1);
    return 0;
}
