#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
#define pll pair< ll,ll >
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define vii vector<pii>
#define vll vector<pll>
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endc "\n"
#define MAX 100003
#define N 10003

using namespace std;

vi prime;
// int ans[N];
// unordered_set<ll>ans;
// prime numbers till n
void prime_numbers(int n) 
{
    vector<bool>primes(n+1,true);
    f(i,2,n+1)
    {
        if(primes[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                primes[j] = false;
            }
        }
    }
    f(i,2,n+1){
        if(primes[i])prime.pb(i);
    }
}

//calculate smallest prime factor for every number
vi spf(MAX);
void find_spf()
{
    // make every number's spf equal to itself
    f(i,1,MAX)spf[i] = i;

    //make even number's spf to 2
    for(int i=2;i<=MAX;i+=2){
        spf[i] = 2;
    }

    for(int i=3;i<=MAX;i+=2)
    {
        //check if i is prime
        if(spf[i] == i)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
                if(spf[j] == j)spf[j] = i;
            }
        }
    }
    
}

// int dp[100005][1003];

// int helper(int p[],int pages[],int x,int n){
//     if(x == 0 )return 0;
//     if(n == 0)return 0;

//     if(dp[x][n] != -1)return dp[x][n];

//     if(p[n-1] <= x)return dp[x][n] = max(pages[n-1] + helper(p,pages,x - p[n-1],n-1), helper(p,pages,x,n-1));
//     return dp[x][n] = helper(p,pages,x,n-1);

// }


void solve(){
    int n,x;cin>>n>>x;
    int prices[n+1],pages[n+1];

    f(i,0,n)cin>>prices[i];
    f(i,0,n)cin>>pages[i];

    int dp[n+1][x+1];

    f(i,0,n+1)dp[i][0] = 0;
    f(j,0,x+1)dp[0][j] = 0;

    f(j,1,n+1){
        f(i,1,x+1){
            if(prices[j-1] <= i){
                dp[j][i] = max(pages[j-1] + dp[j-1][i-prices[j-1]],dp[j-1][i]);
            }
            else{
                dp[j][i] = dp[j-1][i];
            }
        }
    }

    cout<<dp[n][x]<<endl;
    return ;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--){
        solve();
    }
    
    return 0;
}