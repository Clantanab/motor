#pragma once

#include <component.hpp>

namespace engine
{
	//Me estaba dando un error de ambiguedad en el player porque el termino entity era ambiguo
	//por lo tanto esta clase ya no hereda de component
	class UpdateComponent  : public Component
	{
	public:
		virtual void Update() {};
	};
}
