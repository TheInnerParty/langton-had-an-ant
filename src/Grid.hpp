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


class Grid {
	
	enum Direction {LEFT, UP, RIGHT, DOWN};
	
	std::vector<Cell> cells;
	
	typedef std::tuple<Direction, std::vector<Cell>::iterator> Ant;
	
	
	void goUp(Ant& ant);
	void goDown(Ant& ant);
	void goLeft(Ant& ant);
	void goRight(Ant& ant);
    
    Direction turnRight(Direction d);
    Direction turnLeft(Direction d);
	
	OutofBounds outofBounds;
	
	
	
public:
	Grid(int width = 50, int height = 50);
	void update();
	bool getBoxColored(int x, int y);
	std::vector<Ant> ants;
	int width; // Number of Cells
	int height;
    std::tuple<int,int> getAntLocation(Ant a);
    void addAnt(int x, int y);
};
