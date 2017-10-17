#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[10][10],num[10];
void prepare()
{
	for(int i=0;i<=9;i++)f[1][i]=1;
	f[1][4]=0;
	for(int i=2;i<=9;i++)
		for(int j=0;j<=9;j++)
			if(j!=4)
				for(int k=0;k<=9;k++)
					if(k!=4&&(j!=6||k!=2))
						f[i][j]+=f[i-1][k];
	return;
}
int calc(int x)
{
	int sum=0;
	for(num[0]=0;x;x/=10)num[++num[0]]=x%10;
	for(int i=1;i<num[0];i++)
		for(int j=1;j<=9;j++)
			if(j!=4)
				sum+=f[i][j];
	for(int i=1;i<num[num[0]];i++)
		if(i!=4)
			sum+=f[num[0]][i];
	if(num[num[0]]!=4)
		for(int i=num[0]-1;i;i--)
		{
			for(int j=0;j<num[i];j++)
				if(j!=4&&(num[i+1]!=6||j!=2))
					sum+=f[i][j];
			if(num[i]==4||(num[i+1]==6&&num[i]==2))
				break;
		}
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	prepare();
	while(true)
	{
		scanf("%d%d",&a,&b);
		if(!a&&!b)
			break;
		printf("%d\n",calc(b+1)-calc(a));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

