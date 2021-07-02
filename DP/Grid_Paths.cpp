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

void solve(){
    int n;cin>>n;
    vector<string>s(n);
    f(i,0,n)cin>>s[i];

    if(s[0][0] == '*' || s[n-1][n-1] == '*'){
        cout<<0<<endl;return ;
    }
    int dp[n+1][n+1];
    dp[0][0] = 1;
    f(i,1,n){
        if(s[i][0] == '.')dp[i][0] = dp[i-1][0];
        else dp[i][0] = 0;
    }
    f(j,1,n){
        if(s[0][j] == '.')dp[0][j] = dp[0][j-1];
        else dp[0][j] = 0;
    }

    f(i,1,n){
        f(j,1,n){
            dp[i][j] = 0;
            if(s[i][j] == '.')dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
            else dp[i][j] = 0;
            // cout<<dp[i][j]<< " ";
        }
        // cout<<endl;
    }
    cout<<dp[n-1][n-1]<<endl;
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