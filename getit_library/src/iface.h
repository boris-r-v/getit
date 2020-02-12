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

    /**
	@brief Income File state
    */
    enum class FileState {modified, not_modified};
    /**
	@brief Sting with file line
    */
    typedef std::list<std::string> file_lines_t;
    /**
	@brief Common File interface
    */
    class FileIface
    {
	public:
	    virtual FileState is_modified() const = 0;
	    virtual file_lines_t getlines() const = 0;
	    virtual void putlines( file_lines_t const &) const = 0;
	
    };
    typedef std::shared_ptr< FileIface > file_iface_ptr;
    typedef std::list<file_iface_ptr> file_list_t;

    /**
	@brief Directory interface
    */
    class DirectoryIface
    {
	public:
	    virtual file_list_t getfiles( std::string const& path, std::string const& mask ) const = 0;
    };

    /**
	@brief LogicIface Mediator pattern with curretn handle data logic
    */



}
#endif // GETIT_IFACE_H
