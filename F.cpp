#include <iostream>
#include <cmath>

using namespace std;

int len(int n)
{
	int l=0;
	while (n!=0)
	{
		n/=10;
		l++;
	}
	return l;
}

int main()
{
	int a, b;
	cin >> a >> b;
	
	int max=a, cnt=0;
	
	for (int i=a; i<=b; i++)
		if (i<-9 || i>9)
		{
			int v1 = i/pow(10, len(i)-2);
			int v2 = i%100;
			if (v1-v2!=0 && i%(v1-v2)==0)
			{
				cnt++;
				if (i>max) max = i;
			}
		}
	
	if (cnt==0) max=0;
	cout << cnt << " " << max;
	
	return 0;
}
