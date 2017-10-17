#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
deque< pair<unsigned long  long,unsigned long long> >ans; 
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    int t;   cin>>t;
    while(t--)
    {
        ans.clear();
        unsigned long long m,now=1,c=1;
        cin>>m;
        while(1)
        {
            c*=now; 
            unsigned long long w=pow(m,1.0/now)*pow(c,1.0/now)+1; 
            while(w--)
            {
                long double acu=1;
                for(unsigned long long i=1;i<=now;i++) 
                {acu=(long double)acu/i;  acu=(long double)acu*(w+i); }
                unsigned long long hi=(unsigned long long )floor(acu+1e-8);
                if(hi==m) 
                {   
                    if(!((w+now)%2==0 && now==(w+now)/2)) ans.push_front(pair<unsigned long  long,unsigned long long>(w+now,w+now-now));
                    ans.push_front(pair<unsigned long  long,unsigned long long>(w+now,now));
                }   
                if(acu<m) break;
            }
            if(w<=now++) break;
        }
        cout<<ans.size()<<endl;
        for(size_t i=0;i<ans.size();i++) cout<<"("<<ans[i].first<<","<<ans[i].second<<")"<<((i==ans.size()-1)?"":" ") ;
        cout<<endl; 
    }

    return 0;
}
