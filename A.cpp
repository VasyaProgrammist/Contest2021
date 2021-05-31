#include <iostream>
#include <cmath>

using namespace std;

char isOdd(int n)
{
	for (int u=2; u<=(int)sqrt(n); u++)
		if (n%u==0) return '0';
	return '1';
}

int main()
{
	int a, b;
	cin >> a >> b;
	
	int count=0, maxr=0, maxnum=0;
	for (int i=a; i<=b; i++)
	{
		int cnt=0, max=0, min=i, last=0;
		int I = i;
		//cout << "\n\n\n\ni = " << i << "\n";
		for (int k=2; k<=i; k++)
			if (I%k==0 && isOdd(k)=='1')
			{
				//cout << "K: " << k << ", ";
				if (cnt==0)
				{
					I = i/k;
					cnt++;
					last=k%10;
					if (k>max) max=k;
					if (k<min) min=k;
				}
				else
					if (k%10==last)
					{
						I = i/k;
						cnt++;
						if (k>max) max=k;
						if (k<min) min=k;
					}
			}
			
		//cout << "\n\nmin=" << min << " max=" << max << " last=" << last << " cnt=" << cnt << "\n";
		
		if (cnt==3)
		{
			count++;
			if (max-min>maxr)
			{
				maxr=max-min;
				maxnum = i;
				//cout << "\nr=" << max-min << " maxr=" << max-min << " maxnum=" << maxnum << "\n";
			}
		}
			
	}
	cout << count << " " << maxnum;
	
	//cout << isOdd(3);
	
	return 0;
}
