#include <manager.h>
#include <file.h>
#include <visitors.h>
getit::Manager::Manager( std::string const& _p, std::string const& _m, std::string const& _fn ) : 
    producer_( _p ),
    merch_( _m ),
    file_name_ ( _fn )
{
    if ( !producer_.empty() )
    	visitors_.emplace_back ( std::make_shared<OrderForProducer> ( producer_, [this](file_lines_t _t){ store( std::move(_t )); } ) );
    if ( !merch_.empty() )
    	visitors_.emplace_back ( std::make_shared<OrderForName> ( merch_, [this](file_lines_t _t){ store( std::move(_t )); } ) );
}

std::string const& getit::Manager::producer() const
{
    return producer_;
}
std::string const& getit::Manager::merch() const
{
    return merch_;
}
std::string const& getit::Manager::file_name() const
{
    return file_name_;
}

void getit::Manager::work( DatabaseIface& _db )
{
    for ( auto a : visitors_ )
	_db.accept( *a );
}

void getit::Manager::store( file_lines_t _t )
{
    File f( file_name_ );
    f.putlines( _t );
}


getit::ManagerPool::ManagerPool ( getit::ConfigIface const& vm ):
    managers_ ( std::move(vm.managers() ) )
{
}

void getit::ManagerPool::work( DatabaseIface& _db )
{
    for ( auto a : managers_ )
	a->work (_db );
}

