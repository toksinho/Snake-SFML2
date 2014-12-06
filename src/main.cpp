
#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.h"
#include "game.h"
int main(int argc, char** argv)
{

    std::vector<Screen*> Screens;
    int screen = 0;

    //Window creation
    sf::RenderWindow App(sf::VideoMode(725, 475), "Snake");
    App.setVerticalSyncEnabled(true);


    //Screens preparations
    Menu s0;
    Game s1;
    EndScreen s2;

    Screens.push_back(&s0);
    Screens.push_back(&s1);
    Screens.push_back(&s2);

    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}
