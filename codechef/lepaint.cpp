#include<cstdio>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n, k, c;
        scanf("%d %d %d", &n, &c, &k);
        double dp[k+1][n+1][c];
        for(int i=0; i<=k; i++)
            for(int j=1; j<=n; j++)
                for(int k=0; k<c; k++)
                    dp[i][j][k]=0.0;
        for(int i=1; i<=n; i++)
            dp[0][i][1]=1.0;
        for(int iter=1; iter<=k; iter++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            for(int i=1; i<l; i++)
                for(int color=0; color<c; color++)
                    dp[iter][i][color] += dp[iter-1][i][color];
            for(int i=r+1; i<=n; i++)
                for(int color=0; color<c; color++)
                    dp[iter][i][color] += dp[iter-1][i][color];
            for(int i=l; i<=r; i++)
            {   for(int color=0; color<c; color++)
                {   dp[iter][i][color] += dp[iter-1][i][color] * 0.5;
                    for(int lastColor=0; lastColor<c; lastColor++)
                        dp[iter][i][(color * lastColor) %c] += dp[iter-1][i][lastColor] / (2*c);
                }
            }
        }
        double ans=0.0;
        for(int i=1; i<=n; i++)
        {   for(int color=0; color<c; color++)
            {   ans+=dp[k][i][color]*color;
            }
        }
        printf("%.9lf\n",ans);
    }
    return 0;
}
