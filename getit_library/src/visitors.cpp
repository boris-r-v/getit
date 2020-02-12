#include <visitors.h>
#include <algorithm>

getit::OrderForProducer::OrderForProducer( merch_producer_t const& _m ):
	producer_( _m )
{
}
void getit::OrderForProducer::visit( DatabaseIface&  _d )
{
    merch_list_t const& t = _d.get();
    merch_list_t _out;
    std::copy_if ( t.begin(), t.end(), std::back_inserter( _out ), 
	[&]( merch_iface_ptr _f )->bool
	{
	    return ( producer_ == _f->producer() ? true : false );
	}
    );
    //FIX ME - needed accumulate and save data

}


getit::OrderForName::OrderForName( merch_name_t const& _m ):
	name_( _m )
{
}
void getit::OrderForName::visit( DatabaseIface&  _d )
{
    merch_list_t const& t = _d.get();
    merch_list_t _out;
    std::copy_if ( t.begin(), t.end(), std::back_inserter( _out ), 
	[&]( merch_iface_ptr _f )->bool
	{
	    return ( name_ == _f->name() ? true : false );
	}
    );
    //FIX ME - needed accumulate and save data
}
