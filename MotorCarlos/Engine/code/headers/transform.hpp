#pragma once

#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <component.hpp>
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
		Transform(const float positionX, const float positionY, const float positionZ,  Transform* const parent = nullptr);
		Transform( Vector3 const position,  Vector3 const rotation,  Vector3 const scale,  Transform* const parent = nullptr);
	

		void SetParent(Transform* newParent);

		//Transform* GetParent() const;

		Matrix GetMatrix() const;

		Vector3 GetPosition() const;
		Vector3 GetRotation() const;
		Vector3 GetScale() const;

		void Translate(Vector3 tranlation);
		void Rotate(Vector3 rotation);
		void SetPosition(Vector3 newPosition);
		void SetRotation(Vector3 newRotation);
		void SetScale(Vector3 scale);
	};

}