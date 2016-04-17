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

/* Solution1: Use constructor. */
class Foo
{
public:
	static int num_;  // This is declaration, NOT definition!!!
	static int sum_;  // This is declaration, NOT definition!!!

	Foo()
	{
		++num_;
		sum_ += num_;
	}
};

// Below two lines are definition for num_ and sum_, if we omit them:
// "undefined reference to `Foo::num_'"
int Foo::num_ = 0;
int Foo::sum_ = 0;

int Sum_Solution(int n)
{
	// Negative data:
	if(n < 1)
	{
		return 0;
	}

	Foo::num_ = Foo::sum_ = 0;
	Foo array[n];
	return array[0].sum_;
}

/* Solution 2 : Use virtual function*/
class Father
{
public:
	virtual int sum(int n)
	{
		return 0;
	}
};

Father *array[2];

class Child : public Father
{
public:
	int sum(int n)
	{
		return array[!!n]->sum(n - 1) + n;
	}
};

int Solution2(int n)
{
	Father father;
	Child child;
	array[0] = &father;
	array[1] = &child;
	return array[1]->sum(n);
}

/* Solution 3 : Use function pointer */
typedef int (*Fun) (int);

int End(int n)
{
	return 0;
}

int Solution3(int n)
{
	if(n < 1)
	{
		return 0;
	}

	Fun fun[2] = {End, Solution3};
	return n + fun[!!n](n - 1);
}

/* Solution 4: Use template */
template<int n>
struct Solution4
{
	enum {SUM = Solution4<n - 1>::SUM + n};
};

template<>
struct Solution4<1>
{
	enum {SUM = 1};
};

int main()
{
	cout << Solution4<100>::SUM << endl;
	while(1)
	{
		cout << "Input: ";
		int n;
		cin >> n;
		cout << (n * (n + 1) / 2) << '\t'
		<< Solution1(n) << '\t'
		<< Solution2(n) << '\t'
		<< Solution3(n) << '\t' << endl;
	}
}
