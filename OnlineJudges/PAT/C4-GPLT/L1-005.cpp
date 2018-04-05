#include<cstdio>
#include<algorithm>
struct jz
{
	char name[20];
	int a,b;
	bool operator<(const jz &X)const { return a<X.a; }
}stu[1050];
int n,q;
int main()
{
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s%d%d",stu[i].name,&stu[i].a,&stu[i].b);
	std::sort(stu+1,stu+n+1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		printf("%s %d\n",stu[x].name,stu[x].b);
	}
}

