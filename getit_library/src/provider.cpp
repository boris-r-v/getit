#include <provider.h>
#include <file.h>

static unsigned CHECK_PERIOD (3);

getit::Provider::Provider( getit::Config const& vm, boost::asio::io_service& io ):
    timer_ ( io ),
    med_ ( vm )
{
}

void getit::Provider::run( )
{
    do_wait();
}

void getit::Provider::do_wait()
{
    med_.do_it();

    timer_.expires_from_now( boost::posix_time::seconds( CHECK_PERIOD ) );
    timer_.async_wait ( [this](boost::system::error_code ec)
    {
	do_wait();	    
    });
}