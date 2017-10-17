#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//const int D=10000000;
//char in[D],*I=in;
int num[10000050],amax[4]={-2147483648,-2147483648,-2147483648,-2147483648},n;
void Q_sort()
{
	for(int i=2;i>=0&&amax[i]<amax[i+1];i--)
	{
		amax[i]^=amax[i+1];
		amax[i+1]=amax[i]^amax[i+1];
		amax[i]^=amax[i+1];
	}
	return;
}
int readln()
{
	int x=0;
	bool a=false;
//	for(;*I<'0'||'9'<*I;*(I++))if(*I=='-')a=true;
//	for(;'0'<=*I&&*I<='9';*(I++))x=(x<<1)+(x<<3)+*I-'0';
	char ch;
	for(ch=getchar();ch<'0'|'9'<ch;ch=getchar())if(ch=='-')a=true;
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	if(a)x=-x;
	return x;
}
int main()
{
	freopen("T1.in","r",stdin);
	freopen("T1.out","w",stdout);
//	fread(in,1,D,stdin);
//	scanf("%d",&n);
	n=readln();
	for(int i=1;i<=n;i++)
//		scanf("%d",&num[i]);
		num[i]=readln();
	num[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		num[i]-=num[i+1];
		amax[3]=num[i];
		Q_sort();
	}
	printf("%d %d %d",amax[0],amax[1],amax[2]);
	fclose(stdin);
	fclose(stdout);
    return 0;
}

