#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
#define PMX 1000000
int dp[MAX];

int marked[PMX/64 + 2];
vector<int> primes;
#define mark(x) marked[x >> 6] |= (1 << ((x & 63) >> 1))
#define check(x) (marked[x >> 6] & (1 << ((x & 63) >> 1)))

bool isPrime(int x)
{
	return (x > 1) && ((x == 2) || ((x & 1) && (!(check(x)))));
}

void seive(int n)
{
	int i, j;
	for(i = 3; i * i <= n; i += 2) if(!check(i)) for(j = i * i; j <= n; j += i << 1) mark(j);
	primes.push_back(2);
	for(i = 3; i <= n; i += 2) if(isPrime(i)) primes.push_back(i);
}
int main()
{
    seive(1000007);
    for(int i=1;i<1000002;i++){
        if(isPrime(i))
            dp[i]=dp[i-1]+1;
        else
            dp[i]=dp[i-1];
    }

    int tc;
    scanf("%d",&tc);
    while(tc--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        printf("%d\n",dp[r]-dp[l-1]);
    }

    return 0;
}
