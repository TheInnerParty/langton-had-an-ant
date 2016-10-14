//
//  Grid.cpp
//  langston-had-an-ant
//
//  Created by Leo Dastur on 10/13/16.
//
//

#include "Grid.hpp"

Grid::Grid() {
	cells.assign(width*height, Cell());
	Ant ant;
	
}
Grid::update(){
    for(auto&& a : ants){
        if (get<1>(a)->color){
            //left
            get<0>(a) = turnLeft(get<0>(a));
        } else {
            //right
            get<0>(a) = turnRight(get<0>(a));
        }
        //flip color of square
        get<1>->color = ! get<1>->color;
        //move in that direction
        switch(get<0>(a){
            case LEFT;
                get<1>(a) = get<1>(goLeft(a));
                break;
            case UP;
                get<1>(a) = get<1>(goUp(a));
                break;
            case RIGHT;
                get<1>(a) = get<1>(goRight(a));
                break;
            case DOWN;
                get<1>(a) = get<1>(goDown(a));
                break;
        }
        
    }
}

Grid::turnRight(Direction d){
    return (d != DOWN)? d++ : LEFT;
}
GRID::turnLeft(Direction d){
    return (d != LEFT)? d-- : DOWN;
}
