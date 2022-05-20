
#include <EnemyFollower.hpp>
#include <entity.hpp>

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

		dir = glm::normalize(dir);

		dir.x = dir.x * speed;
		dir.y = dir.y * speed;

		this->entity->GetTransform()->Translate(dir);
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