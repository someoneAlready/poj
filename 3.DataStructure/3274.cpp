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
#define N 100000

int i,j,k,m,n,l;
int a[N+10][40], c[N+10][40];

bool equal(int a[], int b[]){
    rep(i, m) if (a[i]!=b[i]) return false;
    return true;
}

template <int SZ>
class Hash{
    int h[SZ+10];
public:    
    void init(){fill(h, -1);}
    int gao(int a[]){
        int ret=0;
        rep(j, m) ret=(ret*131+a[j])%SZ;
        return ret;
    }
    int find(int x[]){
        int k=gao(x);
        while (h[k]!=-1 && !equal(x, a[h[k]]))
            k=(k+1)%SZ;
        return h[k];
    }
    void ins(int x[], int i){
        int k=gao(x);
        while (h[k]!=-1 && !equal(x, a[h[k]]))
            k=(k+1)%SZ;
        h[k]=i;
    }
};

Hash<1000003> hash;
int main(){
    while (~scanf("%d%d", &n, &m)){
        hash.init();
        int ans=0;
        repf(i, 1, n){
            scanf("%d", &k);
            int l=INT_MAX;
            hash.ins(a[0], 0);
            rep(j, m) c[i][j]=c[i-1][j]+((k&(1<<j))?1:0), checkmin(l, c[i][j]);
            rep(j, m) a[i][j]=c[i][j]-l;
            int w=hash.find(a[i]);            
            if (w!=-1){
                 checkmax(ans, i-w);
            }
            else hash.ins(a[i], i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
