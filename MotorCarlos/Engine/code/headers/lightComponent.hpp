#pragma once


#include <renderComponent.hpp>
#include <Light.hpp>
#include <RendererSystem.hpp>

namespace engine
{
	class LightComponent : public RenderComponent
	{
	protected:

		std::shared_ptr< glt::Light > luz = nullptr;
	public:
		glt::Node& GetNode() override
		{
			return *luz;
		}
		LightComponent(Entity* e, RenderSystem& system);

	};
}