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
ll tree[N];

void buildtree(vl &a,int start,int end,int tn)
{
    if(start == end)
    {
        tree[tn] = a[start];
        return ;
    }
    int mid = start + (end -start)/2;
    buildtree(a,start,mid,2*tn);
    buildtree(a,mid+1,end,2*tn+1);
    tree[tn] = tree[2*tn]+tree[2*tn+1];
}

void update(vl &a,int start,int end,int tn,int idx,int val)
{
    if(start == end){
        tree[tn] = val;
        a[start] = val;
        return ;
    }
    int mid = start + (end - start)/2;
    if(idx>mid)update(a,mid+1,end,2*tn+1,idx,val);
    else update(a,start,mid,2*tn,idx,val);
    tree[tn] = tree[2*tn]+tree[2*tn+1];
}

long long query(vl &a,int start,int end,int tn,int l,int r)
{
    // cout<<"start :"<<start<<" "<<end<<endl;
    if(start>r || end<l)return 0;
    if(start>=l && end<=r)return tree[tn];
    int mid = start +(end -start)/2;
    ll ans1 = 0,ans2 = 0;
    ans1 = query(a,start,mid,2*tn,l,r);
    ans2 = query(a,mid+1,end,2*tn+1,l,r);
    return ans1+ans2;
}

int main()
{
    int n,q;cin>>n>>q;
    vl a(n+1);
    f(i,1,n+1){
        cin>>a[i];
    }
    buildtree(a,1,n,1);
    while(q--)
    {
        int t;cin>>t;
        if(t == 1){
            int idx,val;cin>>idx>>val;
            update(a,1,n,1,idx,val);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<query(a,1,n,1,l,r)<<endl;
        }
    }
    return 0;
}