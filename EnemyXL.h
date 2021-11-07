#pragma once
#include "Allheader.h"
class EnemyXL
{
private:
    Vector2f direction;
    float speed;
    float time;
public:
    RectangleShape shapeEnemyXL;
    inline EnemyXL(Texture* texture, float spd, Vector2f position, float sizeW, float sizeH)//constuctor
    {
        time = 0;
        shapeEnemyXL.setTexture(texture);
        shapeEnemyXL.setPosition(position);
        shapeEnemyXL.setSize(Vector2f(sizeW,sizeH));
        shapeEnemyXL.setOrigin(shapeEnemyXL.getSize() / 2.0f);
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
        direction = Vector2f(-0.2, cos(time) / 5);
        shapeEnemyXL.move(direction * deltatime * speed);
    }
    inline void drawOn(RenderWindow* window)
    {
        window->draw(shapeEnemyXL);

    }
};

