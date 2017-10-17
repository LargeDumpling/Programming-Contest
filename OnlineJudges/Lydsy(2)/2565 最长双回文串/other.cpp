#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;

const int maxn=500010;
const int maxm=1010;
const int maxs=26;
const int INF=1<<29;
const int P=1000000007;
const double error=1e-9;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-'?-1:1),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

struct pam
{
	pam *fa,*next[maxs];int len,val;
}su[maxn],*headf,*heads,*last;

int n,pos,cnt,ans,l[maxn],r[maxn];char s[maxn];

void init()
{
	s[0]='~',pos=0;
	headf=&su[++cnt],last=heads=&su[++cnt];
	headf->fa=heads,heads->len=-1;
}

void add(int x)
{
	pam *per=last;
	for(pos++;s[pos-per->len-1]!=s[pos];per=per->fa);
	
	if(!per->next[x])
	{
		pam *now=&su[++cnt];
		last=per->next[x]=now,now->len=per->len+2;
		if(per==heads) now->fa=headf;
		else
		{
			for(per=per->fa;s[pos-per->len-1]!=s[pos];per=per->fa);
			now->fa=per->next[x];
		}
	}
	else last=per->next[x];
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	scanf("%s",s+1),n=strlen(s+1);
	
	init();
	for(int i=1;i<=n;i++) add(s[i]-'a'),l[i]=last->len;
	init();
	for(int i=1;i<=n/2;i++) swap(s[i],s[n-i+1]);
	for(int i=1;i<=n;i++) add(s[i]-'a'),r[n-i+1]=last->len;

	for(int i=1;i<n;i++) ans=max(ans,l[i]+r[i+1]);
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

