#ifndef GETIT_VISITORS_H
#define GETIT_VISITORS_H

#include <iface.h>

namespace getit
{

    /**
    * @brief This is an algorithm for collecting goods by name of the manufacturer.
    */
    class OrderForProducer final: public VisitorIface<DatabaseIface>, public Invoker<file_lines_t>
    {
	    merch_producer_t const producer_;
	    file_lines_t handle_result( merch_list_t );
	public:
	    OrderForProducer( merch_producer_t const&, std::function< void ( file_lines_t ) > f );
	    virtual void visit( DatabaseIface& ) override; 	        
    };

    /**
    * @brief This is an algorithm for collecting goods by product name 
    */
    class OrderForName final: public VisitorIface<DatabaseIface>, public Invoker<file_lines_t>
    {
	    merch_name_t const name_;
	    file_lines_t handle_result( merch_list_t );
	public:
	    OrderForName( merch_name_t const&, std::function< void ( file_lines_t ) > f );
	    virtual void visit( DatabaseIface& ) override; 	        
    };



}
#endif // GETIT_VISITORS_H