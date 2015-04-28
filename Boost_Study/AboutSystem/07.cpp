//只在vagrant_debian下编译通过，Win7编译不过去，不知道咋解决
// g++ 07.cpp -lboost_system -lboost_filesystem 
#include <boost/typeof/typeof.hpp>
#define BOOST_SYSTEM_NO_LIB
#define BOOST_FILESYSTEM_NO_LIB
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main()
{
    namespace fs = boost::filesystem;

    path ptest = "/root/new";
    if(exists(ptest))
    {
        if(is_empty(ptest))
        {
            fs::remove(ptest);
        }
        else
        {
            remove_all(ptest);
        }
    }
    assert(!exists(ptest));

    create_directory(ptest);

    copy_file("/root/06.cpp", ptest / "test.cpp");
    assert(exists(ptest / "test.cpp"));
    rename(ptest / "test.cpp", ptest / "tt.cpp");
    assert(exists(ptest / "tt.cpp"));

    create_directories(ptest / "sub_dir1" / "sub_dir2");

    directory_iterator end;
    for(directory_iterator pos("/"); pos != end; ++pos)
    {
        std::cout << *pos << std::endl;
    }

    std::cout << "****************************************" << std::endl;
    typedef recursive_directory_iterator rd_iterator;
    rd_iterator endd;
    for(rd_iterator pos("/root"); pos != endd; ++pos)
    {
        std::cout << "level" << pos.level() << " : " << *pos << std::endl;
    }


    std::cout << "****************************************" << std::endl;
    rd_iterator enddd;
    for(rd_iterator pos("/root"); pos != enddd; ++pos)
    {
        if(is_directory(*pos))
        {
            pos.no_push();
        }
        std::cout << *pos << std::endl;
    }

}
