/*
------------------------------Function Test Data------------------------------
n > 0 && m > 0

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
n <= 0 || m <= 0

*/
#include <iostream>
#include <list>
using namespace std;

const unsigned int kMax = 0x7fffffff;

int LastRemaining_Solution(unsigned int n, unsigned int m)
{
	if((0 < n && n <= kMax) && (0 < m && m <= kMax))
	{
		list<int> circle;
		for(unsigned int num = 0; num < n; ++num)
		{
			circle.push_back(num);
		}

		list<int>::iterator it = circle.begin();
		while(circle.size() != 1)
		{
			for(unsigned int cnt = 1; cnt < m; ++cnt)
			{
				++it;
				if(it == circle.end())
				{
					it = circle.begin();
				}
			}

			list<int>::iterator temp = it++;
			if(it == circle.end())
			{
				it = circle.begin();
			}
			circle.erase(temp);
		}
		return *circle.begin();
	}
	return -1;
}

int LastRemaining_Solution(unsigned int n, unsigned int m)
{
	if((0 < n && n <= kMax) && (0 < m && m <= kMax))
	// WRONG: if((0 < n <= kMax) && (0 < m <= kMax))
	{
		int last = 0;
		for(unsigned int num = 2; num <= n; ++num)
		{
			last = (last + m) % num;
		}
		return last;
	}
	return -1;
}

int main()
{
	while(1)
	{
		cout << "Input n, m: ";
		unsigned int n, m;
		cin >> n >> m;
		cout << Fun1(n, m) << '\t' << Fun2(n, m) << endl;
	}
	return 0;
}
