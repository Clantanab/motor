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



	SceneManager::Instance().CreateSceneDemo();
	
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