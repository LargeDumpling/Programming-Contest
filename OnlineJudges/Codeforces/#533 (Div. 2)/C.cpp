/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
int n;
long long num[3],f[2][3];
int main()
{
	int l,r,now;
	scanf("%d%d%d",&n,&l,&r);
	for(int i=0;i<3;i++)
		num[i]=((r+3-i)/3)-((l+2-i)/3);
#define pre (now^1)
	now=0;
	f[now][0]=1;
	f[now][1]=f[now][2]=0;
	for(int i=1;i<=n;i++)
	{
		now^=1;
		f[now][0]=f[now][1]=f[now][2]=0;
		f[now][0]=(f[pre][0]*num[0]%mod+f[pre][1]*num[2]%mod+f[pre][2]*num[1]%mod)%mod;
		f[now][1]=(f[pre][0]*num[1]%mod+f[pre][1]*num[0]%mod+f[pre][2]*num[2]%mod)%mod;
		f[now][2]=(f[pre][0]*num[2]%mod+f[pre][1]*num[1]%mod+f[pre][2]*num[0]%mod)%mod;
	}
#undef pre
	cout<<f[now][0];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

