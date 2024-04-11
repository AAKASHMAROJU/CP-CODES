// Link: https://codeforces.com/contest/474/problem/B

#include<bits/stdc++.h>
using namespace std;
 
int getLabel(int warm_no, vector<int>& searchSpace, int n){
    int low=0;
 
    int ans=-1;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(warm_no<=searchSpace[mid]){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    
}
 
 
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int m;
    cin>>m;
    vector<int> q(m);
    for(int i=0;i<m;i++) cin>>q[i];
    vector<int> searchSpace(v.begin(), v.end());
    for(int i=1;i<n;i++){
        searchSpace[i]+=searchSpace[i-1];
    }    
    for(int i=0;i<m;i++){
        cout<<getLabel(q[i], searchSpace, n)+1<<endl;
    }
    
    return 0;
}