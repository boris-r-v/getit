#ifndef GETIT_VISITORS_H
#define GETIT_VISITORS_H

#include <iface.h>

namespace getit
{

    /**
	@brief Алгоритм сбора заказов к конкретному производителю
    */
    class OrderForProducer final: public VisitorIface<DatabaseIface>, public Callback<file_lines_t>
    {
	    merch_producer_t const producer_;
	    file_lines_t handle_result( merch_list_t );
	public:
	    OrderForProducer( merch_producer_t const&, std::function< void ( file_lines_t ) > f );
	    virtual void visit( DatabaseIface& ) override; 	        
    };

    /**
	@brief Алгоритм сбора заказов по типу товара
    */
    class OrderForName final: public VisitorIface<DatabaseIface>, public Callback<file_lines_t>
    {
	    merch_name_t const name_;
	    file_lines_t handle_result( merch_list_t );
	public:
	    OrderForName( merch_name_t const&, std::function< void ( file_lines_t ) > f );
	    virtual void visit( DatabaseIface& ) override; 	        
    };


    /**
	@brief Алгоритм добавления/изменения записей в базе данных
	
	Не реализован
    */
    class DataBaseUpdate final: public VisitorIface<DatabaseIface>
    {
	public:
	    virtual void visit( DatabaseIface& ) override; 	        
    };



}
#endif // GETIT_VISITORS_H