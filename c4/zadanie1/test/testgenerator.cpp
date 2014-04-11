#include <fstream>
#include <set>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

template<class T>
std::string toString(const T& t){
    std::ostringstream s;
    s << t;
    return s.str();
}
int main()
{
	const int test_case_amt = 15;
	int test_case_size[test_case_amt] = {1,5,5,7,8,10,15,20,100,150,500,800,999,999,465};
	std::set<int> set1;
	std::set<int> set2;
	std::vector<int> set_union;
	std::vector<int> set_intersection;
	std::ofstream out_in;
	std::ofstream out_out;
	std::string out_in_name;
	std::string out_out_name;
	for(int i=0;i<test_case_amt;++i)
	{
		out_in_name=toString(i)+"in.txt";
		out_out_name=toString(i)+"out.txt";
		set1.clear();set2.clear();set_union.clear();set_intersection.clear();
		int set1_size = test_case_size[i];
		int set2_size = 1+rand()%test_case_size[i]+3*(rand()%2);
		while(set1.size()<set1_size)
			set1.insert(rand()%(test_case_size[i]+15));
		while(set2.size()<set2_size)
			set2.insert(rand()%(test_case_size[i]+15));
		
		std::set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),back_inserter(set_union));
		std::set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),back_inserter(set_intersection));
		out_in.open(out_in_name.c_str());
			if(out_in.is_open()==false)
				return -1;
		out_in << set1.size() << '\n';
		for(std::set<int>::iterator it=set1.begin();it!=set1.end();++it)
			out_in << *it << ' ';
		out_in << '\n' << set2.size() << '\n';
		for(std::set<int>::iterator it=set2.begin();it!=set2.end();++it)
			out_in << *it << ' ';
		out_in.close();
		out_out.open(out_out_name.c_str());
			if(out_out.is_open()==false)
				return -1;
		for(int i=0;i<set_union.size();++i)
			out_out << set_union[i] << ' ';
		out_out << '\n';
		for(int i=0;i<set_intersection.size();++i)
			out_out << set_intersection[i] << ' ';
		out_out.close();
	}
	return 0;
}