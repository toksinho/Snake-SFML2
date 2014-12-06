#include "endscreen.h"
#include <iostream>
#include <string>
#include <sstream>
#include "game.h"
EndScreen::EndScreen()
{

}

int EndScreen::Run(sf::RenderWindow &App)
{

       //std::cout<<Game::getPoints();
    sf::Event Event;
    bool Running = true;

    font.loadFromFile("arial.ttf");
    text.setFont(font);
    textPoints.setFont(font);


    text.setString("You lose! Points: \nPress Space for back to menu");
    text.setCharacterSize(40);
    text.setPosition(50,160);

    textPoints.setCharacterSize(40);
    textPoints.setColor(sf::Color::Red);
    textPoints.setPosition(360,160);

    while (Running)
    {

        //Verifying events
        while (App.pollEvent(Event))
        {

            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Space:
                    return(0);
                    break;
                case sf::Keyboard::Escape:
                    return(-1);
                    break;
                default:
                    break;
                }
            }
        }

    std::string result;
    std::stringstream convert;
    convert<<Game::getPoints();
    result=convert.str();
    textPoints.setString(result);

        App.clear();
        App.draw(text);
        App.draw(textPoints);
        App.display();
    }
}
