#include <provider.h>
#include <file.h>

static unsigned CHECK_PERIOD (3);

getit::Provider::Provider( getit::Config const& vm, boost::asio::io_service& io ):
    timer_ ( io ),
    med_ ( vm )
{
//    std::cout << "getif::Provider ctor: " << vm["indir"].as<std::string>() << " " << vm["outdir"].as<std::string>() << " " << vm["config"].as<std::string>() << std::endl;
    //Создать и настроить модули:
//	1. проходить по customers -- пистаь в базу данных новые заказы
//		Если есть новые заказы уведомляем об этом менеджеров Observer
//	2. проходить по менеджерам и если есть новые заказы - обновлять данные в их фалах

}

void getit::Provider::run( )
{
    do_wait();
}

void getit::Provider::do_wait()
{

    std::cout << " getit::harrier::do_wait "  << std::endl;

    med_.do_it();

    timer_.expires_from_now( boost::posix_time::seconds( CHECK_PERIOD ) );
    timer_.async_wait ( [this](boost::system::error_code ec)
    {
	
	do_wait();	    

    });

}