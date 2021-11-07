#include"Allheader.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyM.h"
#include "EnemyS.h"
#include "EnemyL.h"
#include "EnemyXL.h"
#include "BananaItem.h"

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

    //EnamyS
   Texture enemySTexture;
    if (!enemySTexture.loadFromFile("enamyS.png"))
    {
        cout << "LoadEnamyS failed" << endl;
    }
    vector<EnemyS> enemySVec;

    //EnamyM
    Texture enemyMTexture;
    if (!enemyMTexture.loadFromFile("enamyM.png"))
    {
        cout << "LoadEnamyM failed" << endl;
    }
    vector<EnemyM> enemyMVec;

    //EnamyL
    Texture enemyLTexture;
    if (!enemyLTexture.loadFromFile("enamyL.png"))
    {
        cout << "LoadEnamyL failed" << endl;
    }
    vector<EnemyL> enemyLVec;

    //EnamyXL
    Texture enemyXLTexture;
    if (!enemyXLTexture.loadFromFile("enamyXL.png"))
    {
        cout << "LoadEnamyXL failed" << endl;
    }
    vector<EnemyXL> enemyXLVec;

    //ItemB
    Texture itemBTexture;
    if (!itemBTexture.loadFromFile("BananaItem.png"))
    {
        cout << "LoadBananaItem failed" << endl;
    }
    vector<ItemB> itemBVec;
    
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
    float sumTimeSEnemy = 0.5;
    float sumTimeMEnemy = 1;
    float sumTimeLEnemy = 1;
    float sumTimeXLEnemy = 1;
    float sumTimeBItem = 1;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sumTimeBull += deltaTime;
        sumTimeSEnemy += deltaTime;
        sumTimeMEnemy += deltaTime;
        sumTimeLEnemy += deltaTime;
        sumTimeXLEnemy += deltaTime;
        sumTimeBItem += deltaTime;
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
                window.close();
        }

        //bornBullet
        if (Keyboard::isKeyPressed(Keyboard::Space) & sumTimeBull > 0.1)
        {
            float positionBullX = player.shapePlayer.getPosition().x;
            float positionBullY = player.shapePlayer.getPosition().y;
            //bulletVec.push_back(Bullet(nullptr, 500, Vector2f(positionBullX + 10, positionBullY)));
            bulletVec.push_back(Bullet(&bulletTexture, 500, Vector2f(positionBullX + 10, positionBullY)));  
            sumTimeBull = 0;
        }

        //bornSEnamy
        if (sumTimeSEnemy > 0.7 )
        {
            //enamyVec.push_back(Enamy(nullptr, 500, Vector2f(2000, rand() % 800 + 100)));
           // enemySVec.push_back(Enemy(&enemySTexture, 1000, Vector2f(2000, 500), 80, 50));
            enemySVec.push_back(EnemyS(&enemySTexture, 700, Vector2f(2000, rand() % 800 + 100),80, 50));
            sumTimeSEnemy -= 0.7;
       

        }

        //bornMEnamy
        if (sumTimeMEnemy > 1)
        {
            enemyMVec.push_back(EnemyM(&enemyMTexture, 1000, Vector2f(2000, 500), 80, 50));
            //enemyMVec.push_back(Enemy(&enemyMTexture, 500, Vector2f(2000, rand() % 800 + 100), 80, 50));
            sumTimeMEnemy -= 1;
      
        }

        //bornLEnamy
        if (sumTimeLEnemy > 2)
        {
            //enemyLVec.push_back(EnemyL(&enemyMTexture, 1000, Vector2f(2000, 700), 80, 50));
            enemyLVec.push_back(EnemyL(&enemyLTexture, 500, Vector2f(2000, rand() % 800 + 100), 80, 50));
            sumTimeLEnemy -= 2;

        }

        //bornXLEnamy
        if (sumTimeXLEnemy > 3)
        {
            enemyXLVec.push_back(EnemyXL(&enemyXLTexture, 1000, Vector2f(2000, 700), 80, 100));
            //enemyXLVec.push_back(EnemyXL(&enemyXLTexture, 500, Vector2f(2000, rand() % 800 + 100), 80, 50));
            sumTimeXLEnemy -= 3;

        }

        //bornItemB
        if (sumTimeBItem > 3)
        {
            itemBVec.push_back(ItemB(&itemBTexture, 1000, Vector2f(2000, 700), 80, 100));
            //itemBVec.push_back(ItemB(&itemBTexture, 500, Vector2f(2000, rand() % 800 + 100), 80, 50));
            sumTimeBItem -= 3;

        }

        //checkColliderEna&Bull
        for (int e = 0; e < enemySVec.size(); e++)
        {
            for (int b = 0; b < bulletVec.size(); b++)
            {
                if (enemySVec[e].shapeEnemyS.getGlobalBounds().intersects(bulletVec[b].shapeBull.getGlobalBounds()))
                {
                    enemySVec[e].shapeEnemyS.setPosition(Vector2f(-500, 500));
                    bulletVec[b].shapeBull.setPosition(Vector2f(2500, 500));
                }
                
            }
        }
        for (int e = 0; e < enemyMVec.size(); e++)
        {
            for (int b = 0; b < bulletVec.size(); b++)
            {
                if (enemyMVec[e].shapeEnemyM.getGlobalBounds().intersects(bulletVec[b].shapeBull.getGlobalBounds()))
                {
                    enemyMVec[e].shapeEnemyM.setPosition(Vector2f(-500, 500));
                    bulletVec[b].shapeBull.setPosition(Vector2f(2500, 500));
                }

            }
        }
        for (int e = 0; e < enemyLVec.size(); e++)
        {
            for (int b = 0; b < bulletVec.size(); b++)
            {
                if (enemyLVec[e].shapeEnemyL.getGlobalBounds().intersects(bulletVec[b].shapeBull.getGlobalBounds()))
                {
                    enemyLVec[e].shapeEnemyL.setPosition(Vector2f(-500, 500));
                    bulletVec[b].shapeBull.setPosition(Vector2f(2500, 500));
                }

            }
        }
        for (int e = 0; e < enemyXLVec.size(); e++)
        {
            for (int b = 0; b < bulletVec.size(); b++)
            {
                if (enemyXLVec[e].shapeEnemyXL.getGlobalBounds().intersects(bulletVec[b].shapeBull.getGlobalBounds()))
                {
                    enemyXLVec[e].shapeEnemyXL.setPosition(Vector2f(-500, 500));
                    bulletVec[b].shapeBull.setPosition(Vector2f(2500, 500));
                }

            }
        }
        for (int i = 0; i < itemBVec.size(); i++)
        {
            for (int b = 0; b < bulletVec.size(); b++)
            {
                if (itemBVec[i].shapeItemB.getGlobalBounds().intersects(bulletVec[b].shapeBull.getGlobalBounds()))
                {
                    itemBVec[i].shapeItemB.setPosition(Vector2f(-500, 500));
                    bulletVec[b].shapeBull.setPosition(Vector2f(2500, 500));
                }

            }
        }

        

        player.update(deltaTime);

        //UpdeteEnemyS
       for (int i = 0; i < enemySVec.size(); i++)
        {
            enemySVec[i].update(deltaTime);
        }

       //UpdeteEnemyM
       for (int i = 0; i < enemyMVec.size(); i++)
       {
           enemyMVec[i].update(deltaTime);
       }

       //UpdeteEnemyL
       for (int i = 0; i < enemyLVec.size(); i++)
       {
           enemyLVec[i].update(deltaTime);
       }

       //UpdeteEnemyXL
       for (int i = 0; i < enemyXLVec.size(); i++)
       {
           enemyXLVec[i].update(deltaTime);
       }

       //UpdeteItemB
       for (int i = 0; i < itemBVec.size(); i++)
       {
           itemBVec[i].update(deltaTime);
       }
       //UpdateBullet
        for (int i = 0; i < bulletVec.size(); i++)
        {
            bulletVec[i].update(deltaTime);
        }

        //BgMove
        bg.move(sf::Vector2f(-100.0f * deltaTime, 0.0f));
        if (bg.getPosition().x <= -3840.0f)
        {
            bg.setPosition(sf::Vector2f(0, 0));
        }
       
        //EraseBull
        while (!bulletVec.empty() && bulletVec.front().shapeBull.getPosition().x>2000.0f)
        {
            bulletVec.erase(bulletVec.begin());
        }
        //EraseEnemyS
        while (!enemySVec.empty() && enemySVec.front().shapeEnemyS.getPosition().x < -10)
        {
            enemySVec.erase(enemySVec.begin());
        }
        //EraseEnemyM
        while (!enemyMVec.empty() && enemyMVec.front().shapeEnemyM.getPosition().x < -10)
        {
            enemyMVec.erase(enemyMVec.begin());
        }
        //EraseEnemyL
        while (!enemyLVec.empty() && enemyLVec.front().shapeEnemyL.getPosition().x < -10)
        {
            enemyLVec.erase(enemyLVec.begin());
        }
        //EraseEnemyXL
        while (!enemyXLVec.empty() && enemyXLVec.front().shapeEnemyXL.getPosition().x < -10)
        {
            enemyXLVec.erase(enemyXLVec.begin());
        }
        //EraseItemB
        while (!itemBVec.empty() && itemBVec.front().shapeItemB.getPosition().x < -10)
        {
            itemBVec.erase(itemBVec.begin());
        }

        window.clear();
        //DrawBackgound
        window.draw(bg);
        //DrawOnEnemy
        for (int i = 0; i < enemySVec.size(); i++)
        {
            enemySVec[i].drawOn(&window);
        }
        for (int i = 0; i < enemyMVec.size(); i++)
        {
            enemyMVec[i].drawOn(&window);
        }
        for (int i = 0; i < enemyLVec.size(); i++)
        {
            enemyLVec[i].drawOn(&window);
        }
        for (int i = 0; i < enemyXLVec.size(); i++)
        {
            enemyXLVec[i].drawOn(&window);
        }
        //DrawOnItem
        for (int i = 0; i < itemBVec.size(); i++)
        {
            itemBVec[i].drawOn(&window);
        }
        //DrawOnBullet
        for (int i = 0; i < bulletVec.size(); i++)
        {
            bulletVec[i].drawOn(&window);
        }
        //DrawOnPlayer
        player.drawOn(&window);
        window.display();
    }
    return 0;
}