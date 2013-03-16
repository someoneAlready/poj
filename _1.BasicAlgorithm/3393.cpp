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
#define N 10000
#define M 12

int i,j,k,m,n,l;
int MON[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int firstDay[N+10][M+10], lastDay[N+10][M+10];  
int lucky[N+10][M+10], good[N+10][M+10];

bool isLeap(int year){
    if (year==1700) return true;
    if (year<1582 && year%4==0) return true;
    if (year>1582 && ( (year%4==0 && year%100!=0) || year%400==0)) return true;
    return false;
}

void init(){
    int day=2, delta;
    repd(year, 2013, 0)
        repd(month, 12, 1){
            lastDay[year][month]=day;
            if (year==1752 && month==9) delta=30-11;
            else if (month==2){
                if (isLeap(year)) delta=29;
                else delta=28;
            }
            else delta=MON[month];
            
            day=(day-delta+70)%7;
        }

    
    day=(lastDay[0][12]+1)%7;
    repf(year, 1, 10000)
        repf(month, 1, 12){
            firstDay[year][month]=day;
            if (year==1752 && month==9) delta=30-11;
            else if (month==2){
                if (isLeap(year)) delta=29;
                else delta=28;
            }
            else delta=MON[month];
            
            day=(day+delta)%7;
            lastDay[year][month]=(day+7-1)%7;
        }
 //   cout<<firstDay[1752][9]<<' '<<lastDay[1752][9]<<endl;
    int LUCKY[]={1,0,0,0,0,1,1};
    int GOOD[]={1,1,0,0,0,0,1};
    fill(lucky, 0), fill(good, 0);
    int y=0, m=0;
    repf(year, 1, 10000) repf(month, 1, 12){
        lucky[year][month]=lucky[y][m]+LUCKY[lastDay[year][month]];
        good[year][month]=good[y][m]+GOOD[firstDay[year][month]];
        y=year, m=month;
    }
}

int main(){
    init();
    int tests;
    scanf("%d", &tests);    
    while (tests--){
        int y1, m1, y2, m2;
        scanf("%d%d%d%d", &y1, &m1, &y2, &m2);
        if (--m1==0) y1--, m1=12;
        printf("%d %d\n", lucky[y2][m2]-lucky[y1][m1], good[y2][m2]-good[y1][m1]);
        
    }
    return 0;
}

