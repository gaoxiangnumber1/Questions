#ifndef COMMON_SYSTEM_HEADER_H_
#define COMMON_SYSTEM_HEADER_H_

#include <bits/stdc++.h>
using namespace std;

void PrintVector(const vector<int> &vec)
{
	for(int index = 0; index < static_cast<int>(vec.size()); ++index)
	{
		printf("%d ", vec[index]);
	}
	printf("\n");
}
void AssertVectorData(const vector<int> &v1, const vector<int> &v2)
{
	if(v1.size() != v2.size())
	{
		printf("FATAL: v1.size=%lu,v2.size=%lu\n", v1.size(), v2.size());
		PrintVector(v1);
		PrintVector(v2);
		assert(0);
	}
	for(int i = 0; i < static_cast<int>(v1.size()); ++i)
	{
		if(v1[i] != v2[i])
		{
			printf("FATAL: vector data not match.\n");
			PrintVector(v1);
			PrintVector(v2);
			assert(0);
		}
	}
}
#endif
