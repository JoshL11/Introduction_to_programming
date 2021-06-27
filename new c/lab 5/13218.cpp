#include<iostream>
#include <set>
#define REP(i,j,k) for(int i=j;i<k;++i)
#define ll long long
#define P pair<ll,ll>
#define F first
#define S second
using namespace std;
ll n,q,t,ans[100005],a,b,c; 
int main(){
    cin>>n>>q;
    set<P> s;             				 //first: y, second: x
    REP(i,1,n+1) s.insert(P(0,i)); 
    while(q--){
        cin>>t>>a>>b;		
        if(t==1) s.erase(P(ans[a],a)), ans[a] += b, s.insert(P(ans[a],a)) ;
        else{
            cin>>c;
            auto p = s.lower_bound(P(b,a));
            if(p!=s.end() && (*p).F==b && (*p).S<=a+c) 
                ans[(*p).S] -= (*p).S-a;
                s.erase(p);
                s.insert(P(ans[(*p).S],(*p).S));
        }
    }
    REP(i,1,n+1){
        cout<<ans[i];
        if(i!=n) cout<<" ";
    }
    cout<<"\n";
}
































































