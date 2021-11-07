#include "Allheader.h"
class ItemB
{
private:
    Vector2f direction;
    float speed;
    float time;
public:
    RectangleShape shapeItemB;
    inline ItemB(Texture* texture, float spd, Vector2f position, float sizeW, float sizeH)//constuctor
    {
        time = 0;
        shapeItemB.setTexture(texture);
        shapeItemB.setPosition(position);
        shapeItemB.setSize(Vector2f(sizeW,sizeH));
        shapeItemB.setOrigin(shapeItemB.getSize() / 2.0f);
        speed = spd;
    }

    inline void update(float deltatime)
    {
        direction = Vector2f(0, 0);
        direction.x -= 1;
        shapeItemB.move(normalize(direction) * deltatime * speed);
    }
    /*inline void update(float deltatime, int i)
    {
        time -= deltatime;
        //                     T            A
        direction = Vector2f(-0.2, cos(time) / 5);
        shapeEnemyS.move(direction * deltatime * speed);
    }*/
    inline void drawOn(RenderWindow* window)
    {
        window->draw(shapeItemB);

    }
};
