#include <fruit.h>
#include <sstream>

getit::Fruit::Fruit (std::string const& file_line )
{
    std::string price_s, weight_s;
    std::istringstream ss ( file_line );
    std::getline( ss, name_, ',' );
    std::getline( ss, price_s, ',' );
    std::getline( ss, producer_, ',' );
    std::getline( ss, weight_s, ',' );
    price_ = atof ( price_s.c_str() );  //FIX ME need to use std::stof - but it may whrow exceptions,  this no exception, but may be incorrect
    weight_ = atof( weight_s.c_str() ); //FIX ME need to use std::stof - but it may whrow exceptions,  this no exception, but may be incorrect
}

getit::merch_price_t getit::Fruit::price() const
{
    return price_;
}
getit::merch_weight_t getit::Fruit::weight() const
{
    return weight_;
}
getit::merch_name_t const& getit::Fruit::name() const
{
    return name_;
}
getit::merch_producer_t const& getit::Fruit::producer() const
{
    return producer_;
}
