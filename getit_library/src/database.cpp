#include <database.h>
#include <iostream>
void getit::Database::put( merch_iface_ptr _m )
{
    merch_.push_back( _m );   	
    for ( auto a : merch_ )
	std::cout << a->name() << " : "  << a->producer() << " : "  << a->price() << " : " << a->weight() << std::endl;
}

getit::merch_list_t const& getit::Database::get( ) const
{
    return merch_;
}

void getit::Database::accept( VisitorIface<DatabaseIface>& _v )
{
    _v.visit( *this );
}
