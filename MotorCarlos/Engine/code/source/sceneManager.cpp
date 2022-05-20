
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
	//Esta funcion solo sirve para la creacion de una escena demo default 
	void SceneManager::CreateSceneDemo()
	{
		//creacion de ventana y escena
		Window* window = new Window("prueba", 800, 800, false);
		Scene* scene = new Scene("deMo", *window);

		glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
		std::string playerTag = "player";

		//Creacion de las entidades de platyer, luz y camara
		Entity* e = new Entity(scene, playerTag);
		Entity* e1 = new Entity(scene);
		Entity* e2 = new Entity(scene);


		//Creacion de las entidades enemigo
		std::string enemy1Tag = "enemy";
		std::string enemy2Tag = "enemy2";
		std::string enemy3Tag = "enemy3";
		std::string enemy4Tag = "enemy4";
		Entity* e3 = new Entity(scene, enemy1Tag);
		Entity* e4 = new Entity(scene, enemy2Tag);
		Entity* e5 = new Entity(scene, enemy3Tag);
		Entity* e6 = new Entity(scene, enemy4Tag);



		std::string path = "../../assets/sphere.obj";



		int i = 1;

		//Creacion de las meses
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateMeshComponent(e, path);
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateMeshComponent(e3, path);
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateMeshComponent(e4, path);
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateMeshComponent(e5, path);
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateMeshComponent(e6, path);

		//se añade el componente jugador a una entidad
		SceneManager::Instance().GetScene("deMo")->updateSystem->AddPlayerComponent(e, 0.030f, *SceneManager::Instance().GetScene(0)->inputSystem);

		//colocamos todas las entidaddes en sus posiciones iniciales
		e->GetTransform()->Translate(Vector3(0, 0, -10));
		e3->GetTransform()->Translate(Vector3(6, 0, -10));
		e3->GetTransform()->SetScale(Vector3(2, 2, 2));
		e4->GetTransform()->Translate(Vector3(0, 6, -10));
		e4->GetTransform()->SetScale(Vector3(2, 2, 2));
		e5->GetTransform()->Translate(Vector3(0, -6, -10));
		e5->GetTransform()->SetScale(Vector3(2, 2, 2));
		e6->GetTransform()->Translate(Vector3(-6, 0, -10));
		e6->GetTransform()->SetScale(Vector3(2, 2, 2));

		//añadimos los componentes enemigos 
		SceneManager::Instance().GetScene("deMo")->updateSystem->AddEnemyComponent(e3, 0.01f, e->GetTransform());
		SceneManager::Instance().GetScene("deMo")->updateSystem->AddEnemyComponent(e4, 0.01f, e->GetTransform());
		SceneManager::Instance().GetScene("deMo")->updateSystem->AddEnemyComponent(e5, 0.01f, e->GetTransform());
		SceneManager::Instance().GetScene("deMo")->updateSystem->AddEnemyComponent(e6, 0.01f, e->GetTransform());

		//añadimos el componente camara y luz y las colocamos en la escena
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateCameraComponent(e1);
		//SceneManager::Instance().GetScene(0)->updateSystem->AddPlayerComponent(&e1, 0.0050f, *SceneManager::Instance().GetScene(0)->inputSystem);
		SceneManager::Instance().GetScene("deMo")->rendererSystem->CreateLightComponent(e2);
		e2->GetTransform()->Translate(Vector3(10.f, 10.f, 10.f));

		//marcamos la escena como una escena activa (inicia el kernel)
		SceneManager::Instance().ActivateScene("deMo");
	}

	//Esta funcion sirve para resetear la escena demo inicial
	void SceneManager::ResetSceneDemo()
	{
		std::string playerTag = "player";
		std::string enemy1Tag = "enemy";
		std::string enemy2Tag = "enemy2";
		std::string enemy3Tag = "enemy3";
		std::string enemy4Tag = "enemy4";

		SceneManager::Instance().GetScene("deMo")->GetEntity(&playerTag)->GetTransform()->SetPosition(Vector3(0, 0, -10));
		SceneManager::Instance().GetScene("deMo")->GetEntity(&enemy1Tag)->GetTransform()->SetPosition(Vector3(6, 0, -10));
		SceneManager::Instance().GetScene("deMo")->GetEntity(&enemy2Tag)->GetTransform()->SetPosition(Vector3(-6, 0, -10));
		SceneManager::Instance().GetScene("deMo")->GetEntity(&enemy3Tag)->GetTransform()->SetPosition(Vector3(0, 6, -10));
		SceneManager::Instance().GetScene("deMo")->GetEntity(&enemy4Tag)->GetTransform()->SetPosition(Vector3(0, -6, -10));

	}
}