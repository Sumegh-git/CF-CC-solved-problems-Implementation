#include <bits/stdc++.h>
using namespace std;

long long int chk(int *x)
{
	long long int ret = 0;
	for(int i = 0;i<32;i++)
		ret += (1 << i)*(x[i]>0);
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int curr[32] = {0};
		int a[n];
		for(int i = 0;i<n;i++)
			scanf("%d",a+i);
		int end = 0;
		long long int ans = 0;
		for(int i = 0;i<n;i++)
		{
			while(chk(curr) < k && end < n)
			{
				for(int j = 0;j<32;j++)
					curr[j] += (a[end]&(1<<j));
				end++;
			}

			//cout << chk(curr) << " " << end << endl;
			if(chk(curr) >= k)
				ans += (n - end + 1);
			for(int j = 0;j<32;j++)
				curr[j] -= (a[i]&(1<<j));
		}

		printf("%lld\n",ans);
	}

	return 0;

}
