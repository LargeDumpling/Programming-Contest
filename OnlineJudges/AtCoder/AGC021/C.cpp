/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char map[1050][1050];
int N,M,A,B,NN,MM;
int main()
{
	bool flag;
	scanf("%d%d%d%d",&N,&M,&A,&B);
	NN=N; MM=M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			map[i][j]='.';
	if(N*M<(A+B)*2)
		printf("NO");
	else
	{
		flag=true;
		while(flag)
		{
			flag=false;
			if(N%2==0&&N/2<=B)
			{
				for(int i=1;i<=N;i++)
				{
					map[i][M]=(i&1)?'^':'v';
					flag=true;
				}
				B-=N/2;
				M--;
			}
			else if(M%2==0&&M/2<=A)
			{
				for(int i=1;i<=M;i++)
				{
					map[N][i]=(i&1)?'<':'>';
					flag=true;
				}
				A-=M/2;
				N--;
			}
			else if(2<=N&&M<=B)
			{
				for(int i=1;i<=M;i++)
				{
					map[N-1][i]='^';
					map[N][i]='v';
					flag=true;
				}
				B-=M;
				N-=2;
			}
			else if(2<=M&&N<=A)
			{
				for(int i=1;i<=N;i++)
				{
					map[i][M-1]='<';
					map[i][M]='>';
					flag=true;
				}
				A-=N;
				M-=2;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

