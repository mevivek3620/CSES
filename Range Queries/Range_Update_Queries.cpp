#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii pair< int,int >
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define vii vector<pii>
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endc "\n"
using namespace std;

const int N = 8e5+3;
ll RSQ[N];


void update(vl &a,int start,int end,int tn,int idx,ll val)
{
    if(start == end)
    {
        RSQ[tn] = val;
        a[start] = val;
        return ;
    }
    int mid = (start+end)/2;
    if(idx>mid)update(a,mid+1,end,2*tn+1,idx,val);
    else update(a,start,mid,2*tn,idx,val);
    RSQ[tn] = RSQ[2*tn] + RSQ[2*tn+1];
}

ll query(vl &a,int start,int end,int tn,int l,int r)
{
    if(start>r || end<l )return 0;
    if(start>=l && end<=r)return RSQ[tn];

    int mid = start+(end-start)/2;
    ll ans1 = 0,ans2 = 0;
    ans1 = query(a,start,mid,2*tn,l,r);
    ans2 = query(a,mid+1,end,2*tn+1,l,r);
    return ans1 + ans2;
}

int main()
{
    int n,q;cin>>n>>q;
    vl a(n+1),X(n+2,0);
    f(i,1,n+1){
        cin>>a[i];
    }
    
    while(q--)
    {
        int t;cin>>t;
        if(t == 1){
            ll l,r,val;cin>>l>>r>>val;
            ll temp1 = query(X,1,n,1,l,l);
            ll temp2 = query(X,1,n,1,r+1,r+1);
            update(X,1,n,1,l,temp1+val);
            if(r+1 <=n)update(X,1,n,1,r+1,temp2-val);
        }
        else{
            int k;cin>>k;
            cout<<a[k]+query(X,1,n,1,1,k)<<endl;
        }
    }
    return 0;
}