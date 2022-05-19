
#include <sceneManager.hpp>


namespace engine
{


	SceneManager::SceneManager() 
	{

	}
	SceneManager::SceneManager(Scene* scene) 
	{
		scenes.push_back(scene);
	}

	Scene* SceneManager::GetCurrentScene() 
	{
		return scenes[currentScene];
	}
	bool SceneManager::GoToScene(std::size_t i)
	{
		if (i >= scenes.size()) {
			std::cout << "El numero de escena no existe" << std::endl;
			return false;
		}
		this->currentScene = i;
		return true;
	}
	bool SceneManager::GoToScene(std::string id)
	{
		bool encontrada = false;


		for (int i = 0; i < scenes.size(); ++i)
		{
			if (scenes[i]->GetName() == id) 
			{
				this->currentScene = i;
				bool encontrada = true;
			}
		}
		if (!encontrada) std::cout << "Escena no encontrada" << std::endl;

		return encontrada;
	}

	void SceneManager::GoToNextScene()
	{
		if (currentScene >= scenes.size() - 1) return;
		 ++currentScene;
	}
	void SceneManager::GoToPreviousScene()
	{
		if (currentScene <= 0) return;
		--currentScene;
	}

	void SceneManager::AddScene(Scene* scene)
	{
		scenes.push_back(scene);
	}

	void SceneManager::EraseScene(std::size_t i)
	{
		if (i >= scenes.size() - 1) return;
	
		scenes.erase(scenes.begin() + i);
	}
	void SceneManager::EraseScene(std::string id)
	{

		for (int i = 0; i < scenes.size(); ++i)
		{
			if (scenes[i]->GetName() == id)
			{
				scenes.erase(scenes.begin() + i);
				return;
			}
		}
	}
}