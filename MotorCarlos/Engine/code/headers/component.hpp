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
	};


}