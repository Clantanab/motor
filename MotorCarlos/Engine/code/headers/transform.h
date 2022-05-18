#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <entity.h>
#include <component.h>
namespace engine 
{
	typedef glm::mat4 Matrix;
	typedef glm::vec3 Vector3;


	class Transform: public Component
	{

	private:

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		Transform* parent;
	public:
		
		Transform();
		Transform(  const float positionX, const float positionY, const float positionZ,  Transform* const parent = nullptr);
		Transform(  const Vector3 position, const Vector3 rotation, const Vector3 scale,  Transform* const parent = nullptr);
	

		void SetParent(Transform* newParent);

		//Transform* GetParent() const;

		Matrix GetMatrix() const;

		Vector3 GetPosition() const;
		Vector3 GetRotation() const;
		Vector3 GetScale() const;
	};

}