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
char s[N+10], a[N+10], b[N+10], ra[N+10], rb[N+10], t[N+10];
int ans;
char A[N*N+10][N+10];
 
template <int SZ>
class Hash{
    int h[SZ+10];
public:
    void init(){fill(h, -1);}
    int gao(char * a){
        int ret=0, m=strlen(a);
        rep(j, m) ret=(ret*131+a[j])%SZ;
        return ret;
    }

    void insert(char *x, int i){
        int k=gao(x);
        while (h[k]!=-1 && strcmp(x, A[h[k]])!=0)
            k=(k+1)%SZ;
        if (h[k]==-1){
            h[k]=i; ans++;
        }
    }
};

Hash <1000003> hash;

void combine(char *a, char *b, char ret[N+10]){
     memset(ret, 0, ret[0]*(N+10));
     int n=strlen(a), m=strlen(b);
     memcpy(ret, a, n), memcpy(ret+n, b, m);
}

int gao(char *s){
    hash.init();
    int tot=0; ans=0;
    memcpy(A[tot], s, sizeof(A[tot])), hash.insert(A[tot], tot);

    repf(i, 1, n-1){
        fill(a, 0), fill(b, 0), fill(ra, 0), fill(rb, 0);
        rep(j, i) a[j]=s[j];
        repf(j, i, n-1) b[j-i]=s[j];

        memcpy(ra, a, sizeof(a)), memcpy(rb, b, sizeof(b));
        reverse(ra, ra+i), reverse(rb, rb+n-i);
        
        combine(ra, b, A[++tot]), hash.insert(A[tot], tot);
        combine(ra, rb, A[++tot]), hash.insert(A[tot], tot);
        combine(a, rb, A[++tot]), hash.insert(A[tot], tot);
        combine(b, a, A[++tot]), hash.insert(A[tot], tot);
        combine(rb, a, A[++tot]), hash.insert(A[tot], tot);
        combine(rb, ra, A[++tot]), hash.insert(A[tot], tot);
        combine(b, ra, A[++tot]), hash.insert(A[tot], tot);        
    }
    return ans;
}

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%s", s);
        n=strlen(s);
        printf("%d\n", gao(s));
        fill(s, 0);
    }
    return 0;
}

