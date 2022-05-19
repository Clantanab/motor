
#include <lightComponent.hpp>
#include <entity.hpp>

namespace engine
{
	LightComponent::LightComponent(Entity* e, RenderSystem& system)
	{
		luz.reset(new glt::Light);
		this->entity = e;
		system.renderNode->add(*entity->GetID(), luz);
	}
}