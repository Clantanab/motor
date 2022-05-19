#pragma once


#include <scene.hpp>
#include <vector>


namespace engine
{
	class SceneManager
	{
	private:

		std::vector<Scene*> scenes;
		std::vector<int> activeScenes;



	public:

		static SceneManager& Instance() 
		{
			static SceneManager sceneManager;
			return sceneManager;
		}


		SceneManager();
		SceneManager(Scene* scene);

		
		bool ActivateScene(std::size_t i);
		bool ActivateScene(std::string id);



		void AddScene(Scene* scene);
		void EraseScene(std::size_t i);
		void EraseScene(std::string id);
	};

}