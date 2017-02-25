/*
------------------------------Function Test Data------------------------------
n >= 1

--------------------------------Edge Test Data--------------------------------
none

------------------------------Negative Test Data------------------------------
n < 1

*/
#include <iostream>
using namespace std;

/*
x + y = x | y + x & y.
Prove:
x is 0 or 1; y is 0 or 1:
0 + 0 = 0;	0 | 0 + 0 & 0 = 0
0 + 1 = 1;	0 | 1 + 0 & 1 = 1
1 + 0 = 1;	1 | 0 + 1 & 0 = 1
1 + 1 = 10;	1 | 1 + 1 & 1 = 10
*/
int Add(int num1, int num2)
{
	return (num1 | num2) + (num1 & num2);
}

int main()
{
	while(1)
	{
		for(int num1 = -100; num1 < 100; ++num1)
		{
			if((num1 * 2 + 999) - Add(num1, 999+num1) != 0)
			{
				cout << "WRONG\n";
			}
		}
		break;
	}
}
