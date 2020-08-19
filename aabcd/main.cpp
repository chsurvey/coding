#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++)
    {
        int q,w;
        cin >> q >> w;
        a.push_back(make_pair(q,w));
    }
    sort(a.begin(),a.end());
    int dp[100]={0, };
    for(int i=0;i<100;i++)
        dp[i]=1;
    int q=0;
    for(int i=1;i<a.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i].second>a[j].second)
            {
                dp[i]=max(dp[i],dp[j]+1);
                printf("i=%d, dp=%d\n",a[i].second,dp[i]);
            }
        }
        q=max(q,dp[i]);
    }
    cout << a.size() - q <<"\n";
}
