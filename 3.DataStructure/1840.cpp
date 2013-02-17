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
#define repf(i, a, b) for ( i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define fill(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 5
int i,j,k,m,n,l;
int a[N+10], x[N+10];

bool input(){
    repf(i, 1, 5) if (scanf("%d", &a[i])==EOF) return false;
    return true;
}

template<int SZ>
class Hash{
    int h[SZ+10], f[SZ+10];
public:
    void init(){
        fill(h, -1), fill(f, 0);
    }
    int gao(int k){
        return (k<0?-k:k)%SZ;
    }
    void ins(int x){
        int k=gao(x);
        while (h[k]!=-1 && h[k]!=x)
            k=(k+1)%SZ;
        h[k]=x, f[k]++;
    }
    int find(int x){
        int k=gao(x);
        while (h[k]!=-1 && h[k]!=x)
            k=(k+1)%SZ;
        return f[k];
    }
};

Hash<1000003> hash;

int main(){
    while (input()){
        hash.init();
        ll ans=0, tot=0;
        repf(x[4], -50, 50) if (x[4]!=0)
        repf(x[5], -50, 50) if (x[5]!=0){
            k=0;
            repf(i, 4, 5)
                k+=a[i]*x[i]*x[i]*x[i];
            hash.ins(-k);
        }        
        
        repf(x[1], -50, 50) if (x[1]!=0)
        repf(x[2], -50, 50) if (x[2]!=0)
        repf(x[3], -50, 50) if (x[3]!=0){
            k=0;
            repf(i, 1, 3) k+=a[i]*x[i]*x[i]*x[i];
            
            ans+=hash.find(k);
        }

        cout<<ans<<endl;
    }
    return 0;
}
