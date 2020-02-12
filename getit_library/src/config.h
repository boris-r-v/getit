#ifndef GETIT_CONFIG_H
#define GETIT_CONFIG_H
/**
    @brief Class Config - обрабатывает конфигурацию задачи
	
*/
#include <list>		
#include <libxml++/libxml++.h>

namespace getit
{
    class Manager
    {
	    std::string producer_, merch_, file_name_;
	public:
	    Manager( std::string const& _p, std::string const& _m, std::string const& _fn );
	    std::string const& producer() const;
	    std::string const& merch() const;
	    std::string const& file_name() const;
    };
    typedef std::list<Manager> managers_t;

    class Config
    {
	    void extract_customers_path( xmlpp::DomParser const& );
	    void extract_managers_path( xmlpp::DomParser const& );
	    void extract_managers( xmlpp::DomParser const& );		
    
	    std::string customers_path_;
	    std::string managers_path_;
	    managers_t managers_;
	public:
	    Config () = delete;
	    virtual ~Config () = default;
	    Config ( std::string const& path_to_config );
    
	    std::string const& customers_path() const;
	    std::string const& managers_path() const;
	    managers_t const& managers() const;
	    
    };
}
#endif // GETIT_CONFIG_H
