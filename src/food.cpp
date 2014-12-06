#include "food.h"

Food::Food()
{

}

void Food::insertFood(sf::RenderWindow& App,float x,float y,int r)
{
    sf::RectangleShape food;
	food.setSize(sf::Vector2f(20, 20));

	if(r==0)
    {
        food.setFillColor(sf::Color::Blue);
    }
    if(r==1)
    {
        food.setFillColor(sf::Color::Red);
    }
    if(r==2)
    {
        food.setFillColor(sf::Color::Yellow);
    }
    if(r==3)
    {
        food.setFillColor(sf::Color::Cyan);
    }
    if(r==4)
    {
        food.setFillColor(sf::Color::White);
    }
	food.move(x, y);

	App.draw(food);
}
