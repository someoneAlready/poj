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
#define N 1024 

int i,j,k,m,n,l;

template<int SZ>
class BIT{
    int a[SZ+10][SZ+10];
public:
    void clear(){ clr(a, 0); }
    void insY(int x, int y, int k){
        while (y<=n)           
            a[x][y]+=k, y+=y&-y;
    }
    void ins(int x, int y, int k){
        while (x<=n)
            insY(x, y, k), x+=x&-x;
    }
    int qryY(int x, int y){
        int ret=0;
        while (y>0)            
            ret+=a[x][y], y-=y&-y;
        return ret;
    }
    int qry(int x, int y){
        int ret=0;
        while (x>0)
            ret+=qryY(x, y), x-=x&-x;
        return ret;
    }
};


BIT<N> bit;

int main(){
    scanf("%d%d", &i, &n); 
    bit.clear();
    while (~scanf("%d", &m) && m!=3){
        if (m==1){
            scanf("%d%d%d", &i, &j, &k), i++, j++;
            bit.ins(i, j, k);
        }
        else{
            int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1++, y1++, x2++, y2++;
            printf("%d\n", bit.qry(x2, y2)-bit.qry(x1-1, y2)-bit.qry(x2, y1-1)+bit.qry(x1-1,y1-1));
        }
    }
    return 0;
}

