
#pragma once 
#include <transform.hpp>
#include <entity.hpp>
#include <iostream>

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


	Transform::Transform( float const positionX,  float const positionY,  float const  positionZ, Transform* const parent)
	{

		this->position.x = positionX;
		this->position.y = positionY;
		this->position.z = positionZ;
		this->rotation.x = 0;
		this->rotation.y = 0;
		this->rotation.z = 0;
		//Scale
		this->scale.x = 1;
		this->scale.y = 1;
		this->scale.z = 1;

		this->parent = parent;
	}

	Transform::Transform(   Vector3 const position,  Vector3 const rotation,  Vector3 const scale,  Transform* const parent)
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

	Vector3 Transform::GetScale() const 
	{
		return this->scale;
	}

	void Transform::Translate(Vector3 position)
	{
		std::cout << *entity->GetID() << std::endl;
		this->position.x += position.x;
		this->position.y += position.y;
		this->position.z += position.z;
	}
	void Transform::Rotate(Vector3 rotation)
	{
		this->rotation.x += rotation.x;
		this->rotation.y += rotation.y;
		this->rotation.z += rotation.z;
	}
	void Transform::SetPosition(Vector3 newPosition)
	{
		this->position = newPosition;
	}

	void Transform::SetRotation(Vector3 newRotation)
	{
		this->rotation = newRotation;
	}

	void Transform::SetScale(Vector3 scale)
	{
		this->scale = scale;
	}

	
}