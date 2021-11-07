#include "Allheader.h"
class EnemyS
{
private:
    Vector2f direction;
    float speed;
    float time;
public:
    RectangleShape shapeEnemyS;
    inline EnemyS(Texture* texture, float spd, Vector2f position, float sizeW, float sizeH)//constuctor
    {
        time = 0;
        shapeEnemyS.setTexture(texture);
        shapeEnemyS.setPosition(position);
        shapeEnemyS.setSize(Vector2f(80, 50));
        shapeEnemyS.setOrigin(shapeEnemyS.getSize() / 2.0f);
        speed = spd;
    }

    inline void update(float deltatime)
    {
        direction = Vector2f(0, 0);
        direction.x -= 1;
        shapeEnemyS.move(normalize(direction) * deltatime * speed);
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
        window->draw(shapeEnemyS);

    }
};
