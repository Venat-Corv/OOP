#include "Crime.h"



const std::string & Crime::get_place() const
{
	return this->plase;
	// TODO: insert return statement here
}

const std::string & Crime::get_crime() const
{
	return this->crime;
	// TODO: insert return statement here
}

Crime::Crime(std::string plase, std::string crime)
{
	this->plase = plase;
	this->crime = crime;
}

Crime::~Crime()
{

}
