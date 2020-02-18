#include <visitors.h>
#include <algorithm>

getit::OrderForProducer::OrderForProducer( merch_producer_t const& _m, std::function< void ( file_lines_t ) > _f):
	Callback( _f ),
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
    call_( handle_result( _out ) );
}
getit::file_lines_t getit::OrderForProducer::handle_result( merch_list_t _l )
{
    getit::file_lines_t ret;
    ret.emplace_back ( "producer,price,weight" );
    for ( auto ptr : _l )
	ret.emplace_back ( ptr->name()+','+std::to_string(ptr->price())+','+std::to_string(ptr->weight()) );
    return ret;
}


getit::OrderForName::OrderForName( merch_name_t const& _m, std::function< void ( file_lines_t ) > _f ):
	Callback( _f ),
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
    call_( handle_result( _out ) );
}
getit::file_lines_t getit::OrderForName::handle_result( merch_list_t _l )
{
    getit::file_lines_t ret;
    ret.emplace_back ( "name,price,weight" );
    for ( auto ptr : _l )
	ret.emplace_back ( ptr->producer()+','+std::to_string(ptr->price())+','+std::to_string(ptr->weight()) );
    return ret;
}
