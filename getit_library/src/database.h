#ifndef GETIT_DATABASE_H
#define GETIT_DATABASE_H

#include <iface.h>

namespace getit
{
    /**
	@brief Импелементация интерфейса базы данных
    */
    class Database final: public DatabaseIface
    {
	    merch_list_t merch_;
	public:	
	    virtual void put( merch_iface_ptr ) override;
	    virtual merch_list_t const& get( ) const  override;
	    virtual void accept( VisitorIface<DatabaseIface>& )  override;
	    

    };
}
#endif // GETIT_DATABASE_H

