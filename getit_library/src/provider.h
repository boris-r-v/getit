#ifndef GETIT_PROVIDER_H
#define GETIT_PROVIDER_H
#include <config.h>
#include <mediator.h>
#include <boost/asio.hpp>
#include <boost/program_options.hpp>		

namespace getit
{
    /**
	@brief Провайдер обеспечивает периодичность проверки набора файлов с задачами менеджеров
	
    */
    class Provider
    {
    	    boost::asio::deadline_timer timer_;
	    Mediator med_;

	    void do_wait();
        public:	
	    Provider( getit::Config const& vm, boost::asio::io_service& io );
	    void run( );
    };
}
#endif //GETIT_PROVIDER_H
