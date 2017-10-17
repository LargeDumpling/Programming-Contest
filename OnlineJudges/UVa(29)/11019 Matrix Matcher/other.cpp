#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
#define B1 10000007
#define B2 100000007
#define N 1234
typedef unsigned long long ull;
char s[N][N];
char s1[N][N];
ull t,mp[N][N],mpp[N][N];
int x,y;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("other.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) scanf("%s",s[i]);
        int x,y;
        scanf("%d%d",&x,&y);
        for (int i=0;i<x;i++) scanf("%s",s1[i]);

        ull p=0;
        for (int i=0;i<x;i++)
        {
            ull tmp=0;
            for (int j=0;j<y;j++)
            tmp=tmp*B1+s1[i][j];
            p=p*B2+tmp;
        }

        ull t=1;
        int ans=0;

        for (int i=0;i<y;i++) t*=B1;
        for (int i=0;i<n;i++)
        {
            ull a=0;
            for (int j=0;j<y;j++) a=a*B1+s[i][j];
            mp[i][y-1]=a;
            for (int j=y;j<=m;j++)
            mp[i][j]=mp[i][j-1]*B1-s[i][j-y]*t+s[i][j];
        }
        t=1;
        for (int i=0;i<x;i++) t*=B2;

        for (int i=y-1;i<=m;i++)
        {
            ull tmp=0;
            for (int j=0;j<x;j++) tmp=tmp*B2+mp[j][i];
            mpp[x-1][i]=tmp;
            if (tmp==p) ans++;
            for (int j=x;j<n;j++)
            {
                mpp[j][i]=mpp[j-1][i]*B2-mp[j-x][i]*t+mp[j][i];
                if (mpp[j][i]==p) ans++;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
   return 0;
}
