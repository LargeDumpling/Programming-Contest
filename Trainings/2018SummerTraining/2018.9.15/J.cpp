/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pri[105];
bool vis[105];
char str[250];
void pre_calc()
{
	memset(vis,false,sizeof(vis));
	pri[0]=0;
	for(int i=2;i<105;i++)
	{
		if(!vis[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<105;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)
				break;
		}
	}
	return;
}
inline int mul_mod(int a,int b,int c)
{
	int ret;
	__asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(c));
	return ret;
}
int pow(int x,int n,int mod)
{
	int ans;
	for(ans=1;n;n>>=1,x=mul_mod(x,x,mod))
		if(n&1)
			ans=mul_mod(ans,x,mod);
	return ans;
}
bool check(int x,int p)
{
	if(!x) return true;
	if(pow(x,(p-1)>>1,p)==1) return true;
	return false;
}
int calc()
{
	int len=strlen(str),rem[105],flag[2]={1,1};
	memset(rem,0,sizeof(rem));
	for(int i=0;i<len;i++)
	{
		for(int j=2;j<=pri[0];j++)
		{
			rem[j]=mul_mod(rem[j],10,pri[j])+str[i]-'0';
			while(pri[j]<=rem[j]) rem[j]-=pri[j];
		}
	}
	for(int i=2;i<=pri[0];i++)
	{
		if(!check(rem[i],pri[i])) flag[0]=0;
		if(!check(mul_mod(mul_mod(rem[i],rem[i]+pri[i]-1,pri[i]),pow(2,pri[i]-2,pri[i]),pri[i]),pri[i])) flag[1]=0;
	}
	return (flag[0]<<1)+flag[1];
}
int main()
{
	int T_T;
	char ans[4][20]={"League of Legends","Clash Royale","Hearth Stone","Arena of Valor"};
	pre_calc();
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str);
		puts(ans[calc()]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

