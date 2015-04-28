//只在vagrant_debian下编译通过，Win7编译不过去，不知道咋解决
// g++ 10.cpp -lboost_system -lboost_filesystem 
#include <boost/optional.hpp>
#include <boost/progress.hpp>
#include <boost/foreach.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/typeof/typeof.hpp>
#define BOOST_SYSTEM_NO_LIB
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
        if(!is_directory(*pos) && regex_match(pos->path().filename().string(), rc[filename]))
        {
            v.push_back(pos->path());
        }
    }
}

bool onlyone = false;
size_t copy_files(const path& from_dir, const path& to_dir, const std::string& filename = "*")
{
    if(!is_directory(from_dir))
    {
        if(!onlyone)
        {
            std::cout << "args is not a dir ." << std::endl;
        }
        return 0;
    }
    onlyone = true;
    std::cout << "prepare for copy, please wait ..." << std::endl;
    std::vector<path> v;
    find_files(from_dir, filename, v);
    if(v.empty())
    {
        std::cout << "0 file copied." << std::endl;
        return 0;
    }
    std::cout << "now begin copy files ..." << std::endl;
    path tmp;
    boost::progress_display pd(v.size());
    BOOST_FOREACH(path &p, v)
    {
        tmp = to_dir / p.string().substr(from_dir.string().length());
        if(!exists(tmp.parent_path()))
        {
            create_directories(tmp.parent_path());
        }
        copy_file(p, tmp);
        ++pd;
    }
    std::cout << v.size() << " file copied ." << std::endl;
    return v.size();
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

    copy_files("/root", "/home/code", "*.cpp");
    return 0;
}
