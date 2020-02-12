#include <provider.h>
static unsigned CHECK_PERIOD (3);

getit::Provider::Provider( getit::Config const& vm, boost::asio::io_service& io ):
    timer_ ( io )
{
//    std::cout << "getif::Provider ctor: " << vm["indir"].as<std::string>() << " " << vm["outdir"].as<std::string>() << " " << vm["config"].as<std::string>() << std::endl;
}

void getit::Provider::run( )
{
    do_wait();
}

void getit::Provider::do_wait()
{

    std::cout << " getit::harrier::do_wait "  << std::endl;

    /*here puts a regular work tasks*/

    timer_.expires_from_now( boost::posix_time::seconds( CHECK_PERIOD ) );
    timer_.async_wait ( [this](boost::system::error_code ec)
    {
	
	do_wait();	    

    });

}