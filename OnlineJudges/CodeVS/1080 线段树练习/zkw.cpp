#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define M 131072
using namespace std;
const int D=10000000;
char in[D],*I=in;
int data[M<<1],s[35],n,m;
void read1n(int &x)
{
	bool a=false;
	for(x=0;*I<'0'||'9'<*I;I++)if(*I=='-')a=true;
	for(;'0'<=*I&&*I<='9';I++)x=(x<<1)+(x<<3)+(*I)-'0';
	if(a)x=-x;
	return;
}
void change(int pos,int x)
{
	data[pos=pos+M]+=x;
	for(pos>>=1;pos;pos>>=1)data[pos]=data[pos<<1]+data[pos<<1|1];
	return;
}
int query(int L,int R)
{
	int sum=0;
	for(L=L+M-1,R=R+M+1;L^R^1;L>>=1,R>>=1)
	{
		if(!(L&1))sum+=data[L^1];
		if(R&1)sum+=data[R^1];
	}
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fread(in,1,D,stdin);
	int temp,a,b;
	read1n(n);
	for(int i=1;i<=n;i++)read1n(data[i+M]);
	for(int i=M-1;i;i--)data[i]=data[i<<1]+data[i<<1|1];
	read1n(m);
	for(int i=1;i<=m;i++)
	{
		read1n(temp),read1n(a),read1n(b);
		if(temp==1)
			change(a,b);
		else
			printf("%d\n",query(a,b));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

