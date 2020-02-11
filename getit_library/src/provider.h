#ifndef GETIT_PROVIDER_H
#define GETIT_PROVIDER_H
/**
    @brief Class Provider - создает требуемые структуры данных для решения целевой задачи: компоновки заказов 
	
*/

#include <boost/asio.hpp>
#include <boost/program_options.hpp>		

namespace getit
{
    class Provider
    {
    	    boost::asio::deadline_timer timer_;

	    void do_wait();
        public:	
	    Provider( boost::program_options::variables_map const& vm, boost::asio::io_service& io );
	    void run( );
    };
}
#endif //GETIT_PROVIDER_H
