#pragma once
#include<iostream>

class Crime
{
	std::string plase; // место происшествия
	std::string crime; // Нарушение
public:
	const std::string& get_place() const;
	const std::string& get_crime() const;
	Crime(std::string plase, std::string crime);
	~Crime();
};

