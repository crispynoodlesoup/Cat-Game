#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "Background.h"
#include "cloud.h"
#include "Ground.h"
#include "Boundaries.h"
#include "Turtle.h"
#include "Soup.h"
#include "Crate.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        void run();
        void setup();
        void update();

    private:
        sf::Clock clock;
        float deltaTime;
        sf::Event event;
        sf::RenderWindow *window;
        sf::Texture doggoTexture;
        Player *player;
        sf::Texture wallPaper;
        Background *background;
        sf::Texture groundTexture;
        Ground *ground;
        sf::Texture boundaryTexture;
        Boundaries *boundary1;
        Boundaries *boundary2;
        Turtle *turtle;
        bool turtleSide;
        Soup *soup;
        sf::Texture crateTexture;
        Crate *bigCrate;
        Crate *smollCrate;
        std::vector<Cloud> clouds;
        sf::Vector2f direction;
};

#endif // GAME_H
