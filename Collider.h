#pragma once
#include "Allheader.h"
class Collider
{
public:
	Vector2f GetPosition() { return body.getPosition(); }
	Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
	Collider(sf::RectangleShape& body) :body(body)
	{
	}

	~Collider()
	{
	}

	inline bool CheckCollider(Collider& other, sf::Vector2f& direction, float push)
	{
		sf::Vector2f otherPosition = other.GetPosition();
		sf::Vector2f otherHalfSize = other.GetHalfSize();
		sf::Vector2f thisPosition = GetPosition();
		sf::Vector2f thisHalfSize = GetHalfSize();

		float deltaX = otherPosition.x - thisPosition.x;
		float deltaY = otherPosition.y - thisPosition.y;
		float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
		float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

		if (intersectX < 0.0f && intersectY < 0.0f)
		{
			
			
			return true;
		}
		return false;
	}
private:
	RectangleShape& body;
};