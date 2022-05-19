
#include <cameraComponent.hpp>
#include <entity.hpp>

namespace engine
{

	CameraComponent::CameraComponent(Entity* e, RenderSystem& render_system)
	{
		this->entity = e;
		camera.reset(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		render_system.renderNode->add(*entity->GetID(), camera);


	}






}