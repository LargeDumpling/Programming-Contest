#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) (a<b?a:b)
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("Floyd.out","w",stdout);
    int n,f[105][105],q,a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>f[i][j];
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(k==i||k==j||i==j)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b;
        cout<<f[a][b]<<"\n";
    }
	fclose(stdin);
	fclose(stdout);
    return 0;
}
