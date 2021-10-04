// https://www.hackerrank.com/challenges/merging-communities/problem
#include<bits/stdc++.h>
using namespace std;
// #define deb(x) cout<<#x<<" -> "<<x<<endl;
#define deb(x) cout<<#x<<" -> "<<x<<"\n";
class dsu
{
    vector<int> immediate_parent;
    vector<int> sz;
    int find_parent(int i)
    {
        if(i==immediate_parent[i]) return i;
        int super_parent=find_parent(immediate_parent[i]);
        immediate_parent[i]=super_parent;
        return super_parent;
    }
    public:
    dsu(int n)
    {
        immediate_parent=vector<int> (n+1); // 1 based indexing
        for(int i=0;i<=n;i++)
        {
            immediate_parent[i]=i;
        }
        sz=vector<int> (n+1,1); // intially everyone is of size 1
    }
    // yes
    // no
    void addEdge(int a,int b)
    {
        int par_a=find_parent(a);
        int par_b=find_parent(b);
        if(par_a!=par_b)
        {
            // immediate_parent[par_a]=par_b;
            // sz[par_b]+=sz[par_a];
            int sz_a=sz[par_a];
            int sz_b=sz[par_b];
            if(sz_a > sz_b)
            {
                swap(par_a,par_b);
            }
            sz[par_b]+=sz[par_a];
            immediate_parent[par_a]=par_b;

        }
    }
    int get_size(int i)
    {
        // int super_parent=immediate_par[i];// this is wrong
        int super_parent=find_parent(i);// this is correct

        return sz[super_parent];
    }
    // 23
    // 5->aagya
    // 0->samajh nahi aaya
};
int main()
{
    int n; cin>>n;
    dsu D(n);
    int q; cin>>q;
    for(int i=0;i<q;i++)
    {
        char c; cin>>c;
        if(c=='M')
        {
            int a,b; cin>>a>>b;
            D.addEdge(a,b);
        }
        else
        {
            
            int node; cin>>node;
            // cout<<node<<endl;
            // deb(node);
            cout<<D.get_size(node)<<endl;
        }
    }
    return 0;
}