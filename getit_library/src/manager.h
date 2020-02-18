/** \file manager.h
    @brief Файл содержит реализацию интерфейсов Менеджера и БассейнаМенеджеров 

    @authors Boris Rozhkin borisrozhkin@gmail.com

*/

#ifndef GETIT_MANAGER_H
#define GETIT_MANAGER_H

#include <iface.h>		

namespace getit
{
    /**
	@brief Реализация интерфейса менеджер

	Хранит список посетителей которые должны выполнить задачу
    */
    class Manager final : public ManagerIface
    {
	    std::string producer_, merch_, file_name_;
	    visitor_list_t visitors_;
	    void store( file_lines_t );
	public:
	    Manager( std::string const& _p, std::string const& _m, std::string const& _fn );
	    std::string const& producer() const override;
	    std::string const& merch() const override;
	    std::string const& file_name() const override;
	    void work( DatabaseIface& ) override;
    };
    /**
	@brief Реализация интерфейса менеджеров
    */
    class ManagerPool final : public ManagerPoolIface
    {
	    managers_list_t managers_;
	public:
	    ManagerPool ( getit::ConfigIface const& vm );
	    void work( DatabaseIface& ) override;
    };

}

#endif // GETIT_MANAGER_H