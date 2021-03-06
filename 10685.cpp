#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>
#include <ctime>
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int n, m, ans, i, num;
vi p, sz;
map<string, int> mp;
char a[33], b[33];

void initSet(int n)
{
    for(i=1;i<=n;++i)
        p[i]=i, sz[i]=1;
    ans=1;
}
int findSet(int i)
{
    return (p[i]==i)?i:p[i]=findSet(p[i]);
}
bool SameSet(int i, int j)
{
    return findSet(i)==findSet(j);
}
void Union(int i, int j)
{
    if(!SameSet(i, j))
    {
        sz[findSet(j)]+=sz[findSet(i)];
        p[findSet(i)]=p[findSet(j)];
        ans=max(sz[findSet(j)], ans);
    }
}
int main()
{
    p.clear(), sz.clear();
    p.assign(33333, 0), sz.assign(33333, 0);
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(!n && !m)
            break;
        initSet(n+1);
        num=1;
        while(n--)
        {
            scanf("%s", a);
            mp[a]=num++;
        }
        while(m--)
        {
            scanf("%s %s", a, b);
            Union(mp[a], mp[b]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
