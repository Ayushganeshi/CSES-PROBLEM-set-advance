#include <bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	
	while(t--)
	{
	    int an1s=1;
	    int count=1;
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]==s[ i+1])
	        {
	            count++;
	        }
	        else
	        {
	            count=1;
	        }
	        ans=max(count,ans);
	    }
	    cout<<ans<<endl;
	}

}


