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

	glClearColor(0.5f,0.5f,0.5f, 1.0f);
	Entity e (&scene);
	Entity e1(&scene);
	Entity e2(&scene);




	std::string path = "../../assets/sphere.obj";

	

	int i = 1;

	
	SceneManager::Instance().GetScene(0)->rendererSystem->CreateMeshComponent(&e, path);
	e.GetTransform()->Translate(Vector3(0, 0, -5));
	SceneManager::Instance().GetScene(0)->rendererSystem->CreateCameraComponent(&e1);
	SceneManager::Instance().GetScene(0)->rendererSystem->CreateLightComponent(&e2);
	e2.GetTransform()->Translate(Vector3(10.f, 10.f, 10.f));
	SceneManager::Instance().ActivateScene(0);
	
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