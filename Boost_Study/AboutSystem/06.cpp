//只在vagrant_debian下编译通过，Win7编译不过去，不知道咋解决
// g++ 06.cpp -lboost_system -lboost_filesystem 
#include <boost/typeof/typeof.hpp>
#define BOOST_SYSTEM_NO_LIB
#define BOOST_FILESYSTEM_NO_LIB
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main()
{
	path p30;
	assert(p30.empty());

	const char str[] = "the path is (/root).";
	path p(str + 13, str + 14);
	assert(!p.empty());
	p /= "etc";
	std::string filename = "xinetd.conf";
	p.append(filename.begin(), filename.end());
	std::cout << p << std::endl;

    std::string fname("w+abc.xxx");
    assert(!portable_posix_name(fname));
    assert(windows_name(fname));

    path pp("/root/1.xxx");
    std::cout << pp.string() << std::endl;
    std::cout << pp.parent_path() << std::endl;
    std::cout << pp.stem() << std::endl;
    std::cout << pp.filename() << std::endl;
    std::cout << pp.extension() << std::endl;

    assert(pp.is_complete());
    assert(system_complete(pp).is_complete());

    std::cout << "--------------------------------" << std::endl;
    std::cout << pp.replace_extension() << std::endl;
    try
    {
        std::cout << pp.replace_extension("cpp") << std::endl;
    }
    catch(filesystem_error& e)
    {
        std::cout << e.path1() << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << pp.remove_filename() << std::endl;

    std::cout << "--------------------------------" << std::endl;

    path p1("c:/test/1.cpp");
    path p2("c:/TEST/1.cpp");
    path p3("c:/abc/1.cpp");

    assert(p1 != p2);
    assert(p2 < p3);

    path p4 = "/boost/tools/libs";
    BOOST_AUTO(pos, p4.begin());
    while(pos != p4.end())
    {
        std::cout << "[" << *pos << "]";
        ++pos;
    }
    std::cout << std::endl;

    std::cout << "--------------------------------" << std::endl;

    path pp1("/root/nofile");
    try
    {
        file_size(pp1);
    }
    catch(filesystem_error& e)
    {
        std::cout << e.path1() << std::endl;
        std::cout << e.what() << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;
    assert(status("/dev/null").type() == character_file);
    assert(status("/root").type() == directory_file);
    assert(status("/bin/sh").type() == regular_file);
    assert(is_directory("/root/"));
    assert(!exists("/root/nofile"));
    assert(!is_symlink("/root"));
    assert(!is_other("/root"));
    assert(is_regular_file("/root/1.xxx"));
    assert(!is_empty("/root/smartptr"));

    std::cout << initial_path() << std::endl;
    std::cout << current_path() << std::endl;

    path ppt("/root/smartptr/1.cpp");
    std::cout << file_size(ppt) << std::endl;
    time_t t = last_write_time(ppt);
    std::cout << t << std::endl;
    last_write_time(ppt, time(0));
    time_t t1 = last_write_time(ppt);
    std::cout << t1 << std::endl;

    std::cout << "--------------------------------" << std::endl;
    const int GBYTES = 1024*1024*1024;
    space_info si = space("/");
    std::cout << si.capacity / GBYTES << std::endl;
    std::cout << si.available / GBYTES << std::endl;
    std::cout << si.free / GBYTES << std::endl;
}

