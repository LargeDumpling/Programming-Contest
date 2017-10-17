/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History: 
	2015-11-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num[15][105],f[15][105],next[15][105],s[110];
void print(int x,int k)
{
	if(k==m+1)return;
	printf("%d",x+1);
	if(k!=m)printf(" ");
	print(next[x][k],k+1);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int aNs,row[3];
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=0;i<n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&num[i][j]);
		memset(f,127,sizeof(f));
		for(int i=0;i<n;i++)f[i][m+1]=0;
		for(int i=m;i;i--)
		{//ап
			for(int j=0;j<n;j++)
			{
				row[0]=(j+n-1)%n;
				row[1]=j;
				row[2]=(j+1)%n;
				sort(row,row+3);
				for(int l=0;l<3;l++)
					if(f[row[l]][i+1]+num[j][i]<f[j][i])
					{
						f[j][i]=f[row[l]][i+1]+num[j][i];
						next[j][i]=row[l];
					}
			}
		}
		aNs=0;
		for(int i=1;i<n;i++)
			if(f[i][1]<f[aNs][1])
				aNs=i;
		print(aNs,1);
		printf("\n%d\n",f[aNs][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

