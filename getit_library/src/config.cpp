#include <config.h>
#include <iostream>

getit::Manager::Manager( std::string const& _p, std::string const& _m ) : 
    producer_( _p ),
    merch_( _m )
{
}

std::string const& getit::Manager::producer()
{
    return producer_;
}
std::string const& getit::Manager::merch()
{
    return merch_;
}


getit::Config::Config( std::string const& path_to_config  ) 
{
    xmlpp::DomParser vm( path_to_config );
    if ( vm )
    {
	extract_customers_path( vm );
	extract_managers_path( vm );
	extract_managers( vm );
    }
}

void getit::Config::extract_customers_path( xmlpp::DomParser const& vm  )
{
    const xmlpp::Node* root = vm.get_document()->get_root_node();
    auto node = root->find("/descendant::path").front();
    customers_path_ = static_cast<xmlpp::Element*>(node)->get_attribute_value("customers");
    
}

void getit::Config::extract_managers_path( xmlpp::DomParser const& vm  )
{
    const xmlpp::Node* root = vm.get_document()->get_root_node();
    auto node = root->find("/descendant::path").front();
    customers_path_ = static_cast<xmlpp::Element*>(node)->get_attribute_value("managers");
}

void getit::Config::extract_managers( xmlpp::DomParser const& vm  )
{
    const xmlpp::Node* root = vm.get_document()->get_root_node();
    auto nodes = root->find("/descendant::manager");
    for ( auto m : nodes )
    {
	managers_.emplace_back( 
	    Manager	
	    (
		static_cast<xmlpp::Element*>(m)->get_attribute_value("producer"),
		static_cast<xmlpp::Element*>(m)->get_attribute_value("merch")
	    )
	);
    }
}

std::string const& getit::Config::customers_path() const
{
    return customers_path_;
}
std::string const& getit::Config::managers_path() const
{
    return managers_path_;
}
getit::managers_t const& getit::Config::managers() const
{
    return managers_;
}