#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int n;
	scanf("%d",&n);
	int numb[n],num=0,order,pos=0,x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&order);
		if(order==0)
		{
			scanf("%d",&numb[++num]);
			if(num)
				sort(numb+1,numb+num+1);
		}
		else if(order==1)
		{
			scanf("%d",&x);
			for(pos=1;pos<=num&&numb[pos]!=x;pos++);
			swap(numb[pos],numb[num--]);
			if(num)
				sort(numb+1,numb+num+1);
		}
		else if(order==2)
		{
			for(int j=1;j<=num;j++)
				printf("%d ",numb[j]);
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

