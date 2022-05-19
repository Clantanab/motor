#include <iostream>
#include <window.hpp>
#include <scene.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <sceneManager.hpp>
#include<kernel.hpp>
#include <render.hpp>
#include <meshComponent.hpp>


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




	std::string path = "../../assets/sphere.obj";

	

	int i = 1;

	SceneManager::Instance().ActivateScene(0);
	
	SceneManager::Instance().GetScene(0)->rendererSystem->CreateMeshComponent(&e, path);


	
	//std::cout << *e.GetID() << std::endl;
	//std::cout << *e1.GetID() << std::endl;
	//std::cout << *e2.GetID() << std::endl;
	//std::cout << e.GetTransform()->GetPosition().x << std::endl;
	//e.GetTransform()->Translate(Vector3(100, 0, 0));
	//std::cout << e.GetTransform()->GetPosition().x << std::endl;

	do {

	} while (true);
	return 0;
}