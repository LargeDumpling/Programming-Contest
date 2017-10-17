#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 100010
char s[M],rs[M];
int f[M],n;
void getfail()
{
    f[0]=f[1]=0;
    for(int i=1;i<n;i++)
    {
        int j=f[i];
        while(j&&rs[i]!=rs[j]) j=f[j];
        f[i+1]=rs[i]==rs[j]?j+1:0;
    }
}
int find()
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j&&rs[j]!=s[i]) j=f[j];
        if(rs[j]==s[i]) j++;
    }
    return j;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	int cAse=0;
    while(cin>>s)
    {
		//printf("%d",cAse++);
        n=strlen(s);
        for(int i=0;i<n;i++) rs[i]=s[n-i-1];
        rs[n]='\0';
        getfail();
        int ans=find();
        cout<<s<<rs+ans<<endl;
    }
	fclose(stdin);
	fclose(stdout);
    return 0;
}

