#include <bits/stdc++.h>
using namespace std;

// Usage: `T &t = ThreadSafeSingleton<T>::Instance();`
template<typename T>
class ThreadSafeSingleton
{
public:
	ThreadSafeSingleton() = delete;
	ThreadSafeSingleton(const ThreadSafeSingleton&) = delete;
	ThreadSafeSingleton &operator=(const ThreadSafeSingleton&) = delete;
	~ThreadSafeSingleton() = delete;

	static T &Instance()
	{
		// int pthread_once(pthread_once_t *initflag, void(*initfn)());
		// initflag must be a global or static variable and initialized to PTHREAD_ONCE_INIT.
		// OS guarantees that initfn will be called only once on the first call to pthread_once.
		pthread_once(&once_, &Initialize);
		assert(value_ != nullptr);
		return *value_;
	}

private:
	static void Initialize()
	{
		value_ = new T();
	}

	static pthread_once_t once_;
	static T *value_;
};
template<typename T>
pthread_once_t ThreadSafeSingleton<T>::once_ = PTHREAD_ONCE_INIT;
template<typename T>
T *ThreadSafeSingleton<T>::value_ = nullptr;

void Test()
{
	int &i = ThreadSafeSingleton<int>::Instance();
	assert(i == 0);
	printf("All case pass.\n");
}

int main()
{
	Test();
}
