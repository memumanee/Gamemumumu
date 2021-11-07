#include "Allheader.h"
class EnemyL
{
private:
    Vector2f direction;
    float speed;
    float time;
public:
    RectangleShape shapeEnemyL;
    inline EnemyL(Texture* texture, float spd, Vector2f position, float sizeW, float sizeH)//constuctor
    {
        time = 0;
        shapeEnemyL.setTexture(texture);
        shapeEnemyL.setPosition(position);
        shapeEnemyL.setSize(Vector2f(100, 100));
        shapeEnemyL.setOrigin(shapeEnemyL.getSize() / 2.0f);
        speed = spd;
    }

    inline void update(float deltatime)
    {
        direction = Vector2f(0, 0);
        direction.x -= 1;
        shapeEnemyL.move(normalize(direction) * deltatime * speed);
    }
    /*inline void update(float deltatime, int i)
    {
        time -= deltatime;
        //                     T            A
        direction = Vector2f(-0.2, cos(time) / 5);
        shapeEnemyL.move(direction * deltatime * speed);
    }*/
    inline void drawOn(RenderWindow* window)
    {
        window->draw(shapeEnemyL);

    }
};