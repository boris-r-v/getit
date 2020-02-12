#ifndef GETIT_VISITORS_H
#define GETIT_VISITORS_H

#include <iface.h>

namespace getit
{

    /**
    * @brief This is an algorithm for collecting goods by name of the manufacturer.
    */
    class OrderForProducer final: public VisitorIface<DatabaseIface>
    {
	    merch_producer_t const producer_;
	public:
	    OrderForProducer( merch_producer_t const& );
	    virtual void visit( DatabaseIface& ) override; 	        
    };

    /**
    * @brief This is an algorithm for collecting goods by product name 
    */
    class OrderForName final: public VisitorIface<DatabaseIface>
    {
	    merch_name_t const name_;
	public:
	    OrderForName( merch_name_t const& );
	    virtual void visit( DatabaseIface& ) override; 	        
    };



}
#endif // GETIT_VISITORS_H