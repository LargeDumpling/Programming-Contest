#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[100050],nu=0;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b,*p;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==1)
		{
			num[++nu]=b;
			sort(num+1,num+nu+1);
		}
		else if(a==2)
		{
			if(*lower_bound(num+1,num+nu+1,b)==b)
				swap(*lower_bound(num+1,num+nu+1,b),num[nu]);
			num[nu--]=0;
			sort(num+1,num+nu+1);
		}
		else if(a==3)
			printf("%d\n",lower_bound(num+1,num+nu+1,b)-num);
		else if(a==4)
			printf("%d\n",num[b]);
		else if(a==5)
		{
			p=lower_bound(num,num+nu+1,b);
			if(*p==b)
				printf("%d\n",*lower_bound(num,num+nu+1,b-1));
			else if(p==num+nu+1)
				printf("%d\n",num[nu]);
			else
				printf("%d\n",(*p)>b?*(p-1):*p);
		}
		else if(a==6)
			printf("%d\n",*upper_bound(num+1,num+nu+1,b));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

