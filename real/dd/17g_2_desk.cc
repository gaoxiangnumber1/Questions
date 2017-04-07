#include <stdio.h>
#include <algorithm>
using namespace std;

struct Customer
{
	int size_;
	int cost_;
};
bool CompareBySize(const Customer &lhs, const Customer &rhs)
{
	return lhs.size_ < rhs.size_;
}
bool CompareByCost(const Customer &lhs, const Customer &rhs)
{
	return lhs.cost_ > rhs.cost_;
}

int main()
{
	const int kCaseMax = 50010, kIntMin = 0x80000000;
	int desk[kCaseMax];
	Customer customer[kCaseMax];
	int desk_number, customer_number;
	while(scanf("%d %d", &desk_number, &customer_number) == 2)
	{
		for(int index = 0; index < desk_number; ++index)
		{
			scanf("%d", &desk[index]);
		}
		for(int index = 0; index < customer_number; ++index)
		{
			scanf("%d %d", &customer[index].size_, &customer[index].cost_);
		}

		sort(desk + 0, desk + desk_number);
		sort(customer + 0, customer + customer_number, CompareBySize);
		int cost = 0;
		for(int desk_index = 0, customer_index = 0; desk_index < desk_number; )
		{
			int desk_size = desk[desk_index];
			int customer_last = customer_index;
			for(; customer_last < customer_number &&
			        customer[customer_last].size_ <= desk_size;
			        ++customer_last);
			sort(customer + customer_index, customer + customer_last, CompareByCost);
			for(; desk_index < desk_number && desk[desk_index] == desk_size; ++desk_index)
			{
				if(customer_index < customer_last)
				{
					cost += customer[customer_index].cost_;
					customer[customer_index].cost_ = kIntMin;
					++customer_index;
				}
				else
				{
					for(; desk_index < desk_number && desk[desk_index] == desk_size;
					        ++desk_index);
					break;
				}
			}
		}
		printf("%d\n", cost);
	}
}
/*
3 5 2 4 2 1 3 3 5 3 7 5 9 1 10
3 1 1 2 3 10 1
3 3 4 5 6 1 1 2 2 3 3
3 5 4 5 6 7 100 5 5 4 0 3 100 6 6

20
0
6
111
*/
