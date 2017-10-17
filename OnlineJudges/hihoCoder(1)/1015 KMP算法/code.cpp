#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[10050],T[1000050];
int n,lenth,L,pre[10050]/*,sum[10050]*/,ans;
void KMP()
{
    // memset(sum,0,sizeof(sum));
    lenth=strlen(tex);
    L=strlen(T);
    ans=0;
    pre[0]=-1;
    for(int i=1,k=-1;i<lenth;i++)
    {
        while(k>=0&&tex[k+1]!=tex[i])k=pre[k];
        if(tex[k+1]==tex[i])k++;
        pre[i]=k;
    }
    for(int i=0,k=-1;i<L;i++)
    {
        while(k>=0&&tex[k+1]!=T[i])k=pre[k];
        if(tex[k+1]==T[i])
        {
            k++;
            // sum[k]++;
            if(k==lenth-1)
            {
                ans++;
                k=pre[k];
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",tex,T);
        KMP();
        // for(int j=lenth-1;j>=0;j--)
            // sum[pre[j]]+=sum[j];
        printf("%d\n",ans);
    }
    return 0;
}

