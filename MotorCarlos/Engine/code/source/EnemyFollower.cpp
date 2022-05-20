
#include <EnemyFollower.hpp>
#include <entity.hpp>
#include <sceneManager.hpp>

namespace engine
{
	EnemyFollower::EnemyFollower(Entity* e, Transform* target, float speeds)
	{
		this->entity = e;
		this->target = target;
		this->speed = speeds;
	}

	void EnemyFollower::Update()
	{
		Vector3 myPosition(this->entity->GetTransform()->GetPosition());

		Vector3 dir(0,0,0);

		dir = target->GetPosition() - myPosition;
		float distance = glm::length(dir);

		dir = glm::normalize(dir);

		dir.x = dir.x * speed;
		dir.y = dir.y * speed;

		this->entity->GetTransform()->Translate(dir);

		float error = (glm::length(entity->GetTransform()->GetScale() + target->GetScale())) / 4.0f;
		if (distance <= error)
		{
			std::cout << "GAME OVER" << std::endl;
			SceneManager::Instance().ResetSceneDemo();
		}
	}

	void EnemyFollower::SetNewTarget(Transform* target)
	{
		this->target = target;
	}

	void EnemyFollower::SetSpeed(float speed)
	{
		this->speed = speed;
	}

	float EnemyFollower::GetSpeed()
	{
		return this->speed;
	}
}