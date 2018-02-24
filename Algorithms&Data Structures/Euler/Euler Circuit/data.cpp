#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
int road[100050][2];
void make_euler_circuit(int &n,int &m)
{
	bool dot[n+1];
	int a,b;
	memset(dot,false,sizeof(dot));
	for(int i=1;i<=m;i++)
	{
		a=rand()%n+1;
		b=rand()%n+1;
		road[i][0]=a;
		road[i][1]=b;
		dot[a]^=true;
		dot[b]^=true;
	}
	for(int i=1,t=0;i<=n;i++)
	{
		if(!dot[i])continue;
		road[t&1?m:++m][t&1]=i;
		t++;
		dot[i]=false;
	}
	return;
}
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int n,m;
	n=rand()%10+1,m=rand()%10+1;
//	n=10;m=10;
	make_euler_circuit(n,m);
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",road[i][0],road[i][1]);
	fclose(stdout);
	return 0;
}

