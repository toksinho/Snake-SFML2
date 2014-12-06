#ifndef ENDSCREEN_H
#define ENDSCREEN_H
#include <SFML/Graphics.hpp>
#include "screen.h"
class EndScreen : public Screen
{
public:
    EndScreen();
    virtual int Run(sf::RenderWindow &App);
private:
    sf::Text text;
    sf::Text textPoints;
    sf::Font font;

};
#endif // ENDSCREEN_H
