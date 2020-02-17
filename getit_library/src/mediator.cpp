#include <mediator.h>
#include <file.h>
#include <database.h>
#include <fruit.h>
#include <manager.h>
#include <iostream>

getit::Mediator::Mediator( getit::ConfigIface const& vm  ) :
    dir_( std::make_shared<Directory>() ),
    input_files_( std::move ( dir_->getfiles( vm.customers_path(), "^.*\\.(csv|txt|cvs)$" ) ) ),
    data_base_ ( std::make_shared<Database>() ),
    manager_pool_( std::make_shared<ManagerPool>( vm ) )
{
}

void getit::Mediator::do_it()
{
    for ( auto file : input_files_ )
    {
	if ( FileState::modified == file->is_modified() )
	{

	    for ( auto fline : file->getlines() )
	    {
		data_base_->put( std::make_shared<Fruit>(fline) );
	    }

	    manager_pool_->work( *data_base_ );	    
	}
    }
}
