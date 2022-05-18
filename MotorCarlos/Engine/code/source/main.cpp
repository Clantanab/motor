#include <iostream>
#include <window.h>
#include <scene.h>
#include <entity.h>

using namespace engine;
#undef main


int main() 
{



	Window window ("prueba", 800, 800, false);
	Scene scene   ("pruebaEscena", window);
;
	Entity e (&scene);
	Entity e1(&scene);
	Entity e2(&scene);


	std::cout << *e.GetID() << std::endl;
	std::cout << *e1.GetID() << std::endl;
	std::cout << *e2.GetID() << std::endl;
	do {

	} while (true);
	return 0;
}