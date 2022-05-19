#include <iostream>
#include <window.hpp>
#include <scene.hpp>
#include <entity.hpp>
#include <transform.hpp>

#include<kernel.hpp>

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

	Kernel* k = new Kernel();

	int i = 1;

	Task a(i);
	Task a2(2);

	k->AddTask(&a);
	k->AddTask(&a2);
	k->Run();

	//std::cout << *e.GetID() << std::endl;
	//std::cout << *e1.GetID() << std::endl;
	//std::cout << *e2.GetID() << std::endl;
	//std::cout << e.GetTransform()->GetPosition().x << std::endl;
	e.GetTransform()->Translate(Vector3(100, 0, 0));
	//std::cout << e.GetTransform()->GetPosition().x << std::endl;

	do {

	} while (true);
	return 0;
}