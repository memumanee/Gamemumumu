#pragma once
#include "Allheader.h"


class Bullet
{
private:
    Vector2f direction;
    float speed;
public:
    RectangleShape shapeBull;
    inline Bullet(Texture* texture, float spd,Vector2f position)//constuctor
    {
        shapeBull.setTexture(texture);
        shapeBull.setPosition(position);
        shapeBull.setSize(Vector2f(20,20));
        shapeBull.setOrigin(shapeBull.getSize() / 2.0f);
        speed = spd;
    }

    inline void update(float deltatime)
    {
        direction = Vector2f(0, 0);
        direction.x += 1;
        shapeBull.move(normalize(direction) * deltatime * speed);
    }
    inline void drawOn(RenderWindow* window)
    {
        window->draw(shapeBull);

    } 
};

