#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;	// sfml
using namespace std; // standard

inline float lenght(Vector2f vec)
{
	return  sqrt(vec.x * vec.x + vec.y * vec.y);
}

inline Vector2f normalize(Vector2f vec) {
	float len = lenght(vec);
	if (len != 0)
		return vec / len;	//vec.x /len,vec.y / len
	return vec;
}