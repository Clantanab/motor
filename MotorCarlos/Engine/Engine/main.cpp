#include <iostream>

#include <sfml-2.5.1\include\SFML\Window.hpp>
#include <sfml-2.5.1\include\SFML\Graphics.hpp>

int main() 
{

	RenderWindow window(VideoMode(window_width, window_height), "Box2D Forces", Style::Titlebar | Style::Close, ContextSettings(32));


	return 0;
}