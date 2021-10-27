#include"Allheader.h"
#include "Player.h"
#include "Bullet.h"
#include "Enamy.h"

int main()
{
    RenderWindow window(VideoMode(1920.0f, 1080.0f), "Game", Style::Titlebar | Style::Close);
    window.setVerticalSyncEnabled(true);
    srand(time(NULL));

    //Player
    Texture playerTexture;
    if (!playerTexture.loadFromFile("mainPlane.png"))
    {
        cout << "LoadPlayer failed" << endl;
    }
    Player player(&playerTexture, 180);

    //Bullet
    Texture bulletTexture;
    if (!bulletTexture.loadFromFile("bullet1.png"))
    {
        cout << "LoadBullet1 failed" << endl;
    }
    vector<Bullet> bulletVec;

    //Enamy
   Texture enamyTexture;
    if (!enamyTexture.loadFromFile("enamyS.png"))
    {
        cout << "LoadEnamyS failed" << endl;
    }
    vector<Enamy> enamyVec;
    /*for (int i = 0; i < 5; i++)
    {
        enamyVec.push_back(Enamy(&enamyTexture, 500, Vector2f(2000, rand() % 800 + 100)));
    }*/
    //enamyVec.push_back(Enamy(&enamyTexture, 500, Vector2f(2000, 500)));

    
    //Backgound
    Texture backgound;
    if (!backgound.loadFromFile("backgoundGame.jpg"))
    {
        cout << "LoadBackgound failed" << endl;
    }
    RectangleShape bg;
    bg.setTexture(&backgound);
    bg.setSize(sf::Vector2f(5760.0f, 1080.0f));
    

    Clock clock;
    float deltaTime = 0;
    float sumTimeBull = 0.1;
    float sumTimeEnamy = 0.5;


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sumTimeBull += deltaTime;
        sumTimeEnamy += deltaTime;
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) & sumTimeBull > 0.1)
        {
            float positionBullX = player.shapePlayer.getPosition().x;
            float positionBullY = player.shapePlayer.getPosition().y;
            bulletVec.push_back(Bullet(&bulletTexture, 500, Vector2f(positionBullX + 10, positionBullY)));  
            sumTimeBull = 0;
        }

        if (sumTimeEnamy > 0.5)
        {
            enamyVec.push_back(Enamy(&enamyTexture, 500, Vector2f(2000, rand() % 800 + 100)));
            sumTimeEnamy -= 0.5;
        }

        player.update(deltaTime);


       for (int i = 0; i < enamyVec.size(); i++)
        {
            enamyVec[i].update(deltaTime);
        }


        for (int i = 0; i < bulletVec.size(); i++)
        {
            bulletVec[i].update(deltaTime);
        }

        bg.move(sf::Vector2f(-100.0f * deltaTime, 0.0f));
        if (bg.getPosition().x <= -3840.0f)
        {
            bg.setPosition(sf::Vector2f(0, 0));
        }
       
        while (!bulletVec.empty() && bulletVec.front().shapeBull.getPosition().x>2000.0f)
        {
            bulletVec.erase(bulletVec.begin());
        }

        while (!enamyVec.empty() && enamyVec.front().shapeEnamy.getPosition().x < -10)
        {
            enamyVec.erase(enamyVec.begin());
        }

        window.clear();
        window.draw(bg);

        for (int i = 0; i < enamyVec.size(); i++)
        {
            enamyVec[i].drawOn(&window);
        }

        for (int i = 0; i < bulletVec.size(); i++)
        {
            bulletVec[i].drawOn(&window);
        }

        player.drawOn(&window);
        window.display();
    }
    return 0;
}