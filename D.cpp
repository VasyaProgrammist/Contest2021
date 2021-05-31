#include <iostream>
#include <cstdlib>

using namespace std;

void fill(char** m, int ny, int mx, int x, int y, char pc2)
{
	char pc = m[y][x];
	m[y][x] = pc2;
	if (y==0)
	{
		if (x==0)
		{
			if (m[y][x+1]==pc) fill(m, ny, mx, x+1, y, pc2);
			if (m[y+1][x]==pc) fill(m, ny, mx, x, y+1, pc2);
		}
		else if (x==mx)
		{
			if (m[y][x-1]==pc) fill(m, ny, mx, x-1, y, pc2);
			if (m[y+1][x]==pc) fill(m, ny, mx, x, y+1, pc2);
		}
		else
		{
			if (m[y][x-1]==pc) fill(m, ny, mx, x-1, y, pc2);
			if (m[y+1][x]==pc) fill(m, ny, mx, x, y+1, pc2);
			if (m[y][x+1]==pc) fill(m, ny, mx, x+1, y, pc2);
		}
	}
	else if (y==ny)
	{
		if (x==0)
		{
			if (m[y][x+1]==pc) fill(m, ny, mx, x+1, y, pc2);
			if (m[y-1][x]==pc) fill(m, ny, mx, x, y-1, pc2);
		}
		else if (x==mx)
		{
			if (m[y][x-1]==pc) fill(m, ny, mx, x-1, y, pc2);
			if (m[y-1][x]==pc) fill(m, ny, mx, x, y-1, pc2);
		}
		else
		{
			if (m[y][x-1]==pc) fill(m, ny, mx, x-1, y, pc2);
			if (m[y-1][x]==pc) fill(m, ny, mx, x, y-1, pc2);
			if (m[y][x+1]==pc) fill(m, ny, mx, x+1, y, pc2);
		}
	}
	else
	{
		if (x==0)
		{
			if (m[y][x+1]==pc) fill(m, ny, mx, x+1, y, pc2);
			if (m[y+1][x]==pc) fill(m, ny, mx, x, y+1, pc2);
			if (m[y][x-1]==pc) fill(m, ny, mx, x-1, y, pc2);
		}
		else if (x==mx)
		{
			if (m[y][x+1]==pc) fill(m, ny, mx, x+1, y, pc2);
			if (m[y-1][x]==pc) fill(m, ny, mx, x, y-1, pc2);
			if (m[y][x-1]==pc) fill(m, ny, mx, x-1, y, pc2);
		}
		else
		{
			if (m[y][x+1]==pc) fill(m, ny, mx, x+1, y, pc2);
			if (m[y-1][x]==pc) fill(m, ny, mx, x, y-1, pc2);
			if (m[y][x-1]==pc) fill(m, ny, mx, x-1, y, pc2);
			if (m[y+1][x]==pc) fill(m, ny, mx, x, y+1, pc2);
		}
	}
}

int main()
{
	int n, m, x, y, ac;
	cin >> n >> m >> x >> y >> ac;
	char a = (char)ac;
	char** b = (char**)malloc(n*sizeof(char));
	for (int i=0; i<n; i++)
		b[i] = (char*)malloc(m*sizeof(char));
	
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			int k;
			cin >> k;
			b[i][j] = (char)k;
		}
		
		
	fill(b, n, m, x, y, ac);
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			cout << (int)b[i][j] << " ";
		cout << "\n";
	}
			
	/*for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			cout << (char)b[i][j] << ", ";
		cout << "\n";
	}*/
	
	
	return 0;
}
