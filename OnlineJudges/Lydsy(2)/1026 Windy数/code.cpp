#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int A,B,f[15][10];
void prepare()
{
	for(int i=0;i<=9;i++)
		f[1][i]=1;
	for(int i=2;i<=14;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				if(abs(j-k)>=2)
					f[i][j]+=f[i-1][k];
	return;
}
int calc(int x)
{
	int sum=0,num[15]={0};
	for(int temp=x;temp;temp/=10)num[++num[0]]=temp%10;
	for(int i=1;i<num[0];i++)
		for(int j=1;j<=9;j++)
			sum+=f[i][j];
	for(int i=1;i<num[num[0]];i++)
		sum+=f[num[0]][i];
	for(int i=num[0]-1;i;i--)
	{
		for(int j=0;j<num[i];j++)
			if(abs(j-num[i+1])>=2)
				sum+=f[i][j];
		if(abs(num[i]-num[i+1])<2)
			break;
	}
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&A,&B);
	prepare();
	printf("%d",calc(B+1)-calc(A));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

