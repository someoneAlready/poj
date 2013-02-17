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
char a[N+10][11], b[N+10][11];
char s[100];

template<int SZ>
class Hash{
    int h[SZ+10];
public:
    void init(){ fill(h, -1); }
    int gao(char s[]){
        int ret=0, n=strlen(s);
        rep(i, n) ret=(ret*131+s[i])%SZ;
        return ret;
    }
    void ins(char s[], int i){
        int k=gao(s);
        while (h[k]!=-1 && strcmp(b[h[k]], s)!=0)
            k=(k+1)%SZ;
        h[k]=i;
    }
    int find(char s[]){
        int k=gao(s);
        while (h[k]!=-1 && strcmp(b[h[k]], s)!=0)
            k=(k+1)%SZ;
        return h[k];
    }
};
Hash<1000003> hash;

int main(){    
    hash.init();
    while (gets(s)!=NULL && strlen(s)>0){
        n++;
        sscanf(s, "%s%s", a[n], b[n]);
        hash.ins(b[n], n);
    }
    while (gets(s)!=NULL){
        k=hash.find(s);
        if (k!=-1) puts(a[k]);
        else puts("eh");
    }
    return 0;
}
