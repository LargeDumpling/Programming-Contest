/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,num[100050];
char str[100050];
int main()
{
	freopen("stations.in","r",stdin);
	int last,mIn,mAx,ans=0;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		scanf("%s",str+1);
		memset(num,0,sizeof(num));
		num[0]=last=0;
		for(int i=1;i<=n+1;i++) if(str[i]=='+'||i==n+1)
		{
			num[++num[0]]=i-last-1;
			last=i;
		}
		num[mIn=num[0]+1]=2147483640;
		num[mIn+1]=0;
		for(int i=1;i<num[0];i++)
		{
			if(i==1||i==num[0]-1)
			{
				if(mIn==1||mIn==num[0]-1)
				{
					if(num[i]+num[i+1]+1<num[mIn]+num[mIn+1]+1)
						mIn=i;
				}
				else if(num[i]+num[i+1]+1<((num[mIn]+num[mIn+1]+2)>>1))
					mIn=i;
			}
			else
			{
				if(mIn==1||mIn==num[0]-1)
				{
					if(((num[i]+num[i+1]+2)>>1)<num[mIn]+num[mIn+1]+1)
						mIn=i;
				}
				else if(((num[i]+num[i+1]+2)>>1)<((num[mIn]+num[mIn+1]+2)>>1))
					mIn=i;
			}
		}
		num[mIn]+=num[mIn+1]+1;
		for(int i=mIn+1;i<num[0];i++)
			num[i]=num[i+1];
		num[0]--;
		num[mAx=num[0]+1]=-2147483640;
		for(int i=1;i<=num[0];i++)
		{
			if(i==1||i==num[0])
			{
				if(mAx==1||mAx==num[0])
				{
					if((num[mAx]+1)/3<(num[i]+1)/3)
						mAx=i;
				}
				else if((num[mAx]+1)/2<(num[i]+1)/3)
					mAx=i;
			}
			else
			{
				if(mAx==1||mAx==num[0])
				{
					if((num[mAx]+1)/3<(num[i]+1)/2)
						mAx=i;
				}
				else if((num[mAx+1])/2<(num[i]+1)/2)
					mAx=i;
			}
		}
		ans=-2147483640;
		for(int i=1;i<=num[0];i++)
		{
			if(i==mAx)
			{
				if(mAx==1||mAx==num[0])
					ans=max(ans,(num[mAx]+1)/3);
				else ans=max(ans,(num[mAx]+1)/2);
			}
			else ans=max(ans,(num[i]+1)/2);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

