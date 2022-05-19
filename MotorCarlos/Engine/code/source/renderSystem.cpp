
#include <RendererSystem.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <meshComponent.hpp>
#include <cameraComponent.hpp>
#include <lightComponent.hpp>
//#include <glm/gtc/matrix_transform.hpp>

namespace engine
{
	RenderSystem::RenderSystem(Window* window, int priorty, Kernel* kernel)
	{
		this->window = window;
		this->priority = priority;
		renderNode.reset(new glt::Render_Node);
		kernel->AddTask(this);
	}

	//ESTO POSIBLEMENTE YA NO SEA NECESARIO DESPUES DEL CONSEJO DE ANGEL
	void RenderSystem::AddComponent(RenderComponent* newComponent) 
	{
		renderComponents.push_back(newComponent);
	}

	void RenderSystem::Run() 
	{
		GLsizei height = GLsizei(window->Get_Height());
		GLsizei width = GLsizei(window->Get_Width());

		renderNode->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);


		for (auto& component : renderComponents)
		{
			if (component && component->GetEntitiy()->GetActive())
			{
					Matrix  transform_matrix = component->GetEntitiy()->GetTransform()->GetMatrix();
					component->GetNode().set_transformation(transform_matrix);
			}
		}

		window->Clear();

		renderNode->render();

		window->SwapBuffers();
	}

	void RenderSystem::CreateMeshComponent(Entity* e, std::string path)
	{
		renderComponents.push_back (new MeshComponent(e, path, *this));
	}
	void RenderSystem::CreateCameraComponent(Entity* e)
	{
		renderComponents.push_back(new CameraComponent(e, *this));
	}
	void RenderSystem::CreateLightComponent(Entity* e)
	{
		renderComponents.push_back(new LightComponent(e, *this));
	}
}