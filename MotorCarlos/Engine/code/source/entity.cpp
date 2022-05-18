


#pragma once

#include <entity.h>


namespace engine 
{
	Entity::Entity(Scene* scene)
	{
		this->id = "0";

		scene->AddEntity(this);

	}
	Entity::Entity(Scene* scene, std::string& id)
	{
		this->id = id;
		scene->AddEntity(this);
	}
	Entity::Entity(Scene* scene, std::string& id, Transform* transform) {

	}

	std::string* Entity::GetID() {
		return &id;
	}


	Transform* Entity::GetTransform()
	{
		return this->transform;
	}
	/*void Entity::add_component(Component* new_component)
	{
		components.push_back(new_component);
	}*/

	template< typename T >
	T* get_component()
	{
		for (auto& component : components)
		{
			auto realComponent = dynamic_cast<T*>(component);

			if (realComponent)
			{
				return realComponent;
			}
		}

		return nullptr;
	}
}