//
//  Grid.hpp
//  langston-had-an-ant
//
//  Created by Leo Dastur on 10/13/16.
//
//

#pragma once

#include <vector>
#include <tuple>
#include "cell.hpp"
#include "OutofBoundsException.hpp"
enum Direction {LEFT, RIGHT, UP, DOWN};

class Grid {
	std::vector<Cell> cells;
	
	typedef std::tuple<Direction, std::vector<Cell>::iterator> Ant;
	
	std::vector<Ant> ants;
	
	
	int width; // Number of Cells
	int height;
	
	Ant goUp(Ant ant);
	Ant goDown(Ant ant);
	Ant goLeft(Ant ant);
	Ant goRight(Ant ant);
	
	OutofBounds outofBounds;
	
	
	
public:
	Grid(int width = 50, int height = 50);
	void update();
	void draw();
};
