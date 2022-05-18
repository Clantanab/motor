

#include <transform.h>


namespace engine
{


	Transform::Transform()
	{
		this->parent = nullptr;
		//Position
		this->position.x = 0;
		this->position.y = 0;
		this->position.z = 0;
		//Rotation
		this->rotation.x = 0;
		this->rotation.y = 0;
		this->rotation.z = 0;
		//Scale
		this->scale.x = 1;
		this->scale.y = 1;
		this->scale.z = 1;
	}


	Transform::Transform(const float positionX, const float positionY, const float positionZ,  Transform* const parent = nullptr)
	{

		this->position.x = positionX;
		this->position.y = positionY;
		this->position.z = positionZ;

		this->parent = parent;
	}

	Transform::Transform(  const Vector3 position, const Vector3 rotation, const Vector3 scale,  Transform* const parent = nullptr)
	{

		this->position = position;
		this->rotation = rotation;
		this->scale = scale;

		this->parent = parent;
	}


	void Transform::SetParent(Transform* const newParent)
	{
		this->parent = newParent;
	}

	Matrix Transform::GetMatrix() const 
	{
		Matrix matrix(1);

		matrix = glm::translate(matrix, position);
		matrix = glm::rotate(matrix, rotation.x, Vector3(1, 0, 0));
		matrix = glm::rotate(matrix, rotation.y, Vector3(0, 1, 0));
		matrix = glm::rotate(matrix, rotation.z, Vector3(0, 0, 1));
		matrix = glm::scale(matrix, scale);

		if (parent)
		{
			return parent->GetMatrix() * matrix;
		}

		return matrix;
	}


	Vector3 Transform::GetPosition() const
	{
		return this->position;
	}

	Vector3 Transform::GetRotation() const 
	{
		return this->rotation;
	}

	Vector3 Transform::GetScale() const {
		return this->scale;
	}
}