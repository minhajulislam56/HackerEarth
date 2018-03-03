#include<bits/stdc++.h>
using namespace std;
int arr[100007];
int tree[300007];
void segment(int node, int b, int e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    segment(left,b,mid);
    segment(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return INT_MAX;
    if(b>=i && e<=j)
        return tree[node];
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    return min(query(left,b,mid,i,j),query(right,mid+1,e,i,j));
}
void update(int node,int b, int e, int i, int num)
{
    if(i>e || i<b)
        return;
    if(b==e && b==i){
        tree[node]=num;
        //cout<<node<<" Node"<<endl;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(left,b,mid,i,num);
    update(right,mid+1,e,i,num);
    tree[node]=min(tree[left],tree[right]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    segment(1,1,n);
    for(int i=0;i<q;i++){
        char ch;
        int l,r;
        cin>>ch>>l>>r;
        if(ch=='q'){
            cout<<query(1,1,n,l,r)<<endl;
        }
        else{
            update(1,1,n,l,r);
        }
    }

    return 0;
}

