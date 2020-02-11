#include <main.h>
#include <provider.h>
#include <boost/program_options.hpp>		
#include <thread>
#include <boost/asio.hpp>

namespace po = boost::program_options;


void getit::Main::run(int argc, char** argv)
{
    boost::program_options::options_description gen_desc("General options");
    gen_desc.add_options()
    ("help,h", "Produce help message")
    ("indir,i",po::value<std::string>() ,"Specifies a directory with csv-files from customers")
    ("outdir,o",po::value<std::string>() , "Specifies a directory with files for managers ")
    ;

    boost::program_options::options_description desc;
    desc.add(gen_desc);

    po::variables_map vm;
    try
    {
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);    
    }
    catch (po::error& e )
    {
	std::cout << e.what() << std::endl;
	std::cout << desc << std::endl;
	return;
    }

    if ( vm.count("help") )
    {
	std::cout << "  Welcome to getit - sort programm for fruit business  " << std::endl;
	std::cout << "\tType: \"getit --indir=./customers --outdir=./managers\" - to automatic sort inconing requests from dir: ./customers, and put manager files to: ./managers" << std::endl;
	std::cout << "  Copyright, Boris.R <borisrozhkin@gmail.com>" << std::endl << std::endl;

	std::cout << desc << std::endl;
	return;
    }

    if ( vm.count("indir") and vm.count("outdir") )
    {
	getit::Provider pro( vm, service_ );
	pro.run();
	service_.run();
	return;
    }


    std::cout << "Wrong command line options, type ./getit -h - for more information" << std::endl;
    return;
}