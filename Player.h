#pragma once
#include "Allheader.h"
static const float VIEW_WIDTH = 1920.0f;	//ปรับขนาดพท.ให้เครื่องบินบินตรงนี้
static const float VIEW_HIGHT = 1080.0f;

class Player
{
private:
	Vector2f direction;
	float speed;
public:
    RectangleShape shapePlayer;
	inline Player(Texture* texture, float spd = 120)//constuctor
	{
        shapePlayer.setTexture(texture);
		shapePlayer.setPosition(Vector2f(200, 400));
		shapePlayer.setSize(Vector2f(100, 100));
		shapePlayer.setOrigin(shapePlayer.getSize()/2.0f);
		speed = spd;
	}

	inline void update(float deltatime)
	{
        direction = Vector2f(0, 0);
        if (Keyboard::isKeyPressed(Keyboard::W) && shapePlayer.getPosition().y > shapePlayer.getOrigin().y)
        {
            direction.y -= 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && shapePlayer.getPosition().y < VIEW_HIGHT - shapePlayer.getOrigin().y)
        {
            direction.y += 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && shapePlayer.getPosition().x > shapePlayer.getOrigin().x)
        {
            direction.x -= 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && shapePlayer.getPosition().x < VIEW_WIDTH - shapePlayer.getOrigin().x)
        {
            direction.x += 1;
        }
        shapePlayer.move(normalize(direction) * deltatime * speed);
	}
    inline void drawOn(RenderWindow *window)
    {
        window->draw(shapePlayer);

    }
};

