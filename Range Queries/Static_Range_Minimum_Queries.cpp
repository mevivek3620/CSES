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
int tree[N];

void buildtree(vi &a,int start,int end,int tn)
{
    if(start == end)
    {
        tree[tn] = a[start];
        return ;
    }
    int mid = start + (end -start)/2;
    buildtree(a,start,mid,2*tn);
    buildtree(a,mid+1,end,2*tn+1);
    tree[tn] = min(tree[2*tn],tree[2*tn+1]);
}

int query(vi &a,int start,int end,int tn,int l,int r)
{
    // cout<<"start :"<<start<<" "<<end<<endl;
    if(start>r || end<l)return INT_MAX;
    if(start>=l && end<=r)return tree[tn];
    int mid = start +(end -start)/2,ans1=INT_MAX,ans2 = INT_MAX;
    ans1 = query(a,start,mid,2*tn,l,r);
    ans2 = query(a,mid+1,end,2*tn+1,l,r);
    return min(ans1,ans2);
}

int main()
{
    int n,q;cin>>n>>q;
    vi a(n+1);
    f(i,1,n+1){
        cin>>a[i];
    }
    buildtree(a,1,n,1);
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<query(a,1,n,1,l,r)<<endl;
    }
    return 0;
}