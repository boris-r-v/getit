/** \file iface.h
    @brief Набор интерфейсов для реализации слабой связности между классами (SOLID)

    @authors Boris Rozhkin borisrozhkin@gmail.com
*/

#ifndef GETIT_IFACE_H
#define GETIT_IFACE_H

#include <iface.h>

#include <string>
#include <list>
#include <memory>
#include <functional>

namespace getit
{
    typedef std::string merch_name_t;
    typedef std::string merch_producer_t;
    typedef double merch_price_t;
    typedef double merch_weight_t;
    /**
	@brief Интерфейс описания товара

	Содержит методы доступа к 4-м атрибутам товара: цена, масса, имя, производитель
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
	@brief Базовый класс для добавления коллбэка, с обощенным типом
    */
    template< typename T >
    class Callback
    {
	protected:
	    std::function< void ( T ) > call_;
	public:
	    Callback ( std::function< void ( T ) > &f ): call_(std::move(f) )
	    {
	    }
    };
    /**
	@brief Шаблонный интерфейс для реализации паттерна Visitor
    */
    template <typename T>
    class VisitorIface
    {
	public:
	    virtual void visit( T& ) = 0; 	        
    };
    /**
	@brief Интерфейс базы данных 

	Содержит методы доступа к данным (get, set) и метод применения Visitor
    */
    class DatabaseIface
    {
	public:
	    virtual void put( merch_iface_ptr ) = 0;
	    virtual merch_list_t const& get( ) const = 0;
	    virtual void accept( VisitorIface<DatabaseIface>& ) = 0;
    };
    typedef std::shared_ptr<DatabaseIface> database_iface_ptr;
    typedef std::shared_ptr <VisitorIface<DatabaseIface> > visitor_iface_ptr;
    typedef std::list <visitor_iface_ptr> visitor_list_t;
    /**
	@brief Статусы состояния файла 
    */
    enum class FileState 
    {
	modified, 	/**< файл был модифицирован */
	not_modified	/**< файл не был модифицирован	*/
    };
    /**
	@brief Тип данных: список строк
    */
    typedef std::list<std::string> file_lines_t;
    /**
	@brief Интерфейс файла.

	Позволяет получить/записать список строк из/в файла и проверить, что за последнее время он изменился
    */
    class FileIface
    {
	public:
	    virtual FileState is_modified() const = 0;
	    virtual file_lines_t getlines() const = 0;
	    virtual void putlines( file_lines_t const &) const = 0;
	    virtual std::string path() const = 0;
	
    };
    typedef std::shared_ptr< FileIface > file_iface_ptr;
    typedef std::list<file_iface_ptr> file_list_t;

    /**
	@brief Интерфейс директории.

	Содержит метод получения списка  файлов
    */
    class DirectoryIface
    {
	public:
	    virtual file_list_t getfiles( std::string const& path, std::string const& mask ) const = 0;
    };
    typedef std::shared_ptr< DirectoryIface > directory_iface_ptr;

    /**
	@brief Интерфейс менеджера.

	Содержит методы доступа к задачам конктретного менеджера: наименование товара и его производителя согласно задачи менеджера
    */
    class ManagerIface
    {
	public:
	    virtual std::string const& producer() const = 0;
	    virtual std::string const& merch() const = 0;
	    virtual std::string const& file_name() const = 0;
	    virtual void work( DatabaseIface& ) = 0;
    };
    typedef std::shared_ptr<ManagerIface> manager_iface_ptr;
    typedef std::list<manager_iface_ptr> managers_list_t;

    /**
	@brief Интерфейс места работы менеджеров, содержит их список и заставляет работать.
    */
    class ManagerPoolIface
    {
	public:
	    virtual void work( DatabaseIface&  ) = 0;
    };
    typedef std::shared_ptr<ManagerPoolIface> manager_pool_iface_ptr;

    /**
	@brief Интерфейс конфигуратора, обеспечивает доступ к данным в конфигурационном файле
    */
    class ConfigIface
    {    
	public:
	    virtual std::string const& customers_path() const = 0;
	    virtual std::string const& managers_path() const = 0;
	    virtual managers_list_t managers() const = 0;
    };



}	
#endif // GETIT_IFACE_H
