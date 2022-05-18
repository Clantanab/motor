#pragma once

#include <iostream>
#include <vector>
#include <scene.h>

namespace engine 
{
	class Transform;

	class Entity {

	private:

		std::string id;
		//std::vector<Component*> components;
		Transform* transform = nullptr;
	public:



		Entity(Scene* scene);
		Entity(Scene* scene,std::string& id);
		Entity(Scene* scene, std::string& id, Transform* transform);

		std::string* GetID();
		//void AddComponent(Component* new_component);
		Transform* GetTransform();
		template<typename T>
		T* GetComponent();
	};
}