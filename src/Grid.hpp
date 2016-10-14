//
//  Grid.hpp
//  langston-had-an-ant
//
//  Created by Leo Dastur on 10/13/16.
//
//

#pragma once

#include <vector>
#include "cell.hpp"

class Grid {
	std::vector<Cell> cells;
	
	std::vector<std::vector<Cell>::iterator> ants;
	
	
	
	
public:
	void update();
	void draw();
};
