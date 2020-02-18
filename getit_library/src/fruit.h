#ifndef GETIT_MERCH_H
#define GETIT_MERCH_H

#include <iface.h>

namespace getit
{
    /**
	@brief Имплементация интерфейса Товар в виде Фрукта
    */
    class Fruit final: public MerchIface
    {
	    merch_price_t price_;
	    merch_weight_t weight_;
	    merch_name_t name_;
	    merch_producer_t producer_;
	public:
	    Fruit () = delete;
	    Fruit ( std::string const& file_line );
	    	

	    merch_price_t price() const override;
	    merch_weight_t weight() const override;
	    merch_name_t const& name() const override;
	    merch_producer_t const& producer() const override;
    };

}
#endif // GETIT_MERCH_H
