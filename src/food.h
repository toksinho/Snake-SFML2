#ifndef FOOD_H
#define FOOD_H
#include <SFML/Graphics.hpp>

class Food
{
public:
    Food();
    float getX();
    float getY();
    void insertFood(sf::RenderWindow& App,float,float,int);
};
#endif // FOOD_H
