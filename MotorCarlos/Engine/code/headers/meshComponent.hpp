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

		MeshComponent(Entity* e, const std::string& path, RenderSystem& renderSystem);
		void AssignModel(const std::string& path);

		~MeshComponent() = default;

		glt::Node& GetNode() override{ return *modelo;}
	};
}
