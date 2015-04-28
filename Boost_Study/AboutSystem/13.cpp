#include <boost/optional.hpp>
#include <boost/foreach.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#define BOOST_SYSTEM_NO_LIB
#define BOOST_FILESYSTEM_NO_LIB
#include <boost/filesystem.hpp>
#define BOOST_PROGRAM_OPTIONS_NO_LIB
#include <boost/program_options.hpp>

using namespace boost::xpressive;
using namespace boost::filesystem;
using namespace boost::program_options;

void print_vm(options_description &opts, variables_map &vm)
{
    if(vm.size() == 0)
    {
        std::cout << opts << std::endl;
        return ;
    }

    if(vm.count("help"))
    {
        std::cout << opts << std::endl;
    }

    std::cout << "find opt : " << vm["filename"].as<std::string>() << std::endl;

    if(vm.count("dir"))
    {
        std::cout << "dir opt : ";
        BOOST_FOREACH(std::string str, vm["dir"].as<std::vector<std::string> >())
        {
            std::cout << str << ",";
        }
        std::cout << std::endl;
    }
    if(vm.count("depth"))
    {
        std::cout << "depth opt : " << vm["depth"].as<int>() << std::endl;
    }
}

std::string name_mapper(const std::string& env_name)
{
    using namespace boost::assign;
    static std::map<std::string, std::string> nm = map_list_of("HOME", "home") ("PATH", "path");
    return nm[env_name];
}

int main(int argc, char* argv[])
{
    //options_description opts("demo options");
    //std::string filename;
    //opts.add_options()
    //    ("help,h", "help message\n  a bit of long text")
    //    ("filename,f", boost::program_options::value<std::string>(&filename)->default_value("test"), "to find a file")
    //    ("dir,D", boost::program_options::value<std::vector<std::string> >()->multitoken(), "search dir")
    //    ("depth,d", boost::program_options::value<int>()->implicit_value(5), "search depth");

    //variables_map vm;
    //store(parse_command_line(argc, argv, opts), vm);
    //notify(vm);
    //print_vm(opts, vm);

    options_description opts("test");
    opts.add_options()
        ("home", boost::program_options::value<std::string>(), "home ")
        ("path", boost::program_options::value<std::string>(), "path ");

    variables_map vm;
    store(parse_environment(opts,name_mapper), vm);
    std::cout << vm["home"].as<std::string>() << std::endl;
    std::cout << vm["path"].as<std::string>() << std::endl;

}
