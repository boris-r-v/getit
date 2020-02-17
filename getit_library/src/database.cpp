#include <database.h>

void getit::Database::put( merch_iface_ptr _m )
{
    merch_.push_back( _m );   	
}

getit::merch_list_t const& getit::Database::get( ) const
{
    return merch_;
}

void getit::Database::accept( VisitorIface<DatabaseIface>& _v )
{
    _v.visit( *this );
}
