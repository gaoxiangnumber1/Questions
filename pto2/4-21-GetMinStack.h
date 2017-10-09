eclipse ../ds/stack.cc
class GetMinStack

class Solution
{
public:
	void push(int val)
	{
		data_.push(val);
		min_.push((min_.empty() || min_.top() > val) ? val : min_.top());
	}
	void pop()
	{
		data_.empty() ? void(0) : (data_.pop(), min_.pop());
	}
	int top()
	{
		return data_.empty() ? int() : data_.top();
	}
	int min()
	{
		return min_.empty() ? int() : min_.top();
	}

private:
	stack<int> data_;
	stack<int> min_;
};
