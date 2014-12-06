#include "game.h"
#include "snake.h"
#include "food.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
//IDEJA: FRIEND FUNKCIJA ZA NOVI SCREEN ZBOG BODOVA FRIEND GETPOINTS();
Game::Game()
{
    isPlay=true;

    font.loadFromFile("arial.ttf");
    text.setFont(font);
}



int Game::Run(sf::RenderWindow &App)
{

    srand(time(NULL));
    Snake snake;
    Food food;
    pause=false;
    snake.reset();
    setZero();
    increase = 10;
    foodX=300.f;
    foodY=300.f;
    int color = 1;

    sf::Event event;
    App.setFramerateLimit(12);
     while (App.isOpen())
    {
                App.clear();

        //Verifying events
        while (App.pollEvent(event))
        {

            // Window closed
           if (event.type == sf::Event::Closed)
            {
                return (-1);
            }

            //Key pressed
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    return(0);
                    break;
                case sf::Keyboard::Num1:
                    App.setFramerateLimit(10);
                    break;
                case sf::Keyboard::Num2:
                    App.setFramerateLimit(12);
                    break;
                 case sf::Keyboard::Num3:
                    App.setFramerateLimit(16);
                    break;
                 case sf::Keyboard::P:
                    if(pause==false)
                        pause=true;
                    else
                        pause=false;
                    break;

                default:
                    break;
                }
            }
        }
    if(pause==false)
        snake.moveSnake(App);

    food.insertFood(App,foodX,foodY,color);
    snake.drawSnake(App);

    if(snake.getX()==foodX && snake.getY()==foodY)
    {
        snake.bigger();
        points = points + increase;

    //srand(time(NULL));
    color = rand()%5;

    block = snake.getSnake();
    do{

        foodX=(rand()%29)*25;
        foodY=(rand()%16)*25;

        for(std::list<Square>::iterator it = block.begin(); it != block.end(); it++)
        {
            if(it->getX()==foodX && it->getY()==foodY)
                {
                    safe=false;
                    break;
                }

            else
                {
                safe=true;
                }
        }

    } while(safe!=true);

    }


if(snake.getX()>=725 || snake.getX()<0 || snake.getY()>=400 || snake.getY()<0)
{

    return(2);


}
//check if snake hits itself
		block = snake.getSnake();
		std::list<Square>::iterator it = block.begin();

		it++; // Since we know the last inserted block is the same position as the snake's head, we skip it

		for(it; it != block.end(); it++)
		{
			if(it->getX() == snake.getX() && it->getY() == snake.getY())
			{


                return(-1);

			}

		}
		    screenMessages(App,points);
        App.display();

}
}
void Game::screenMessages(sf::RenderWindow&App,int& points)
{
    sf::RectangleShape line(sf::Vector2f(725,3));
    line.setFillColor(sf::Color::White);
    line.setPosition(0,400);
    App.draw(line);

    std::string result;
    std::stringstream convert;
    convert<<points;
    result=convert.str();
    std::string message("Points:  ");
    std::string sum=message + result;
    text.setString(sum);
    text.setColor(sf::Color::Red);
    text.setCharacterSize(24);
    text.setPosition(530,410);
    App.draw(text);

    text.setString("Speed: ");
    text.setCharacterSize(24);
    text.setPosition(20,405);
    App.draw(text);

    text.setString("1-Easy\n2-Medium\n3-Fast");
    text.setCharacterSize(18);
    text.setPosition(110,405);
    App.draw(text);
}
int Game::points = 0;
