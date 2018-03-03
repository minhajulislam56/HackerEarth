#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        long long n;
        cin>>n;

        if(n==1){
            cout<<1<<endl;
        }
        else{
            cout<<(n*n)/2-1<<endl;
        }
    }


    return 0;
}
