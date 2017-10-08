#ifndef COMMON_SYSTEM_HEADER_H_
#define COMMON_SYSTEM_HEADER_H_

#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
using Row = vector<int>;
using Matrix = vector<vector<int>>;
template<typename T>
void PrintVector(const vector<T> &vec)
{
	for(int index = 0; index < static_cast<int>(vec.size()); ++index)
	{
		cout << vec[index] << " ";
	}
	printf("\n");
}
template<typename T>
void AssertVectorData(const vector<T> &v1, const vector<T> &v2)
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
void AssertTwoDimensionVectorData(const Matrix &m1, const Matrix &m2)
{
	if(m1.size() != m2.size())
	{
		printf("FATAL: m1.size=%lu,m2.size=%lu\n", m1.size(), m2.size());
		assert(0);
	}
	for(int i = 0; i < static_cast<int>(m1.size()); ++i)
	{
		AssertVectorData(m1[i], m2[i]);
	}
}
//////////////////////////////////////////////////////////////////////
void Test()
{
	printf("-----Test-----\n");
	printf("All case pass.\n");
}
//////////////////////////////////////////////////////////////////////
#endif
