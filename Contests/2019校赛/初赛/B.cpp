/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-03-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXM=1000050;
int pri[MAXM],S[MAXM],n,m;
bool exist[MAXM];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	exist[1]=false;
	pri[0]=0;
	S[0]=S[1]=0;
	for(int i=2;i<MAXM;i++)
	{
		S[i]=S[i-1]+(int)exist[i];
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&(long long)i*pri[j]<MAXM;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]==0) break;
		}
	}
	return;
}
long long calcPP()
{ //p,p,n
	long long sum=0;
	for(int i=1;i<=pri[0]&&pri[i]<=m;i++)
	{
		if(n<pri[i])
		{
			sum+=(S[min(n+pri[i]-1,m)]-S[pri[i]-n]);
			if(pri[i]-n<pri[i]) sum++;
		}
		else if(pri[i]<n)
		{
			sum+=(S[min(n+pri[i]-1,m)]-S[n-pri[i]]);
			if(n-pri[i]<pri[i]) sum++;
		}
	}
	if(exist[n])
	{
		sum++;
		sum+=S[min(n*2-1,m)];
	}
	sum>>=1;
	return sum;
}
long long calcPN()
{
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		if(exist[i]) continue;
		if(n<i) sum+=(S[min(n+i-1,m)]-S[i-n]);
		else if(i<n) sum+=(S[min(n+i-1,m)]-S[n-i]);
	}
	return sum;
}
int main()
{
	pre_calc();
	scanf("%d%d",&n,&m);
	if(exist[n]) printf("%lld",calcPN()+calcPP());
	else printf("%lld",calcPP());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

