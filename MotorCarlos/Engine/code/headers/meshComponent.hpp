#pragma once

#include <renderComponent.hpp>
#include<RendererSystem.hpp>
#include <Model_Obj.hpp>
#include <Model.hpp>

namespace engine
{
	class MeshComponent : public RenderComponent
	{
		std::shared_ptr< glt::Model > modelo = nullptr;
	public:

		MeshComponent(Entity* e, const std::string&, RenderSystem&);
		void AssignModel(const std::string&);

		~MeshComponent() = default;
	};
}
