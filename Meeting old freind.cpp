#include<bits/stdc++.h>
using namespace std;
unsigned long long l1,r1,l2,r2,k;
int main()
{
	cin>>l1>>r1>>l2>>r2>>k;
	if(r1<l2||l1>r2)
	{
		cout<<0;
		return 0;
	}
	unsigned long long l3=max(l1,l2),r3=min(r1,r2),ans=r3-l3+1;
	if(l3<=k&&k<=r3) ans--;
	cout<<ans;
	return 0;
}
