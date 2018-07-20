#include <cstdio>
#define ll long long
ll const INF = 1e16;
ll n, ans, ma;
int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
 
void DFS(int pos, ll val, ll num)
{
    if(val > n || pos > 14)
        return;
    if(num > ma || num == ma && val < ans)
    {
        ma = num;
        ans = val;
    }
    for(int i = 1; i <= 53; i++)
    {
        if(val > INF / p[pos])
            break;
        val *= p[pos];
        DFS(pos + 1, val, num * (i + 1));
    }
    return;
}
 
int main()
{
    while(scanf("%lld", &n) != EOF)
    {
        ma = 0;
        DFS(0, 1, 1);
        printf("%lld\n", ans);
    }
}

