#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
bool beat[1050][1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char sit[1050];
	int exist[1050];
	while(scanf("%d",&n)==1)
	{
		memset(exist,true,sizeof(exist));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",sit+1);
			for(int j=1;j<=n;j++)
				beat[i][j]=(sit[j]=='1');
			exist[i]=n;
		}
		for(int cAse=n;cAse;cAse>>=1)
		{
			//第一阶段 杀黑
			for(int i=2;i<=n;i++)
			{
				if(exist[i]!=cAse||!beat[1][i])continue;
				for(int j=2;j<=n;j++)
					if(exist[j]==cAse&&beat[j][1]&&beat[i][j])
					{
						printf("%d %d\n",i,j);
						exist[i]>>=1;//i可进入下一轮，退出当前轮
						exist[j]<<=1;//j退出
						i=j=n+1;
					}
			}
			//第二阶段 1乱杀
			for(int i=2;i<=n;i++)
			{
				if(exist[i]!=cAse||!beat[1][i])continue;
				printf("%d %d\n",1,i);
				exist[1]>>=1;
				exist[i]<<=1;
				break;
			}
			//第三阶段 黑自相残杀
			for(int i=2;i<=n;i++)
			{
				if(exist[i]!=cAse||!beat[i][1])continue;
				for(int j=2;j<=n;j++)
					if(exist[j]==cAse&&beat[j][1]&&beat[i][j])
					{
						printf("%d %d\n",i,j);
						exist[i]>>=1;
						exist[j]<<=1;
						i=j=n+1;
					}
			}
			//第四阶段 大乱斗
			for(int i=2;i<=n;i++)
			{
				if(exist[i]!=cAse)continue;
				for(int j=2;j<=n;j++)
				{
					if(exist[j]!=cAse||(!beat[i][j]&&!beat[j][i]))continue;
					if(beat[i][j])
					{
						printf("%d %d\n",i,j);
						exist[i]>>=1;
						exist[j]<<=1;
					}
					else
					{
						printf("%d %d\n",j,i);
						exist[j]>>=1;
						exist[i]<<=1;
					}
					i=j=n+1;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

