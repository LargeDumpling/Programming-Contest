/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	freopen("BST.in","r",stdin);
	freopen("Set.out","w",stdout);
	int n,m,op,x;
	set<int> s;
	//scanf("%d%d",&n,&m);
	read1n(n);
	read1n(m);
	for(int i=1;i<=n;i++)
	{
		//scanf("%d",&x);
		read1n(x);
		s.insert(x);
	}
	for(int i=1;i<=m;i++)
	{
		//scanf("%d%d",&op,&x);
		read1n(op);
		read1n(x);
		switch(op)
		{
			case 1:
				puts(s.insert(x).second?"Yes":"No");
				break;
			case 2:
				puts(s.find(x)!=s.end()?"Yes":"No");
				s.erase(x);
				break;
			case 3:
				puts(s.find(x)!=s.end()?"Yes":"No");
				break;
			default:
				break;
		}
	}
	fprintf(stderr,"Set %lf\n",(double)clock()/CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

