#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,m,height[1050],ans[4050],s[1050];
char map[1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int temx,temy,k;
	scanf("%d",&T);
	while(T--)
	{
		memset(height,0,sizeof(height));
		memset(ans,0,sizeof(ans));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",map+1);
			s[0]=0;
			for(int j=1;j<=m;j++)
			{
				if(map[j]=='#')
				{
					height[j]=0;
					s[0]=0;
					continue;
				}
				height[j]++;
				if(!s[0])
					s[++s[0]]=j*10000+height[j];
				else
				{
					temy=height[j];temx=j;
					while(s[0]&&temy<=s[s[0]]%10000)temx=s[s[0]--]/10000;
					if(!s[0]||(s[s[0]]%10000-s[s[0]]/10000)<temy-temx)
						s[++s[0]]=temx*10000+temy;
				}
				ans[(j+1+s[s[0]]%10000-s[s[0]]/10000)<<1]++;
			}
		}
		for(int i=0;i<4049;i++)
			if(ans[i])
				printf("%d x %d\n",ans[i],i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

