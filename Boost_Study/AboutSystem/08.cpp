//只在vagrant_debian下编译通过，Win7编译不过去，不知道咋解决
// g++ 08.cpp -lboost_system -lboost_filesystem 
#include <iostream>
#include <boost/optional.hpp>
#include <boost/typeof/typeof.hpp>
#define BOOST_SYSTEM_NO_LIB
#define BOOST_FILESYSTEM_NO_LIB
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

typedef recursive_directory_iterator rd_iterator;

boost::optional<path> find_file(const path& dir, const std::string& filename)
{
    typedef boost::optional<path> result_type;
    if(!exists(dir) || !is_directory(dir))
    {
        return result_type();
    }

    rd_iterator end;
    for(rd_iterator pos(dir); pos != end; ++pos)
    {
        if(!is_directory(*pos) && pos->path().filename() == filename)
        {
            return result_type(pos->path());
        }
    }
    return result_type();
}

int main()
{
    boost::optional<path> r = find_file("/root", "06.cpp");
    if(r)
    {
        std::cout << *r << std::endl;
    }
    else
    {
        std::cout << "file not found." << std::endl;
    }
}
