#pragma once



namespace engine
{

	class Entity;


	class Component 
	{
	protected:
		
		Entity* entity = nullptr;
	public:
		virtual ~Component() = default;
		void SetEntity(Entity* const e) { this->entity = e; }

		template <typename T>
		T* GetComponent() const { return entity->GetComponent<T>(); }
	};


}