#include <iostream>

using namespace std;

string formatNOT(string S, int i) // форматирование строки вида "текст not(0) текст" в "текст 1 текст". i - айди символа 'n' в not.
{
	string work = S.substr(i, i+5);
	char A = work[4];
	
	if (A=='1') S = S.substr(0, i-1)+'0'+S.substr(i+6, S.size());
	else S = S = S.substr(0, i-1)+'1'+S.substr(i+6, S.size());

	return S;
}

char solve(string S)
{
	string m = "";
	for (int i=0; i<S.size(); i++)
	{
		if ((S[i]=='1' || S[i]=='0') && S[i+1]==' ')
			m+=S[i];
		else if (S[i]=='a' && S[i+1]=='n' && S[i+2] && 'd')
			m+='*';
		else if (S[i]=='o' && S[i+1]=='r')
			m+='+';
	}
	
	cout << "\n\n" << m << "\n\n";
	while (m.size()!=1)
	{
		for (int i=0; i<m.size(); i++)
			if (m[i]=='*')
			{
				if (m[i-1]=='1' && m[i+1]=='1') m = m.substr(0, i-2)+'1'+m.substr(i+2, m.size());
				else m = m.substr(0, i-2)+'0'+m.substr(i+2, m.size());
				continue;
			}
			
		for (int i=0; i<m.size(); i++)
			if (m[i]=='+')
			{
				if (m[i-1]=='0' && m[i+1]=='0') m = m.substr(0, i-2)+'0'+m.substr(i+2, m.size());
				else m = m.substr(0, i-2)+'1'+m.substr(i+2, m.size());
				continue;
			}
	}
	return m[0];
}

int main()
{
	string as, bs, cs;
	cin >> as >> bs >> cs;
	char a, b, c;
	
	if (as=="true") a='1';
	else a='0';
	if (bs=="true") b='1';
	else b='0';
	if (cs=="true") c='1';
	else c='0';
	
	string s;
	getline(cin, s);
	getline(cin, s);
	
	for (int i=0; i<s.size(); i++)
	{
		if (i!=s.size()-1)
			if (s[i]=='a' && s[i+1]!='n') s[i] = a;
		else
			if (s[i]=='a') s[i] = a;
		if (s[i]=='b') s[i] = b;
		if (s[i]=='c') s[i] = c;
	}
	
	while (s.size()!=1)
	{
		int start = 0, end=0;
		for (int i=0; i<s.size(); i++)
		{
			if (s[i]=='(') start = i;
			if (s[i]==')')
			{
				end = i;
				break;
			}
		}
		
		string work = s.substr(start, end-3);
		//cout << "\n\n\n\n" << solve(work) << "\n\n\n\n" << work << "\n\n\n\n\n";
		if (s[start-3]=='n' && s[start-2]=='o' && s[start-1]=='t')
		{
			if (solve(s.substr(start+1, end-4))=='1')
				s = s.substr(0, start-4)+'0'+s.substr(end-2, s.size());
			else
				s = s.substr(0, start-4)+'1'+s.substr(end-2, s.size());
		}
		else
			s = s = s.substr(0, start-1)+'1'+s.substr(end-2, s.size());
			
		//cout << s << "\n";
		s = s.substr(0, 1);
	}
				
	if (s=="1") cout << "true";
	else cout << "false";
	
	return 0;
}

// Программа не до конца правильно работает, но вот её план:
// 1. Все символы, отвечающие за переменные, заменены на 1, если переменная true, и 0, если false. (Строка 69)
// 2. Она заходит в бесконечный цикл, выполняющийся, пока в строке не останется 1 символ.
// 3. В цикле, она находит первую скобку без внутренних скобок и вычисляет в ней выражение функцией solve.
// 4. Функция solve преобразует строку в строку, в которой and заменено на *, а or на +. Затем последовательно вычисляет.
// 5. Если скобка, которую вычислило solve, является частью функции not, то выражение подставляется обратное полученному.
// Короче, скобки вычисляются и подставляются последовательно до тех пор, пока выражение не вычислится полностью.
