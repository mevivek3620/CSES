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

bool isValid(int i,int j,int n,int m){
    if(i < 0 || j < 0 || i >=n ||j >= m)return false;
    return true;
}

void bfs(vector<string>& s,int n,int m,int sx,int sy,int ex,int ey){
    int x[4] = {1,0,0,-1};
    int y[4] = {0,1,-1,0};
    int f = 0;
    vector<vector<char>>ans(n,vector<char>(m,'*'));
    vector<vector<bool>>vis(n,vector<bool>(m,false));

    queue<pii>q;
    q.push({sx,sy});
    vis[sx][sy] = true;
    while(!q.empty()){
        int i = q.front().ff;
        int j = q.front().ss;
        // cout<<i<<" "<<j<<endl;
        q.pop();

        if(i == ex && j == ey){
            f = 1;
            break;
        }

        for(int k = 0;k < 4;k++){
            int x1 = i + x[k],y1 = j + y[k];
            if(isValid(x1,y1,n,m) && !vis[x1][y1] && s[x1][y1] != '#'){
                q.push({x1,y1});
                vis[x1][y1] = true;
                if(k == 0)ans[x1][y1] = 'D';
                else if(k == 1)ans[x1][y1] = 'R';
                else if(k == 2)ans[x1][y1] = 'L';
                else ans[x1][y1] = 'U';
            }
        }
    }
    if(f == 0)cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        string res;
        // cout<<ans[ex][ey]<<endl;
        while(ex != sx || ey != sy){
            res += ans[ex][ey];
            char a = ans[ex][ey];
            if(a == 'L')ey++;
            else if(a == 'R')ey--;
            else if(a == 'U')ex++;
            else ex--;
        }
        reverse(all(res));
        cout<<res.size()<<endl;
        cout<<res<<endl;
        // f(i,0,n){
        //     f(j,0,m)cout<<ans[i][j]<<" ";
        //     cout<<endl;
        // }
    }
}

int get_root(int a,vi& par){
    if(a == par[a])return a;
    return par[a] = get_root(par[a],par);
}

void merge(int a,int b,vi& par){
    par[a] = b;
}

void solve(){
    int n,m;cin>>n>>m;
    vi par(n+1,-1);
    f(i,1,n+1)par[i] = i;

    f(i,0,m){
        int x,y;cin>>x>>y;
        int a = get_root(x,par);
        int b = get_root(y,par);
        if(a != b)merge(a,b,par);
    }

    set<int>s;
    f(i,1,n+1){
        s.insert(get_root(i,par));
    }
    int k = s.size() - 1;
    cout<<k<<endl;
    // for(auto x:s)cout<<x<<" ";
    f(i,0,k){
        cout<<*s.begin()<<" ";
        s.erase(s.begin());
        cout<<*s.begin()<<endl;
    }
}

int main(){
    
    int t = 1;
    // cin>>t;
    while(t--)solve();
    return 0;
}