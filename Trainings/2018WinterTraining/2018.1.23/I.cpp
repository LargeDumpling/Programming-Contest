/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jp
{
	int t,v;
}s[MAXN];
int n,m,f[MAXN][18][2],S[MAXN];
char com1[5],com2[5];
int mIn(int l,int r)
{
	int t=r-l,ans=f[l][0][0];
	for(int i=0;i<18;i++) if((t>>i)&1)
	{
		ans=min(ans,f[l][i][0]);
		l+=(1<<i);
	}
	return ans;
}
int mAx(int l,int r)
{
	int t=r-l,ans=f[l][0][1];
	for(int i=0;i<18;i++) if((t>>i)&1)
	{
		ans=mAx(ans,f[l][i][1]);
		l+=(1<<i);
	}
	return ans;
}
int main()
{
	int x,l,r,cnt;
	while(scanf("%d",&n)!=-1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&s[i].t,&s[i].v);
			S[i]=S[i-1]+s[i].v;
			f[i][0][0]=f[i][0][1]=s[i].v;
		}
		for(int k=1;k<18;k++)
		{
			for(int i=1;i+(1<<k)-1<=n;i++)
			{
				f[i][k][0]=min(f[i][k-1][0],f[i+(1<<(k-1))][k-1][0]);
				f[i][k][1]=max(f[i][k-1][1],f[i+(1<<(k-1))][k-1][1]);
			}
		}
		scanf("%d",&m);
		while(m--)
		{
			cnt=0;
			l=1;
			scanf("%s%s%d",com1,com2,&x);
			for(r=1;r<=n;r++)
			{
				while(l<r&&x<(s[r].t-s[l].t)) l++;
				if(l<r&&(s[r].t-s[l].t)<=x)
				{
					switch(com2[1])
					{
						case 'i':
							if(com1[0]=='g')
							{
								if(mIn(l,r-1)<s[r].v)
									cnt++;
							}
							else if(com1[0]=='l')
							{
								if(s[r].v<mIn(l,r-1))
									cnt++;
							}
							break;
						case 'a':
							if(com1[0]=='g')
							{
								if(mAx(l,r-1)<s[r].v)
									cnt++;
							}
							else if(com1[0]=='l')
							{
								if(s[r].v<mAx(l,r-1))
									cnt++;
							}
							break;
						case 'v':
							if(com1[0]=='g')
							{
								if(S[r-1]-S[l-1]<s[r].v*(r-l))
									cnt++;
							}
							else if(com1[0]=='l')
							{
								if(s[r].v*(r-l)<S[r-1]-S[l-1])
									cnt++;
							}
							break;
						default:
							break;
					}
				}
			}
			printf("%d\n",cnt);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

