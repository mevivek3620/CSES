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

void dfs(vector<vector<int>>&adj,vector<bool>& vis,int i,vi& col,int c){
    vis[i] = true;

    if(col[i] != -1)return ;
    col[i] = c;

    for(auto x:adj[i]){
        if(!vis[x]){
            dfs(adj,vis,x,col,1 - c);
        }
    }
}

void solve(){
    int n,m;cin>>n>>m;
    vi col(n+1,-1);
    // f(i,1,n+1)col[i] = -1;
    vector<vector<int>>adj(n+1);
    vector<pii>a;

    f(i,0,m){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        a.pb({x,y});
    }
    vector<bool>vis(n+1,false);

    f(i,1,n+1){
        if(!vis[i]){
            dfs(adj,vis,i,col,1);
        }
    }
    int f = 0;
    f(i,0,m){
        // cout<<a[i].ff<<" "<<a[i].ss<<endl;
        // cout<<col[a[i].ff]<<" "<<col[a[i].ss]<<endl;
        if(col[a[i].ff] == col[a[i].ss]){
            f = 1;
            break;
        }
    }
    if(f == 1)cout<<"IMPOSSIBLE"<<endl;
    else{
        f(i,1,n+1){
            cout<<col[i]+1<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    int t = 1;
    // cin>>t;
    while(t--)solve();
    return 0;
}