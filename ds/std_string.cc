#include "../common_system_header.h"

bool can_print = false;
class String
{
public:
	// Default ctor
	String() :
		data_(new char[1]), size_(0)
	{
		*data_ = 0;
		can_print ? printf("Default_ctor    ") : 0;
	}
	String(const char *data, size_t size) :
		data_(new char[size + 1]), size_(size)
	{
		memcpy(data_, data, size_);
		data_[size_] = 0;
		can_print ? printf("Const_char_*length_ctor    ") : 0;
	}
	String(const char *data) :
		String(data, strlen(data)) // Delegating ctor
	{
		can_print ? printf("Const_char_*ctor    ") : 0;
	}
	// Copy ctor
	String(const String &rhs) :
		String(rhs.data_, rhs.size_)
	{
		can_print ? printf("Copy_ctor    ") : 0;
	}
	// Move ctor
	String(String &&rhs) noexcept:
	data_(rhs.data_), size_(rhs.size_)
	{
		rhs.data_ = nullptr;
		rhs.size_ = 0;
		can_print ? printf("Move_ctor    ") : 0;
	}

	// Non-throwing swap
	void Swap(String &rhs) noexcept
	{
		swap(data_, rhs.data_);
		swap(size_, rhs.size_);
		can_print ? printf("Swap    ") : 0;
	}
	// Unifying assignment operator: no need to write copy/move assignment operator.
	String &operator=(String rhs)// Copy and Swap idiom.
	{
		Swap(rhs);
		can_print ? printf("Unifying-AO    ") : 0;
		return *this;
	}
	/*	// If not use copy and swap.
	 String &operator=(const String &rhs)
	 {
	 char *tmp = new char[rhs.size_ + 1];
	 memcpy(tmp, rhs.data_, rhs.size_);
	 tmp[rhs.size_] = 0; // Deep copy rhs to tmp.
	 delete [] data_;// Destruct lhs.
	 data_ = tmp;
	 size_ = rhs.size_;// Shallow copy tmp and other members to lhs.
	 return *this;
	 }
	 String &operator=(String &&rhs) noexcept
	 {
	 if(this != &rhs) // Have to check since not copy to tmp.
	 {
	 delete [] data_;
	 data_ = rhs.data_;
	 size_ = rhs.size_;
	 rhs.data_ = nullptr;
	 rhs.size_ = 0;
	 }
	 return *this;
	 }*/
	// Dtor
	~String()
	{
		delete[] data_;
		can_print ? printf("Dtor    ") : 0;
	}

	const char *data() const
	{
		return data_;
	}
	size_t size() const
	{
		return size_;
	}

private:
	char *data_;
	size_t size_; // long unsigned int
};
namespace std
{
template<>
void swap(String &lhs, String &rhs) noexcept
{
	lhs.Swap(rhs);
}
}
/////////////////////
void PassByValue(String s)
{
	can_print ? printf("passed = %s    ", s.data()) : 0;
}
void PassByConstReference(const String &s)
{
	can_print ? printf("\npassed = %s\n", s.data()) : 0;
}
String ReturnByValue(const char *data)
{
	String ret(data);
	can_print ? printf("ret = %s\t", ret.data()) : 0;
	return ret;
}
void DetailTest()
{
	//	Test copy-elision between (String) and (const String&)
	String s;
	s = ReturnByValue("gao");
	printf("%s\n", s.data());

	printf("----------Test Ctor----------\n");
	String s0;
	printf("s0 = %s, s0.size() = %d\n", s0.data(), static_cast<int>(s0.size()));
	String s1("gao");
	printf("s1 = %s\n", s1.data());
	String s2 = "xiang"; // Equivalent to `String s3("xiang");`
	printf("s2 = %s\n", s2.data());
	String s3(s1);
	printf("s3 = %s\n", s3.data());
	String s4(move(String("number1")));
	printf("s4 = %s\n", s4.data());

	printf("----------Test Copy/Move Assignment Operator----------\n");
	// The following two assignment are errors if define move ctor/assignment_operator.
	// error: use of deleted function ‘String& String::operator=(const String&)’
	// note: ‘String& String::operator=(const String&)’ is implicitly declared as deleted
	// because ‘String’ declares a move constructor or move assignment operator
	s2 = s4;
	printf("s2 = %s\n", s2.data());
	s2 = s2;
	printf("s2 = %s\n", s2.data());
	s2 = move(s1);
	printf("s2 = %s, s1 = %s\n", s2.data(), s1.data());
	s2 = move(s2);
	printf("s2 = %s\n", s2.data());
	s1 = "xiang";
	printf("s1 = %s\n", s1.data());

	printf("----------Test as Parameter/Return type----------\n");
	PassByValue(s1);
	PassByConstReference(s1);
	String s5(ReturnByValue("hello")); // The returned temporary object is moved to s5.
	printf("s5 = %s\n", s5.data());
	s5 = ReturnByValue("world");
	printf("s5 = %s\n", s5.data());

	printf("----------Test as value_type of STL container----------\n");
	vector<String> vec;
	vec.push_back(s1);
	printf("vec[0] = %s\n", vec[0].data());
	vec.push_back(s2);
	printf("vec[0] = %s\tvec[1] = %s\n", vec[0].data(), vec[1].data());
	vec.push_back("gaoxiangnumber1");
	printf("vec[0] = %s\tvec[1] = %s\tvec[2] = %s\n", vec[0].data(), vec[1].data(), vec[2].data());

	printf("All case pass\n");
}
void Test()
{
	String s1; // Default ctor
	assert(memcmp(s1.data(), "", 1) == 0);
	String s2("gao"); // 2 and 3 ctor
	assert(memcmp(s2.data(), "gao", 4) == 0);
	String s3(s2); // Copy ctor
	assert(memcmp(s3.data(), "gao", 4) == 0);
	String s4(move(s2)); // Move ctor
	assert(s2.data() == nullptr && s2.size() == 0);
	assert(memcmp(s4.data(), "gao", 4) == 0);
	s2 = "xiang"; // Copy assignment: not self.
	assert(memcmp(s2.data(), "xiang", 6) == 0);
	s2 = s2; // Copy assignment: self.
	assert(memcmp(s2.data(), "xiang", 6) == 0);
	s4 = move(s2); // Move assignment: not self.
	assert(s2.data() == nullptr && s2.size() == 0);
	assert(memcmp(s4.data(), "xiang", 6) == 0);
	s4 = move(s4); // Move assignment: self.
	assert(memcmp(s4.data(), "xiang", 6) == 0);
	printf("All case pass\n");
}

int main()
{
	Test();
}
