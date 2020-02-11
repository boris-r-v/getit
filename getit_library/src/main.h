#ifndef GETIT_MAIN_H
#define GETIT_MAIN_H
/**
    @brief Class Main - запускает программу используя опции командной строки.
	
*/
#include <boost/asio.hpp>

namespace getit
{
    class Main
    {
	    boost::asio::io_service service_;
        public:		
	    void run(int argc, char** argv);
    };
}
#endif //GETIT_MAIN_H
