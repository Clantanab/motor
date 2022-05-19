#pragma once

#include <renderComponent.hpp>


namespace engine
{
	class MeshComponent
	{
	public:

		std::shared_ptr< glt::Model > modelo = nullptr;
		//Mesh_Component(Entity* e, const std::string&, Renderer_System&);




		~MeshComponent() = default;
	};
}
