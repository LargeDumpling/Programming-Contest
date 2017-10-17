#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define bEgin {
#define eNd }
using namespace std;
const int D=10000000;
char in[D],*I=in,out[D/10],*O=out;
int L[200050],R[200050],dist[200050],top,sz=0;
long long n,data[200050];
void read1n(long long &x)
bEgin
	for(x=0;*I<'0'||'9'<*I;I++);
	while('0'<=*I&&*I<='9')x=(x<<1)+(x<<3)+*(I++)-'0';
	return;
eNd
int s[100];
void write1n(long long x)
bEgin
	if(!x)*(O++)='0';
	for(s[0]=0;x;x/=10)s[++s[0]]=x%10;
	while(s[0])*(O++)=s[s[0]--]+'0';
	return;
eNd
void swap(int &A,int &B)
bEgin
	A^=B;
	B=A^B;
	A^=B;
eNd
int merge(int A,int B)
bEgin
	if(!A)
		return B;
	if(!B)
		return A;
	if(data[A]>data[B])
		swap(A,B);
	R[A]=merge(R[A],B);
	if(dist[L[A]]<dist[R[A]])
		swap(L[A],R[A]);
	dist[A]=R[A]?dist[R[A]]+1:0;
	return A;
eNd
int main()
bEgin
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	long long a,b,ans=0;
	while(true)
	bEgin
		read1n(n);
		if(!n)
			break;
		top=sz=0;
		L[0]=R[0]=0;
		for(int i=1;i<=n;i++)
		bEgin
			sz++;
			L[sz]=R[sz]=0;
			read1n(data[sz]);
			top=merge(top,sz);
		eNd
		ans=0;
		while(true)
		bEgin
			a=data[top];
			top=merge(L[top],R[top]);
			if(!top)
				break;
			b=data[top];
			top=merge(L[top],R[top]);
			a+=b;
			ans+=a;
			sz++;
			L[sz]=R[sz]=0;
			data[sz]=a;
			top=merge(top,sz);
		eNd
		write1n(ans);
		*(O++)='\n';
	eNd
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
eNd

