//
//  OutofBoundsException.hpp
//  langston-had-an-ant
//
//  Created by Leo Dastur on 10/13/16.
//
//

#pragma once

#include <exception>


class OutofBounds: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Reached Edge of Cell";
	}
} ;

