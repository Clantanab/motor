
#include <RendererSystem.hpp>
#include <entity.hpp>
#include <transform.hpp>
//#include <glm/gtc/matrix_transform.hpp>

namespace engine
{


	RenderSystem::RenderSystem(Window* window)
	{
		window = window;
		renderNode.reset(new glt::Render_Node);
	}


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
}