eclipse ../alg/backtrack.cc
vector<string> StringPermutation(string str)
vector<string> StringSubset(const string &str)
int NQueen(int queen_number)

class Solution
{
public:
	void StringPermutationMain(string str, int first, int last, vector<string> &result) // [)
	{
		if(first == last) // End recursive
		{
			result.push_back(str);
			return;
		}
		for(int index = first; index < last; ++index)
		{
			if(index != first && str[first] == str[index]) // Not swap repeated data.
			{
				continue;
			}
			swap(str[first], str[index]);
			StringPermutationMain(str, first + 1, last, result);
			//swap(str[first], str[index]); // Pass by reference! Need recover.
		}
	}
	vector<string> Permutation(string str)
	{
		if(str.size() <= 0) // Negative test.
		{
			return vector<string>();
		}
		vector<string> result;
		StringPermutationMain(str, 0, static_cast<int>(str.size()), result);
		return result;
	}
};
通过
您的代码已保存
答案正确:恭喜！您提交的程序通过了所有的测试用例
class Solution
{
public:
	void StringPermutationMain(string &str, int first, int last, vector<string> &result) // [)
	{
		if(first == last) // End recursive
		{
			result.push_back(str);
			return;
		}
		for(int index = first; index < last; ++index)
		{
			if(index != first && str[first] == str[index]) // Not swap repeated data.
			{
				continue;
			}
			swap(str[first], str[index]);
			StringPermutationMain(str, first + 1, last, result);
			swap(str[first], str[index]); // Pass by reference! Need recover.
		}
	}
	vector<string> Permutation(string str)
	{
		if(str.size() <= 0) // Negative test.
		{
			return vector<string>();
		}
		vector<string> result;
		StringPermutationMain(str, 0, static_cast<int>(str.size()), result);
		return result;
	}
};
不通过
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例
case通过率为50.00%
测试用例:
abc
对应输出应该为:
["abc","acb","bac","bca","cab","cba"]
你的输出为:
["abc","acb","bac","bca","cba","cab"]
class Solution
{
public:
	void StringPermutationMain(string &str, int first, int last, vector<string> &result) // [)
	{
		if(first == last) // End recursive
		{
			result.push_back(str);
			return;
		}
		for(int index = first; index < last; ++index)
		{
			if(index != first && str[first] == str[index]) // Not swap repeated data.
			{
				continue;
			}
			swap(str[first], str[index]);
			StringPermutationMain(str, first + 1, last, result);
			//swap(str[first], str[index]); // Pass by reference! Need recover.
		}
	}
	vector<string> Permutation(string str)
	{
		if(str.size() <= 0) // Negative test.
		{
			return vector<string>();
		}
		vector<string> result;
		StringPermutationMain(str, 0, static_cast<int>(str.size()), result);
		return result;
	}
};
不通过
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例
case通过率为40.00%
测试用例:
aab
对应输出应该为:
["aab","aba","baa"]
你的输出为:
["aab","aba","baa","aab","aba"]
