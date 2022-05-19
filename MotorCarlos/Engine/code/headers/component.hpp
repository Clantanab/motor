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
		Entity* GetEntitiy() { return this->entity; };

	};


}