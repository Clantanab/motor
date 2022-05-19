
#include <meshComponent.hpp>
#include <entity.hpp>

namespace engine
{
	MeshComponent::MeshComponent(Entity* e, const std::string& path, RenderSystem& renderSystem)
	{
		this->entity = e;

		modelo.reset(new glt::Model_Obj(path));

		renderSystem.renderNode->add(*entity->GetID(), modelo);
		
		renderSystem.AddComponent(this);
	}

	void MeshComponent::AssignModel(const std::string& path)
	{
		modelo.reset(new glt::Model_Obj(path));
	}
}