#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>


class Solution 
{
public:
	int myAtoi(std::string str);										// 字符串转int型
	bool isPalindrome(int x);											// 判断int型数据是否为回文
	bool isMatch(std::string s, std::string p);							// 字符串模式匹配 使用递归方式 待完成
	int maxArea(std::vector<int>& height);								// 输入n个非负数，输出两个数组成的最大容积
	std::string intToRoman(int num);									// 整型转罗马数字
	int romanToInt(std::string s);										// 罗马数字转整型
	std::string longestCommonPrefix(std::vector<std::string>& strs);	// 查找最长相同前缀
	std::vector<std::vector<int>> threesum(std::vector<int>& nums);		// 
};

int Solution::myAtoi(std::string str)
{
	int intMax = int(unsigned(~0) >> 1);
	int intMin = -int(unsigned(~0) >> 1) - 1;
	bool isMinus = false;
	unsigned resTemp = 0;
	int res = 0;

	if (str.length() == 0) return 0;

	// 去除字符串前缀
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i])) return 0;
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+') continue;
		else
		{
			str = str.substr(i, str.length() - i);
			break;
		}
	}
	// 判断是否为负数 
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-') isMinus = true;
		str = str.substr(1, str.length() - 1);
	}
	// 开始解析
	int index = 0;
	while (isdigit(str[index]))
	{
		unsigned temp = unsigned(str[index] - '0');
		if (!isMinus && ((resTemp > unsigned(intMax) / 10) || (resTemp == unsigned(intMax) / 10 && temp >= unsigned(intMax) % 10)))
		{
			return intMax;
			break;
		}
		if (isMinus && ((resTemp > unsigned(intMin) / 10) || (resTemp == unsigned(intMin) / 10 && temp >= unsigned(intMin) % 10)))
		{
			return intMin;
			break;
		}
		resTemp = resTemp * 10 + temp;
		index++;
	}
	res = isMinus ? -int(resTemp) : int(resTemp);
	return res;
}

bool Solution::isPalindrome(int x)
{
	bool res = true;
	std::string str;
	if (x < 0) return false;
	while (x != 0)
	{
		str.push_back(char(x % 10) + '0');
		x /= 10;
	}
	for (size_t i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - i - 1])
		{
			res = false;
			break;
		}
	}
	return res;
}

bool Solution::isMatch(std::string s, std::string p)
{
	return false;
}

int Solution::maxArea(std::vector<int>& height)
{		
	int m = 0;
	for (int i = 0, j = height.size() - 1; i < j;) {
		m = std::max(m, (j - i) * std::min(height[i], height[j]));
		height[i] < height[j] ? i++ : j--;
	}
	return m;
}

std::string Solution::intToRoman(int num)
{
	std::string res;
	int c[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	std::string str[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int n = 0;
	for (int i = 0; num && i < 13; i++) {
		n = num / c[i];
		for (int j = 0; j < n; j++) {
			res += str[i];
		}
		num -= c[i] * n;
	}
	return res;
}

int Solution::romanToInt(std::string s)
{
	int res = 0;
	int c1[] = { 900, 400, 90, 40, 9, 4 };
	std::string str1[] = { "CM", "CD", "XC", "XL", "IX", "IV"};
	int c2[] = { 1000, 500, 100, 50, 10, 5, 1 };
	std::string str2[] = { "M", "D", "C", "L", "X", "V", "I" };
	for (size_t i = 0; i < 6; i++)
	{
		while (s.find(str1[i]) != std::string::npos)
		{
			size_t pos = s.find(str1[i]);
			res += c1[i];
			s = s.substr(0, pos) + s.substr(pos + 2, s.length() - pos - 2);
		}
	}
	for (size_t i = 0; i < 7; i++)
	{
		while (s.find(str2[i]) != std::string::npos)
		{
			size_t pos = s.find(str2[i]);
			res += c2[i];
			s = s.substr(0, pos) + s.substr(pos + 1, s.length() - pos - 1);
		}
	}
	return res;
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
{
	std::string res;
	if (strs.empty()) return res;
	size_t minLen = strs[0].length();
	int minLenIndex = 0;
	// 找到最短的字符串
	for (size_t i = 0; i < strs.size(); i++)
	{
		if (strs[i].length() < minLen)
		{
			minLen = strs[i].length();
			minLenIndex = i;
		}
	}
	for (size_t i = 0; i < strs[minLenIndex].length(); i++)
	{
		char temp = strs[minLenIndex][i];
		size_t j = 0;
		for (j = 0; j < strs.size(); j++)
		{
			if (strs[j][i] != temp) break;
		}
		if (j >= strs.size()) res.push_back(temp);
		else break;
	}
	return res;
}

std::vector<std::vector<int>> Solution::threesum(std::vector<int>& nums)
{
	return std::vector<std::vector<int>>();
}


int main()
{
	Solution solution;
	std::string str = "MCMXCIV";
	solution.romanToInt(str);
	return 0;
}

