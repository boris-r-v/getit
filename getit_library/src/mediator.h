#ifndef GETIT_MEDIATOR_H
#define GETIT_MEDIATOR_H

#include <iface.h>


namespace getit
{
    /**
	@brief Реализация паттерна Mediator, создает все составные части системы и обеспечивает их взаимосвязь
    */
    class Mediator
    {
	    directory_iface_ptr dir_;
	    file_list_t input_files_;
	    database_iface_ptr data_base_;
	    manager_pool_iface_ptr manager_pool_;

	public:
	    Mediator( getit::ConfigIface const& vm );

	    void do_it();



    };
}
#endif // GETIT_MEDIATOR_H
