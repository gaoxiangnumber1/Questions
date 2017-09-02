#include <bits/stdc++.h>
using namespace std;

class NonCopyable // Class that disallow copy or assignment. Object semantics.
{
public:
	NonCopyable() = default; // Constructor
	~NonCopyable() = default; // Destructor

	NonCopyable(const NonCopyable&) = delete; // Copy constructor
	NonCopyable &operator=(const NonCopyable&) = delete; // Copy assignment operator
};

// Usage: `Test &test = Singleton<Test>::Instance();`
template<typename T>
class Singleton: public NonCopyable
{
public:
	static T &Instance()
	{
		// #include <pthread.h>
		// pthread_once_t initflag = PTHREAD_ONCE_INIT;
		// int pthread_once(pthread_once_t *initflag, void(*initfn)());
		// Return 0 if OK, error number on failure.
		// initflag must be a nonlocal variable(i.e., global or static) and initialized to
		// PTHREAD_ONCE_INIT.
		// If each thread calls pthread_once, the system guarantees that the initialization
		// routine, initfn, will be called only once, on the first call to pthread_once.
		::pthread_once(&once_, &Singleton::Initialize);
		assert(value_ != nullptr);
		return *value_;
	}

private:
	Singleton();
	~Singleton();

	static void Initialize()
	{
		value_ = new T();
	}

	static pthread_once_t once_;
	static T *value_;
};
template<typename T>
pthread_once_t Singleton<T>::once_ = PTHREAD_ONCE_INIT;
template<typename T>
T *Singleton<T>::value_ = nullptr;

void Test()
{
	int i = Singleton<int>::Instance();
	assert(i == 0);
	printf("All case pass.\n");
}

int main()
{
	Test();
}
