
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
	bool SceneManager::ActivateScene(std::size_t i)
	{
		if (i >= scenes.size()) {
			std::cout << "El numero de escena no existe" << std::endl;
			return false;
		}
		scenes[i]->Init();
		activeScenes.push_back(i);
		return true;
	}
	bool SceneManager::ActivateScene(std::string id)
	{
		bool encontrada = false;


		for (int i = 0; i < scenes.size(); ++i)
		{
			if (scenes[i]->GetName() == id)
			{
				scenes[i]->Init();
				activeScenes.push_back(i);
				 encontrada = true;
			}
		}
		if (!encontrada) std::cout << "Escena no encontrada" << std::endl;

		return encontrada;
	}

	Scene* SceneManager::GetScene(std::size_t i)
	{
		if (i >= scenes.size()) {
			std::cout << "El numero de escena no existe" << std::endl;
			return nullptr;
		}
	
		return scenes[i];
	}
	Scene* SceneManager::GetScene(std::string id)
	{
		for (int i = 0; i < scenes.size(); ++i)
		{
			if (scenes[i]->GetName() == id)
			{
				return scenes[i];

			}
		}
		return nullptr;
	}

	/*DEPRECATED
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
	}*/

	//DEPRECATED
	/*void SceneManager::GoToNextScene()
	{
		if (currentScene >= scenes.size() - 1) return;
		 ++currentScene;
	}
	void SceneManager::GoToPreviousScene()
	{
		if (currentScene <= 0) return;
		--currentScene;
	}*/

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

	void SceneManager::CreateSceneDemo()
	{
		Window* window = new Window("prueba", 800, 800, false);
		Scene* scene = new Scene("deMo", *window);

		glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
		std::string playerTag = "player";
		Entity* e = new Entity(scene, playerTag);
		Entity* e1 = new Entity(scene);
		Entity* e2 = new Entity(scene);
		std::string enemy1Tag = "enemy";
		Entity* e3 = new Entity(scene, enemy1Tag);



		std::string path = "../../assets/sphere.obj";



		int i = 1;


		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateMeshComponent(e, path);
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateMeshComponent(e3, path);
		SceneManager::Instance().GetScene("deMo")->updateSystem->AddPlayerComponent(e, 0.030f, *SceneManager::Instance().GetScene(0)->inputSystem);
		e->GetTransform()->Translate(Vector3(-6, 0, -10));
		e3->GetTransform()->Translate(Vector3(6, 0, -10));
		e3->GetTransform()->SetScale(Vector3(2, 2, 2));
		SceneManager::Instance().GetScene("deMo")->updateSystem->AddEnemyComponent(e3, 0.01f, e->GetTransform());
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateCameraComponent(e1);
		//SceneManager::Instance().GetScene(0)->updateSystem->AddPlayerComponent(&e1, 0.0050f, *SceneManager::Instance().GetScene(0)->inputSystem);
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateLightComponent(e2);
		e2->GetTransform()->Translate(Vector3(10.f, 10.f, 10.f));
		SceneManager::Instance().ActivateScene("deMo");
	}

	void SceneManager::ResetSceneDemo()
	{
		std::string playerTag = "player";
		std::string enemy1Tag = "enemy";
		SceneManager::Instance().GetScene("deMo")->GetEntity(&playerTag)->GetTransform()->SetPosition(Vector3(-6, 0, -10));
		SceneManager::Instance().GetScene("deMo")->GetEntity(&enemy1Tag)->GetTransform()->SetPosition(Vector3(6, 0, -10));

	}
}