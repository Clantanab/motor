#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <entity.h>

namespace engine 
{
	typedef glm::mat4 Matrix;
	typedef glm::vec3 Vector3;


	class Transform
	{

	private:
		
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		Transform* parent;
	public:
		
		Transform(Entity* entity);
		Transform(Entity* entity, float positionX, float positionY, float positionZ, Transform* parent = nullptr);
		Transform(Entity* entity, Matrix m, Transform* parent = nullptr);

		void SetParent(Transform* newParent);


		Matrix GetMatrix();

		Vector3 GetPosition();
		Vector3 GetRotation();
		Vector3 GetScale();

		void SetTransform(Matrix m);
	private:

	};

}