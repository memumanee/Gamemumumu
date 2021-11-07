#pragma once
#include "Allheader.h"
class EnemyM
{
private:
    Vector2f direction;
    float speed;
    float time;
public:
    RectangleShape shapeEnemyM;
    inline EnemyM(Texture* texture, float spd, Vector2f position,float sizeW,float sizeH)//constuctor
    {
        time = 0;
        shapeEnemyM.setTexture(texture);
        shapeEnemyM.setPosition(position);
        shapeEnemyM.setSize(Vector2f(80, 50));
        shapeEnemyM.setOrigin(shapeEnemyM.getSize() / 2.0f);
        speed = spd;
    }

    /*inline void update(float deltatime)
    {
        direction = Vector2f(0, 0);
        direction.x -= 1;
        shapeEnamy.move(normalize(direction) * deltatime * speed);
    }*/
    inline void update(float deltatime)
    {
        time -= deltatime;
        //                     T            A
        direction = Vector2f(-0.2,cos(time)/5);
        shapeEnemyM.move(direction * deltatime * speed);
    }
    inline void drawOn(RenderWindow* window)
    {
        window->draw(shapeEnemyM);

    }
};
