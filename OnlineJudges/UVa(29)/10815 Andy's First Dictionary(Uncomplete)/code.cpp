#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	string tex,in;
	set<string>s;
	while(cin>>in)
	{
		for(int i=0;i<in.length();i++)
			if('a'<=in[i]&&in[i]<='z');
			else if('A'<=in[i]&&in[i]<='Z')
				in[i]=in[i]-'A'+'a';
			else
				in[i]=' ';
		stringstream In(in);
		while(In>>tex)
			s.insert(tex);
	}
	for(set<string>::iterator it= s.begin();it!=s.end();it++)
		cout<<*it<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

