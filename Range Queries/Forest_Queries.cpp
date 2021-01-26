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
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define vii vector<pii>
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endc "\n"
using namespace std;

const int N = 8e5+3;

int main()
{
    int n,q;cin>>n>>q;
    // vector<vector<char> >grid(n+1,vector<char>(n+1));
    vector<vector<int> >dp(n+1,vector<int>(n+1,0));

    f(i,1,n+1){
        f(j,1,n+1)
        {
            char c;cin>>c;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])-dp[i-1][j-1];
            if(c == '*')dp[i][j]++;
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        // cout<<cnt[x2][y2]<<" "<<cnt[x1][y1]<<endl;
        cout<<dp[x2][y2]-(dp[x1-1][y2] + dp[x2][y1-1] -dp[x1-1][y1-1])<<endl;
    }
    return 0;
}