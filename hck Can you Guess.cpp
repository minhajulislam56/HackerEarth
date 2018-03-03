#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;

        int sum=0;
        for(int i=1;i<(int)sqrt(n)+1;i++){
            if(n%i==0 && i*i!=n)
                sum+=i+(n/i);
            if(n%i==0 && i*i==n)
                sum+=i;
        }
        cout<<sum-n<<endl;
    }

    return 0;
}
