#include "Game.h"

Game::Game() {
    this->window = window;
    this->deltaTime = deltaTime;
    this->event = event;
    this->clock = clock;
    this->doggoTexture = doggoTexture;
    this->wallPaper = wallPaper;
    this->background = background;
    this->player = player;
    this->direction = direction;
    this->ground = ground;
    this->groundTexture = groundTexture;
    this->boundaryTexture = boundaryTexture;
    this->clouds = clouds;
    this->boundary1 = boundary1;
    this->boundary2 = boundary2;
    this->turtle = turtle;
    this->turtleSide = turtleSide;
    this->soup = soup;
    this->crateTexture = crateTexture;
    this->bigCrate = bigCrate;
    this->smollCrate = smollCrate;
    this->setup();
}

Game::~Game() {
    //dtor
}

void Game::run() {
    window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Nice Things", sf::Style::Close);

    while(window->isOpen()) {
        this->update();
    }
}

void Game::setup() {
    deltaTime = 0.0f;
    doggoTexture.loadFromFile("Doggo.png");
    wallPaper.loadFromFile("WallPaper.png");
    groundTexture.loadFromFile("groundTexture.png");
    boundaryTexture.loadFromFile("walls.png");
    crateTexture.loadFromFile("crate.png");

    player = new Player(&doggoTexture, sf::Vector2u(4, 4), 0.1f, 1.0f);
    background = new Background(&wallPaper, 4.0f, sf::IntRect(0, 0, 1080, 720));
    ground = new Ground(&groundTexture);
    boundary1 = new Boundaries(&boundaryTexture, sf::Vector2f(-120.0f, 360.0f));
    boundary2 = new Boundaries(&boundaryTexture, sf::Vector2f(1200.0f, 360.0f));
    turtle = new Turtle(&doggoTexture, sf::Vector2f(200.0f, 500.0f), sf::Vector2u(4, 4), 0.5f);
    soup = new Soup(&doggoTexture, sf::Vector2f(540.0f, 240.0f), sf::Vector2u(4, 4), 0.2f);
    bigCrate = new Crate(&crateTexture, sf::Vector2f(200.0f, 200.0f), 5.0f);
    smollCrate = new Crate(&crateTexture, sf::Vector2f(880.0f, 200.0f), 2.0f);
    clouds.push_back(Cloud(&doggoTexture, sf::Vector2f(200.0f, 540.0f)));
    clouds.push_back(Cloud(&doggoTexture, sf::Vector2f(880.0f, 540.0f)));
    clouds.push_back(Cloud(&doggoTexture, sf::Vector2f(540.0f, 420.0f)));
    clouds.push_back(Cloud(&doggoTexture, sf::Vector2f(200.0f, 300.0f)));
    clouds.push_back(Cloud(&doggoTexture, sf::Vector2f(880.0f, 300.0f)));
}

void Game::update() {
    deltaTime = clock.restart().asSeconds();
    if(deltaTime > 1.0f/30.0f)
        deltaTime = 1.0f/30.0f;

    while(window->pollEvent(event)) {
        switch(event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        }
    }
    player->Update(deltaTime);
    turtle->Update(deltaTime);
    soup->Update(deltaTime);
    bigCrate->Update(deltaTime);
    smollCrate->Update(deltaTime);

    for(Cloud& cloud : clouds) {
        if(cloud.GetBody().CheckCollided(player->GetBody(), direction, 1.0f))
            player->IsColliding(direction, "cloud");
        if(cloud.GetBody().CheckCollided(bigCrate->GetBody(), direction, 1.0f))
            bigCrate->IsColliding(direction);
        if(cloud.GetBody().CheckCollided(smollCrate->GetBody(), direction, 1.0f))
            smollCrate->IsColliding(direction);
    }
    if(ground->GetBody().CheckCollided(player->GetBody(), direction, 1.0f))
        player->IsColliding(direction, "ground");
    if(ground->GetBody().CheckCollided(bigCrate->GetBody(), direction, 1.0f))
        bigCrate->IsColliding(direction);
    if(ground->GetBody().CheckCollided(smollCrate->GetBody(), direction, 1.0f))
        smollCrate->IsColliding(direction);
    if(boundary1->GetBody().CheckCollided(player->GetBody(), direction, 1.0f))
        player->IsColliding(direction, "boundary");
    if(boundary2->GetBody().CheckCollided(player->GetBody(), direction, 1.0f))
        player->IsColliding(direction, "boundary");
    if(boundary1->GetBody().CheckCollided(bigCrate->GetBody(), direction, 1.0f))
        bigCrate->IsColliding(direction);
    if(boundary2->GetBody().CheckCollided(bigCrate->GetBody(), direction, 1.0f))
        bigCrate->IsColliding(direction);
    if(boundary1->GetBody().CheckCollided(smollCrate->GetBody(), direction, 1.0f))
        smollCrate->IsColliding(direction);
    if(boundary2->GetBody().CheckCollided(smollCrate->GetBody(), direction, 1.0f))
        smollCrate->IsColliding(direction);
    if(bigCrate->GetBody().CheckCollided(player->GetBody(), direction, 0.7f))
        player->IsColliding(direction, "crate");
    if(smollCrate->GetBody().CheckCollided(player->GetBody(), direction, 0.3f))
        player->IsColliding(direction, "crate");
    if(soup->GetBody().CheckCollided(player->GetBody(), direction, 1.0f)) {
        player->SetRandColor();
        player->IsColliding(direction, "soup");
        printf("Soup!\n");
    }
    if(turtle->GetBody().CheckCollided(player->GetBody(), direction, 1.0f)) {
        if(turtleSide) {
            turtle->SetPosition(sf::Vector2f(200.0f, 500.0f));
            turtleSide = false;
        } else {
            turtle->SetPosition(sf::Vector2f(880.0f, 500.0f));
            turtleSide = true;
        }
        printf("Turtle!\n");
    }

    window->clear();
    background->Draw(window);
    ground->Draw(window);
    soup->Draw(window);
    bigCrate->Draw(window);
    smollCrate->Draw(window);
    player->Draw(window);
    for(Cloud& cloud : clouds)
        cloud.Draw(window);
    boundary1->Draw(window);
    boundary2->Draw(window);
    turtle->Draw(window);

    window->display();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        this->setup();
}
