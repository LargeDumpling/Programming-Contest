/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
struct jp
{
	int fir,sec;
	jp(const int &a=0,const int &b=0):fir(a),sec(b){}
	bool operator<(const jp &X)const { return fir==X.fir?sec<X.sec:fir<X.fir; }
};
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,n,a,b;
	jp T;
	multiset<jp>s;
	multiset<jp>::iterator it;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		if(cAse>1) putchar('\n');
		printf("Case #%d:\n",cAse);
		scanf("%d",&n);
		s.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			T=jp(a,b);
			it=s.lower_bound(T);
			if(it==s.begin()||(--it)->sec > b)
			{
				s.insert(T);
				it=s.upper_bound(T);
				while(it!=s.end()&&it->sec>=b) s.erase(it++);
			}
			printf("%d\n",(int)s.size());
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

