/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
int n,m,k;
long long f[21][5000][21];
char str[25][25];
int main()
{
	int limit,cnt;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		limit=1<<m;
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str[i]);
			for(int j=0;j<=k;j++)
				for(int S=0;S<limit;S++)
					if(f[i-1][S][j])
						f[i][S][j]=f[i-1][S][j];
			for(int S2=0;S2<limit;S2++)
			{
				cnt=0;
				for(int j=0;j<m;j++)
					if((S2>>j)&1)
						cnt++;
				for(int j=cnt;j<=k;j++)
					for(int S=0;S<limit;S++)
						if(f[i-1][S][j-cnt])
							f[i][S
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

