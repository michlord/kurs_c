#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

bool ibanGreaterThan(const std::string& s1,const std::string& s2)
{
	std::string c1 = s1.substr(0,2);
	std::string c2 = s2.substr(0,2);
	if(c1==c2)
	{
		c1 = s1.substr(4,s1.size());
		c2 = s2.substr(4,s2.size());
		return c1>c2;
	}
	return c1>c2;
}

int main()
{
	std::vector<std::string> iban;
	int n;
	std::cin >> n;
	while(n--)
	{
		std::string tmp;
		std::cin >> tmp;
		iban.push_back(tmp);
	}
	std::cout << "RESULT\n";
	std::sort(iban.begin(),iban.end(),ibanGreaterThan);
	std::vector<std::string>::iterator it;
	for(it=iban.begin();it!=iban.end();++it)
	{
		std::cout << *it << "\n";
	}
	return 0;
}