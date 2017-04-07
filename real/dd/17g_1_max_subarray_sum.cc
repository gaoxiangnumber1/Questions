#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int length;
	while(scanf("%d", &length) == 1)
	{
		int data[length];
		for(int index = 0; index < length; ++index)
		{
			scanf("%d", &data[index]);
		}

		// Max sum of sub-array that ends with [index], initial 0.
		int current_max_sum = data[0];
		int max_sum = current_max_sum; // Max among all current_max_sum.
		for(int index = 1; index < length; ++index)
		{
			if(current_max_sum <= 0)
			{
				current_max_sum = data[index];
			}
			else
			{
				current_max_sum += data[index];
			}
			max_sum = max(max_sum, current_max_sum);
		}
		printf("%d\n", max_sum);
	}
}
/*
1 10
3 -1 -5 -2
3 -1 0 -2
6 1 1 1 1 1 1
6 -1 0 1 1 1 1
6 -1 0 -1 0 -1 0
6 -1 0 2 -1 0 0
6 -5 -4 -1 -2 -3 -6
6 -5 0 10 -2 -3 9
6 -2 11 -4 13 -5 -2
6 5 -8 3 2 5 0
10 -10 1 2 3 4 -5 -23 3 7 -21

10
-1
0
6
4
0
2
-1
14
20
10
10
*/
