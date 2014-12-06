#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "snake.h"

class Game : public Screen
{
public:
    Game();
    virtual int Run(sf::RenderWindow &App);
    static int getPoints() {return points;} //Static because endscreen(other class) need access to points to show end message
    static int points;
    static void setZero(){points = 0;} //Always set zero points when game begins
private:
    bool isPlay;
    bool safe; //put food or not
    bool pause;
    std::list<Square> block;
    float foodX;
    float foodY;

    int increase; //when food is eaten increase for this number
    sf::Text text;
    sf::Font font;
    void screenMessages(sf::RenderWindow&,int&); //points and lower part of the screen


};
#endif // GAME_H
