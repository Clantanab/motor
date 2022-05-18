#include <iostream>
#include <window.h>
#include <scene.h>
#include <entity.h>

using namespace engine;
#undef main


int main() 
{



	Window window =  Window("prueba", 800, 800, false);
	Scene scene = Scene("pruebaEscena", window);
;
	Entity e = Entity(&scene);
	Entity e1 = Entity(&scene);
	Entity e2 = Entity(&scene);


	std::cout << *e.GetID() << std::endl;
	std::cout << *e1.GetID() << std::endl;
	std::cout << *e2.GetID() << std::endl;
	do {

	} while (true);
	return 0;
}