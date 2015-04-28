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

using namespace boost::program_options;

std::string name_mapper(const std::string& env_name)
{
    using namespace boost::assign;
    static std::map<std::string, std::string> nm = map_list_of("HOME", "home") ("PATH", "path");
    return nm[env_name];
}

int main(int argc, char* argv[])
{

    options_description opts1("group 1");
    opts1.add_options()
        ("help,h", "help message");
    options_description opts2("group 2(hide)");
    opts2.add_options()
        ("filename,f", boost::program_options::value<std::string>(), "to find a file");
    options_description opts3("group 3");
    opts3.add_options()
        ("dir,D", boost::program_options::value<std::vector<std::string> >()->composing(), "search dir")
        ("depth,d", boost::program_options::value<int>(), "search depth");

    options_description opts_all;
    opts_all.add(opts1).add(opts2).add(opts3);
    options_description opts_cfgfile;
    opts_cfgfile.add(opts2).add(opts3);
    options_description opts_showhelp("demo options");
    opts_showhelp.add(opts1).add(opts3);

    variables_map vm;
    store(parse_command_line(argc, argv, opts_all), vm);
    store(parse_config_file<char>("config.ini", opts_cfgfile), vm);

    if(vm.count("help"))
    {
        std::cout << opts_showhelp << std::endl;
    }
}
