#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>s1;
map<string,int>s2;
set<string>ans;
string ins(string s)
{
	string temp=s;
	for(int i=0;i<temp.size();i++)
		temp[i]=tolower(temp[i]);
	sort(temp.begin(),temp.end());
	return temp;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	string temp,t2;
	while(true)
	{
		cin>>temp;
		s1.push_back(temp);
		if(temp[0]=='#')
			break;
		t2=ins(temp);
		if(!s2.count(t2))
			s2[t2]=0;
		s2[t2]++;
	}
	for(int i=0;i<s1.size();i++)
		if(s2[ins(s1[i])]==1)
			ans.insert(s1[i]);
	for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
		cout<<*it<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

