#include <file.h>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

getit::File::File ( std::string const& _p ):
    path_ ( _p ),
    last_read_time_( 0 )

{
}

getit::FileState getit::File::is_modified() const
{
    boost::system::error_code ec;
    std::time_t lwr = boost::filesystem::last_write_time( path_, ec );
    if ( ec )
	return last_read_time_ < lwr ?  FileState::modified : FileState::not_modified;
    else
	throw std::logic_error ( ec.message() );
    
}

getit::file_lines_t getit::File::getlines() const
{
    file_lines_t ret;
    std::ifstream s ( path_ );
    if(  s.is_open() )
    {
	std::string line;
	while( s.good() and std::getline( s, line ) )
	{
	    std::cout << "Read_line from: " << path_ << ": " << line << std::endl;	    
	    ret.push_back( line );
	} 
    }
    last_read_time_ = std::chrono::system_clock::to_time_t ( std::chrono::system_clock::now() );
    std::cout << "last_read  "  << last_read_time_ << std::endl;
    return ret;
    
}

void getit::File::putlines( file_lines_t const& _l ) const
{
    std::ofstream s ( path_, std::ios::trunc );
    if(  s.is_open() )
    {
	for ( auto a : _l )
	    s << a;
    }
}

getit::file_list_t getit::Directory::getfiles( std::string const& path, std::string const& mask) const
{
    getit::file_list_t ret;
    boost::regex const filter( mask );
    boost::filesystem::directory_iterator end_itr; 

    for( boost::filesystem::directory_iterator i( path ); i != end_itr; ++i )
    {
	if( !boost::filesystem::is_regular_file( i->status() ) ) continue;

	boost::smatch what;

	if( !boost::regex_match( i->path().filename().string(), what, filter ) ) continue;

	ret.push_back( std::make_shared<File>( i->path().filename().string() ) );
    }
    return ret;
}

