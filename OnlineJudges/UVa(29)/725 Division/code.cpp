#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=1000000;
char in[D],*I=in;
int n;
int read1n()
{
	int x=0;
	while(*I<'0'||'9'<*I)I++;
	while('0'<=*I&&*I<='9')x=(x<<1)+(x<<3)+*(I++)-'0';
	return x;
}
bool check(int x)
{
	if(x*n>=100000)return false;
	int ha=0,b=x*n,hb=0;
	for(int i=1;i<=5;i++,x/=10)
	{
		if(ha&(1<<(x%10)))
			return false;
		ha|=(1<<(x%10));
	}
	for(int i=1;i<=5;i++,b/=10)
	{
		if(ha&(1<<(b%10))||hb&(1<<(b%10)))
			return false;
		hb|=(1<<(b%10));
	}
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int cAse=0;
	bool flag=false;
	while(true)
	{
		n=read1n();
		if(!n)
			break;
		if(cAse++)
			printf("\n");
		flag=false;
		for(int i=1000;i<=99999;i++)
			if(check(i))
			{
				printf("%05d / %05d = %d\n",i*n,i,n);
				flag=true;
			}
		if(!flag)
			printf("There are no solutions for %d.\n",n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

