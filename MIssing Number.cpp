#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0);   cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++)
    {
        if(v[i+1]!=1+v[i])
        {
            
            cout<<i+1<<endl;
            break;
        }
    }
    
}

int32_t main() {
    fast_io();
    
    int t=1; 
      
    while (t--) {
        solve();
    }

    return 0;
}
