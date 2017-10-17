#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,rad[2000050],lenth,r,id,ans;
char tex[2000050];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
		ans=0;
        scanf("%s",tex);
		lenth=strlen(tex);
		tex[2*lenth]='#';
		for(int j=lenth-1;j>=0;j--)
		{
			tex[2*j+1]=tex[j];
			tex[2*j]='#';
		}
		rad[0]=0;
		r=0;
		id=0;
		for(int j=1;j<lenth*2;j++)
		{
			rad[j]=min(rad[2*id-j],r-j);
			while(rad[j]<j&&tex[j-rad[j]-1]==tex[j+rad[j]+1])rad[j]++;
			if(j+rad[j]>r)
			{
				r=j+rad[j];
				id=j;
			}
		}
		for(int j=0;j<lenth*2;j++)
			if(j&1&&(rad[j]/2)*2+1>ans)
				ans=(rad[j]/2)*2+1;
			else if(!(j&1)&&(rad[j]+1)/2*2>ans)
				ans=(rad[j]+1)/2*2;
		printf("%d\n",ans);
    }
	return 0;
}

