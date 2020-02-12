#ifndef GETIT_IFACE_H
#define GETIT_IFACE_H

#include <iface.h>

#include <string>
#include <list>
#include <memory>

namespace getit
{
    typedef std::string merch_name_t;
    typedef std::string merch_producer_t;
    typedef double merch_price_t;
    typedef double merch_weight_t;
    /**
	@brief Merch interface
    */
    class MerchIface
    {
	public:
	    virtual merch_price_t price() const = 0;
	    virtual merch_weight_t weight() const = 0;
	    virtual merch_name_t const& name() const = 0;
	    virtual merch_producer_t const& producer() const = 0;
    };
    typedef std::shared_ptr< MerchIface > merch_iface_ptr;

    typedef std::list< merch_iface_ptr > merch_list_t;

    /**
	@brief DatabaseVisitorIface
    */
    template <typename T>
    class VisitorIface
    {
	public:
	    virtual void visit( T& ) = 0; 	        
    };
    /**
	@brief Database interface
    */
    class DatabaseIface
    {
	public:
	    virtual void put( merch_iface_ptr ) = 0;
	    virtual merch_list_t const& get( ) const = 0;
	    virtual void accept( VisitorIface<DatabaseIface>& ) = 0;
    };

}
#endif // GETIT_IFACE_H
