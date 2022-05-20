#pragma once



#include <updateComponent.hpp>
#include <transform.hpp>


namespace engine
{
	class  EnemyFollower : public UpdateComponent
	{
		Transform* target;
		float speed;
	public:
		

		EnemyFollower(Entity* e, Transform* target, float speeds);

		void Update()  override;

		void SetSpeed(float speed);
		float GetSpeed();

		void SetNewTarget(Transform* target);


	};

}
