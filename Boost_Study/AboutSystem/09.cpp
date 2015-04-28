//只在vagrant_debian下编译通过，Win7编译不过去，不知道咋解决
// g++ 09.cpp -lboost_system -lboost_filesystem 
#include <boost/optional.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/typeof/typeof.hpp>
#define BOOST_SYSTEM_NO_LIB
#define BOOST_FILESYSTEM_NO_LIB
#include <boost/filesystem.hpp>

using namespace boost::xpressive;
using namespace boost::filesystem;

typedef recursive_directory_iterator rd_iterator;

void find_files(const path& dir, const std::string& filename, std::vector<path>& v)
{
    static boost::xpressive::sregex_compiler rc;
    if(!rc[filename].regex_id())
    {
        std::string str = boost::replace_all_copy(boost::replace_all_copy(filename, ".", "\\."), "*", ".*");
        rc[filename] = rc.compile(str);
    }
    typedef std::vector<path> result_type;
    if(!exists(dir) || !is_directory(dir))
    {
        return;
    }
    rd_iterator end;
    for(rd_iterator pos(dir); pos != end; ++pos)
    {
        if(!is_directory(*pos) && regex_match(pos->path().filename(), rc[filename]))
        {
            v.push_back(pos->path());
        }
    }
}

int main()
{
    std::vector<path> v;
    find_files("/root", "*.cpp", v);
    std::cout << v.size() << std::endl;

    BOOST_FOREACH(path &p, v)
    {
        std::cout << p << std::endl;
    }
}
