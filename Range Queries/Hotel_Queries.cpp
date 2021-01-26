#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define vi vector< int >
#define vl vector< ll >
// #define v2l vector<ll>
#define ss second
#define ff first
#define pii pair< int,int >
#define pll pair< ll,ll >
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define vii vector<pii>
#define vll vector<pll>
// #define pqueue priority_queue< ll >
#define pqueue priority_queue< pll >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endc "\n"
using namespace std;

const int N = 8e5+3;

bool cmp(pll &a,pll &b)
{
    return a.ss<b.ss;
}


bool cmp1(pll &a,pll &b)
{
    return a.ff>b.ff;
}

int main()
{
    int n,q;cin>>n>>q;
    pqueue pq;
    f(i,0,n){
        ll a;cin>>a;
        pq.push({a,i+1});
        cout<<pq.top().ss<<endl;
    }
    vll a(q);
    f(i,0,q){
        ll b;cin>>b;
        a.pb({i,b});
    }
    // sort(all(a),cmp);
    // f(i,0,q){
    //     int f = 0;
    //     while(!pq.empty()){
    //         if(pq.top().ss<a[i].ss)a[i].ss = 0;
    //         else{
    //             pii t = pq.top();
    //             pq.pop();
    //             if(t.ss-a[i].ss != 0)pq.push({t.ff,t.ss-a[i].ss});
    //             a[i].ss = t.ff;
    //         }
    //         f = 1;
    //     }
    //     if(!f)a[i].ss = 0;
    // }
    // sort(all(a),cmp1);
    // f(i,0,q)cout<<a[i].ff<<" ";
    return 0;
}