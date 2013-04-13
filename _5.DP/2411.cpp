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
#define N 11

int i,j,k,m,n,l;
ll f[N+10][N+10][1<<N];


int main(){

        
    while (~scanf("%d%d", &n, &m) && n+m){    
        clr(f, 0);
        
        f[0][m][0]=1;
        repf(i, 1, n){
            memcpy(f[i][0], f[i-1][m], sizeof(f[i][m]));
            repf(j, 1, m) {
                rep(k, 1<<m){ 
                    if (k&(1<<j-1)){
                        f[i][j][k]=f[i][j-1][k-(1<<j-1)];
//                        if (j!=1) if (k&(1<<j-2)) f[i][j][k]+=f[i][j-2][k];
                    }
                    else{
                        f[i][j][k]=f[i][j-1][k+(1<<j-1)];
                        if (j!=1) if (!(k&(1<<j-2))) f[i][j][k]+=f[i][j-2][k];
                    }
//                    cout<<f[i][j][k]<<' ';
                }
  //              cout<<endl;
            }

        }
        cout<<f[n][m][0]<<endl;
    }
    return 0;
}

