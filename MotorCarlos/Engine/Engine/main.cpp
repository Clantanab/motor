#include <iostream>

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <ciso646>
#include <memory>
#include <vector>

using namespace sf;
int main() 
{
	constexpr auto window_width = 800u;
	constexpr auto window_height = 600u;
	RenderWindow window(VideoMode(window_width, window_height), "Box2D Forces", Style::Titlebar | Style::Close, ContextSettings(32));
	//window.setVerticalSyncEnabled(true);

	
	return 0;
}