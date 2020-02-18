/** \file config.h
    @brief Файл содержит имплементацию интерфейса чтения конфигурации
*/

#ifndef GETIT_CONFIG_H
#define GETIT_CONFIG_H
#include <iface.h>		
#include <libxml++/libxml++.h>

namespace getit
{
    /**
	@brief Config - обрабатывает конфигурацию задачи

	Парсит конфигурауционный файл с описанием решаемой задачи    
	
	Обеспечивает интерфейс доступа конфигурации каталогов с файлами и перечню менеджеров
    */
    class Config final : public ConfigIface 
    {
	    void extract_customers_path( xmlpp::DomParser const& );
	    void extract_managers_path( xmlpp::DomParser const& );
	    void extract_managers( xmlpp::DomParser const& );		
    
	    std::string customers_path_;
	    std::string managers_path_;
	    managers_list_t managers_;
	public:
	    Config () = delete;
	    virtual ~Config () = default;
	    Config ( std::string const& path_to_config );
    
	    std::string const& customers_path() const override;
	    std::string const& managers_path() const override;
	    managers_list_t managers() const override;
	    
    };
}
#endif // GETIT_CONFIG_H
