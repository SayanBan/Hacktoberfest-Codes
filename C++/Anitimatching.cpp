#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int nax=1e4+5;
vector<vector<int>> v(nax);
bool is3=false;
int vis[nax]={0};
int p[nax]={0};
stack<int> st;
void dfs(int ci){
    vis[ci]=1;
    st.push(ci);
    for(auto x : v[ci]){
        if(x==p[ci]) continue;
        if(vis[x]==0){
            p[x]=ci;
            dfs(x);
        }
        else{
            if(st.size() >=3){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                if(st.top()==x) is3=true;
                st.push(b);
                st.push(a);
            }
        }
    }
    st.pop();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        int deg[n]={0};
        int m1=0;
        for(int i=0;i<m;i++){
            int a,b; cin>>a>>b; a--; b--;
            v[a].push_back(b); deg[a]++; 
            v[b].push_back(a); deg[b]++;
            m1=max(m1,max(deg[a],deg[b]));
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
            dfs(i);
        }
        cout<<max(m1,(is3 ? 3 : 0))<<"\n";
        for(int i=0;i<n;i++){
            vis[i]=0;
            v[i].clear();
        }
        is3=false;
    }
 }
