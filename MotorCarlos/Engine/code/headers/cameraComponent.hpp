#pragma once


#include <renderComponent.hpp>
#include <Camera.hpp>
#include <RendererSystem.hpp>


namespace engine
{
	class CameraComponent : public RenderComponent
	{
	protected:
		std::shared_ptr< glt::Camera > camera = nullptr;


	public:
		glt::Node& GetNode() override
		{
			return *camera;
		}

		CameraComponent(Entity* e, RenderSystem& renderer);
	};
}