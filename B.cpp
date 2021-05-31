#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	string s;
	ifstream fin("input.txt");
	fin >> s;
	
	string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	short int* ids = (short int*)malloc(s.size()*sizeof(short int));

	for (int i=0; i<s.size(); i++)
	{
		ids[i] = alp.find(s[i]);
		cout << ids[i] << " ";
	}
	cout << "\n\n";
	
	int maxletterid=25, maxposlAll=0;
	
	for (int lid=0; lid<s.size(); lid++)
	{
		bool isposl=false;
		int posl=0, maxposl=-1;
		
		for (int i=0; i<s.size(); i++)
		{
			if (ids[i]==lid)
			{
				isposl = true;
				posl++;
			}
			else if (isposl==true)
			{
				if (posl>maxposl) maxposl=posl;
				posl=0;
				isposl=false;
			}
		}
		if (isposl==true && posl>maxposl && ids[s.size()-1]==lid) maxposl=posl+1;
		
		if (maxposl>maxposlAll)
		{
			maxposlAll = maxposl;
			maxletterid = lid;
		}
		else if (maxposl==maxposlAll && lid<maxletterid)
			maxletterid=lid;
			
		cout << s[lid] << " " << maxposl << " " << maxletterid << " " << maxposlAll << "\n";
		
	}
	if (maxletterid==25)
		cout << "0";
	else if (maxletterid==0)
		cout << alp[maxletterid] << " 0";
	else
		cout << alp[maxletterid] << " " << maxletterid+1;
	
	return 0;
}
