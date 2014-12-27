#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/tokenizer.hpp>
using namespace boost;
using namespace std;

template<typename T>
void print(T &tok)
{
	for(BOOST_AUTO(pos, tok.begin()); pos!=tok.end(); ++pos)
	{
		cout << '[' << *pos << ']';
	}
	cout << endl;
}

template<typename Func, typename String = std::string>
struct tokenizer_wrapper
{
	//typedef typenam Func::string_type String;
	typedef tokenizer<Func, typename String::const_iterator, String> type;
};

int main()
{
	//wstring str(L"Link mario samus");
	//typedef split_iterator<wstring::iterator> string_split_iterator;
	//string_split_iterator p, endp;
	//for(p=make_split_iterator(str, first_finder(L" ", is_iequal()));
	//	p!=endp; ++p)
	//{
	//	wcout << L"[" << *p << L"]";
	//}

	wstring str(L"Link mario samus");
	char_separator<wchar_t> sep(L" ");
	tokenizer<char_separator<wchar_t>, wstring::const_iterator, wstring > tok(str, sep);
	for(BOOST_AUTO(pos, tok.begin()); pos!=tok.end(); ++pos)
	{
		wcout << L"[" << *pos << L"]";
	}

	//wstring str(L"Link mario samus");
	//escaped_list_separator<wchar_t> sep;
	//tokenizer<escaped_list_separator<wchar_t>, wstring::const_iterator, wstring> tok(str, sep);
	//for(BOOST_AUTO(pos, tok.begin()); pos!=tok.end(); ++pos)
	//{
	//	wcout << L"[" << *pos << L"]";
	//}
}