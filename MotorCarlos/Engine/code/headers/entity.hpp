#pragma once

#include <iostream>
#include <vector>
#include <component.hpp>

namespace engine 
{
	class Transform;
	class Scene;

	class Entity {

	private:

		std::string id;
		std::vector<Component*> components;
		Transform* transform = nullptr;
		bool active = true;
	public:



		Entity(Scene * scene);
		Entity(Scene * scene,std::string& id);
		Entity(Scene * scene, std::string& id, Transform* transform);

		std::string* GetID();
		void AddComponent(Component* new_component);
		Transform* GetTransform();

		void SetActive(bool active);
		bool GetActive() const;


		template<typename T>
		T* GetComponent();
	};
}