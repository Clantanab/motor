#pragma once


#include <scene.hpp>
#include <vector>


namespace engine
{
	class SceneManager
	{
	private:

		std::vector<Scene*> scenes;

		std::size_t currentScene = 0;

	public:

		static SceneManager& Instance() 
		{
			static SceneManager sceneManager;
			return sceneManager;
		}


		SceneManager();
		SceneManager(Scene* scene);

		Scene* GetCurrentScene();
		bool GoToScene(std::size_t i);
		bool GoToScene(std::string id);

		void GoToNextScene();
		void GoToPreviousScene();

		void AddScene(Scene* scene);
		void EraseScene(std::size_t i);
		void EraseScene(std::string id);
	};

}