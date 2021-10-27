#pragma once
#include "Allheader.h"
class Enamy
{
private:
    Vector2f direction;
    float speed;
public:
    RectangleShape shapeEnamy;
    inline Enamy(Texture* texture, float spd, Vector2f position)//constuctor
    {
        shapeEnamy.setTexture(texture);
        shapeEnamy.setPosition(position);
        shapeEnamy.setSize(Vector2f(80, 50));
        shapeEnamy.setOrigin(shapeEnamy.getSize() / 2.0f);
        speed = spd;
    }

    inline void update(float deltatime)
    {
        direction = Vector2f(0, 0);
        direction.x -= 1;
        shapeEnamy.move(normalize(direction) * deltatime * speed);
    }
    inline void drawOn(RenderWindow* window)
    {
        window->draw(shapeEnamy);

    }
};
