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
			//��һ�׶� ɱ��
			for(int i=2;i<=n;i++)
			{
				if(exist[i]!=cAse||!beat[1][i])continue;
				for(int j=2;j<=n;j++)
					if(exist[j]==cAse&&beat[j][1]&&beat[i][j])
					{
						printf("%d %d\n",i,j);
						exist[i]>>=1;//i�ɽ�����һ�֣��˳���ǰ��
						exist[j]<<=1;//j�˳�
						i=j=n+1;
					}
			}
			//�ڶ��׶� 1��ɱ
			for(int i=2;i<=n;i++)
			{
				if(exist[i]!=cAse||!beat[1][i])continue;
				printf("%d %d\n",1,i);
				exist[1]>>=1;
				exist[i]<<=1;
				break;
			}
			//�����׶� �������ɱ
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
			//���Ľ׶� ���Ҷ�
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

