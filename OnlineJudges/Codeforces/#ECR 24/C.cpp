/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-06-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int M=1<<17;
struct jp
{
	int x1,y1,x2,y2;
	int cnt1,cnt2,cnt3,cnt4;
	jp() { cnt1=cnt2=cnt3=cnt4=0; }
}sofa[MAXN];
int d,n,m,cntl,cntr,cntt,cntb;
int data[M<<1];
void add(int P)
{
	for(P=P+M;P;P>>=1)
		data[P]++;
	return;
}
int query(int L,int R)
{
	int cnt=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) cnt+=data[L^1];
		if(R&1) cnt+=data[R^1];
	}
	return cnt;
}
int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1;i<=d;i++)
		scanf("%d%d%d%d",&sofa[i].x1,&sofa[i].y1,&sofa[i].x2,&sofa[i].y2);
	scanf("%d%d%d%d",&cntl,&cntr,&cntt,&cntb);

	memset(data,0,sizeof(data));
	for(int i=1;i<=d;i++) add(sofa[i].x1<sofa[i].x2?sofa[i].x1:sofa[i].x2);
	for(int i=1;i<=d;i++)
		sofa[i].cnt1=query(1,(sofa[i].x1<sofa[i].x2?sofa[i].x2:sofa[i].x1)-1)-(int)(sofa[i].x1!=sofa[i].x2);

	memset(data,0,sizeof(data));
	for(int i=1;i<=d;i++) add(sofa[i].x1<sofa[i].x2?sofa[i].x2:sofa[i].x1);
	for(int i=1;i<=d;i++)
		sofa[i].cnt2=query((sofa[i].x1<sofa[i].x2?sofa[i].x1:sofa[i].x2)+1,100000)-(int)(sofa[i].x1!=sofa[i].x2);

	memset(data,0,sizeof(data));
	for(int i=1;i<=d;i++) add(sofa[i].y1<sofa[i].y2?sofa[i].y1:sofa[i].y2);
	for(int i=1;i<=d;i++)
		sofa[i].cnt3=query(1,(sofa[i].y1<sofa[i].y2?sofa[i].y2:sofa[i].y1)-1)-(int)(sofa[i].y1!=sofa[i].y2);

	memset(data,0,sizeof(data));
	for(int i=1;i<=d;i++) add(sofa[i].y1<sofa[i].y2?sofa[i].y2:sofa[i].y1);
	for(int i=1;i<=d;i++)
		sofa[i].cnt4=query((sofa[i].y1<sofa[i].y2?sofa[i].y1:sofa[i].y2)+1,100000)-(int)(sofa[i].y1!=sofa[i].y2);

	int ans=-1;
	for(int i=1;i<=d;i++)
		if(sofa[i].cnt1==cntl&&sofa[i].cnt2==cntr&&sofa[i].cnt3==cntt&&sofa[i].cnt4==cntb)
			ans=i;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

