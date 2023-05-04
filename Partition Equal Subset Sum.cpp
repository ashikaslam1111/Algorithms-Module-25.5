#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int>nums)
    {
        int n =nums.size();
        int num[105];
        int dp[205][20005];
        for(int i=1; i<=n; i++)num[i]=nums[i-1];
        int  sum =0;
        for(int i=1; i<=n; i++)
        {
            sum=sum+num[i];
        }
        if(sum%2!=0)
            return false;
        sum=sum/2;
        for(int i=1; i<=n; i++)dp[0][i]=0;
        for(int i=0; i<=n; i++)dp[i][0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                int ans1 = dp[i-1][j];
                if(j<num[i])
                {
                    dp[i][j]=ans1;
                }
                else
                {
                    int ans2 = dp[i-1][j-num[i]];
                    dp[i][j] = ans1|| ans2;
                }
            }
        }
        if(dp[n][sum]==1)return true;
        return false;
    }
};
int main()
{
    Solution a;
    vector<int>a1 = {1,5,11,5};
    cout<<a.canPartition(a1);
    return 0;
}
