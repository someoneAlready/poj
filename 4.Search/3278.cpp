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
int v[N+10];
int d[3][2]={ 1,1, 1,-1, 2,0 };

int bfs(){
    queue<int> q; fill(v, -1);
    q.push(n), v[n]=0;

    while (!q.empty()){
        rep(k, 3){
            j=q.front()*d[k][0]+d[k][1];

            if (j>=0 && j<=N && v[j]==-1){
                v[j]=v[q.front()]+1;
                q.push(j);
                if (j==m) return v[m];
            }
        }
        q.pop();
    }
    return v[m];
}

int main(){
    while (~scanf("%d%d", &n, &m)){
        printf("%d\n", bfs());
    }
    return 0;
}
