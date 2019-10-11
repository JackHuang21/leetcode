#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>


class Solution 
{
public:
	int myAtoi(std::string str);					// �ַ���תint��
	bool isPalindrome(int x);						// �ж�int�������Ƿ�Ϊ����
	bool isMatch(std::string s, std::string p);		// �ַ���ģʽƥ��
};

int Solution::myAtoi(std::string str)
{
	int intMax = int(unsigned(~0) >> 1);
	int intMin = -int(unsigned(~0) >> 1) - 1;
	bool isMinus = false;
	unsigned resTemp = 0;
	int res = 0;

	if (str.length() == 0) return 0;

	// ȥ���ַ���ǰ׺
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
	// �ж��Ƿ�Ϊ���� 
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-') isMinus = true;
		str = str.substr(1, str.length() - 1);
	}
	// ��ʼ����
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
	bool res = false;
	size_t pIndex = 0;
	char lastChar;
	bool keep = false;
	size_t i = 0;

	if (s.length() == 0 || p.length() == 0) return false;
	for (i = 0; i < s.length(); i++)
	{
		if (!keep && pIndex >= p.length())
		{
			res = false;
			break;
		}
		if (p[pIndex] == '.')
		{
			pIndex++;
			continue;
		}
		else if (p[pIndex] == '*')
		{
			lastChar = p[pIndex - 1];
			pIndex++;
			keep = true;
			if (lastChar == '.')
			{
				pIndex++;
				continue;
			}
		}
		else
		{
			if (keep && s[i] == lastChar) continue;
			else
			{
				keep = false;
				if (s[i] != p[pIndex])
				{
					if (pIndex + 1 < p.length())
					{
						if (p[pIndex + 1] == '*')
						{
							pIndex += 2;
							continue;
						}
						else
						{
							res = false;
							break;
						}
					}
					else
					{
						res = false;
						break;
					}
				}
				else
				{
					pIndex++;
				}
			}
		}
		
	}
	if (i == s.length())
	{
		for (size_t j = pIndex; j < p.length(); j++)
		{
			if (p[j] != '*')
			{
				return false;
			}
		}
	}
	return res;
}


int main()
{
	Solution solution;
	std::string source = "aab";
	std::string pattern = "c*a*b*";
	std::cout << solution.isMatch(source, pattern) << std::endl;
	return 0;
}

