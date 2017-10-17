#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int Kase,n,cost[200050],value[200050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int sum,H,T;
	bool flag;
	scanf("%d",&Kase);
	for(int cAse=1;cAse<=Kase;cAse++)
	{
		printf("Case %d: ",cAse);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&value[i]);
			value[i+n]=value[i];
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cost[i]);
			cost[i+n]=cost[i];
		}
		H=T=1;
		flag=false;
		while(T<=n)
		{
			sum=0;
			H=T;
			while(H-T<n&&sum+value[H]-cost[H]>=0&&H<=(n<<1))
			{
				sum+=(value[H]-cost[H]);
				H++;
			}
			if(H>=T+n)
			{
				flag=true;
				printf("Possible from station %d\n",T);
				break;
			}
			else
				T=H+1;
		}
		if(!flag)
			printf("Not possible\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

