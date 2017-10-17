#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=10000050;
char in[D],*I=in,out[D/10],*O=out;
int num[10050],n,q,pos,temp;
void read1n(int &x)
{
	for(x=0;*I<'0'||'9'<*I;I++);
	for(;'0'<=*I&&*I<='9';I++)x=(x<<1)+(x<<3)+(*I)-'0';
	return;
}
void write1n(const int &x)
{
	static int s[11];
	s[0]=0;
	if(!x)
	{
		*(O++)=0;
		return;
	}
	for(int X=x;X;X/=10)s[++s[0]]=X%10;
	while(s[0])*(O++)=s[s[0]--]+'0';
	return;
}
void write1n(const char tex[])
{
	for(int i=0;tex[i]!='\0';i++)
		*(O++)=tex[i];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	for(int cAse=1;;cAse++)
	{
		read1n(n);
		read1n(q);
		if(!n&&!q)
			break;
		write1n("CASE# ");
		write1n(cAse);
		write1n(":\n");
		for(int i=1;i<=n;i++)
			read1n(num[i]);
		sort(num+1,num+n+1);
		for(int i=1;i<=q;i++)
		{
			read1n(temp);
			write1n(temp);
			pos=lower_bound(num+1,num+n+1,temp)-num;
			if(pos==n+1||num[pos]!=temp)
				write1n(" not found\n");
			else
			{
				write1n(" found at ");
				write1n(pos);
				*(O++)='\n';
			}
		}
	}
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

