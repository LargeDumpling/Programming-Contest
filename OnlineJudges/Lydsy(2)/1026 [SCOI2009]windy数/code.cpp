#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int A,B,ans,f[11][10],num[11];
void pRe()
{
	for(int i=0;i<=9;i++)
		f[1][i]=1;
	for(int k=2;k<=10;k++)
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				if(abs(i-j)>=2)
					f[k][i]+=f[k-1][j];
	return;
}
int calc(int x)
{
	ans=num[0]=0;
	for(;x;x/=10)num[++num[0]]=x%10;
	for(int i=1;i<num[0];i++)
		for(int j=1;j<=9;j++)
			ans+=f[i][j];
	num[num[0]+1]=-1;
	for(int i=num[0];i>=1;i--)
	{
		for(int j=0;j<num[i];j++)
			if(abs(j-num[i+1])>=2)
				ans+=f[i][j];
		if(abs(num[i]-num[i+1])<2)
			break;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&A,&B);
	pRe();
	printf("%d",calc(B+1)-calc(A));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

