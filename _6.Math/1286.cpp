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
#define N 24

int i,j,k,m,n,l;
int a[N+10];
bool v[N+10];
ll ans[N+10];

int gao(int a[], int n){
    int ret=0; clr(v, 0);
    repf(i, 1, n) if (!v[i]){
        ret++; k=i;
        while (!v[k]) v[k]=1, k=a[k];
    }
    return ret;
}

int main(){
    repf(n, 1, N){
        repf(i, 1, n) a[i]=i;
        rep(i, n){
            k=a[n];
            repd(j, n, 2) a[j]=a[j-1];
            a[1]=k;
            ans[n] += pow(3., gao(a, n));
        }
        
        repf(i, 1, n) a[i]=n+1-i;
        rep(i, n){
            k=a[n];
            repd(j, n, 2) a[j]=a[j-1];
            a[1]=k;
            ans[n] += pow(3., gao(a, n));
        }
        
        ans[n]/=n*2;
    }
    while (~scanf("%d", &n) && n!=-1){
        cout<<ans[n]<<endl;
    }
    return 0;
}
