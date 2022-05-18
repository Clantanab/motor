


#pragma once

#include <entity.h>
#include <scene.h>
#include <transform.h>
#include <component.h>

namespace engine 
{
	Entity::Entity(Scene* scene)
	{
		this->id = "0";

		Transform* t = new Transform();
		this->transform = t;
		AddComponent(t);

		scene->AddEntity(this);

	}
	Entity::Entity(Scene* scene, std::string& id)
	{
		this->id = id;
		Transform* t = new Transform();
		this->transform = t;
		AddComponent(t);
		scene->AddEntity(this);
	}
	Entity::Entity(Scene* scene, std::string& id, Transform* transform)
	{
		this->id = id;
		this->transform = new Transform();
		this->transform->SetParent(transform);
		AddComponent(this->transform);
	}

	std::string* Entity::GetID() {
		return &id;
	}


	Transform* Entity::GetTransform()
	{
		return this->transform;
	}

	void Entity::AddComponent(Component* new_component)
	{
		components.push_back(new_component);
	}

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