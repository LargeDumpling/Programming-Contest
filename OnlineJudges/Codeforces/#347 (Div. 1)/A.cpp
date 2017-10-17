/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-04-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x,cnt,l,r,an,bn,ann,bnn,xx;
bool mark[105];
int num[105];
int main()
{
	char tex[5];
	bool poss=true;
	an=bn=n=0;
	scanf("%s",tex);
	mark[n++]=true;
	while(true)
	{
		scanf("%s",tex);
		if(tex[0]=='+'||tex[0]=='-')
		{
			mark[n++]=(tex[0]=='+');
			if(mark[n-1]) an++;
			else bn++;
			scanf("%s",tex);
		}
		else if(tex[0]=='=')
		{
			scanf("%d",&x);
			break;
		}
	}
	l=max(bn+x,an);
	r=min((bn+1)*x,an*x);
	if(r<l) poss=false;
	else xx=l;
	ann=xx;//需要减下去的
	bnn=xx-x;//需要加的
	cnt=0;
	if(poss) for(int i=0;i<n;i++)
	{
		if(mark[i])
		{
			num[i]=ann/an;
			ann-=num[i];
			an--;
		}
		else
		{
			num[i]=bnn/bn;
			bnn-=num[i];
			bn--;
		}
	}
	if(poss)
	{
		puts("Possible");
		printf("%d",num[0]);
		for(int i=1;i<n;i++)
		{
			if(mark[i]) printf(" + %d",num[i]);
			else printf(" - %d",num[i]);
		}
		printf(" = %d",x);
	}
	else puts("Impossible");
	return 0;
}

