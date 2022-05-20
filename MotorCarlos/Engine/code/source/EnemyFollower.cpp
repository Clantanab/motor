
#include <EnemyFollower.hpp>


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