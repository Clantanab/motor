#pragma once


#include <component.hpp>
#include <Render_Node.hpp>
//#include <Model.hpp>
//#include <Model_Obj.hpp> BORRAR

namespace engine 
{

	class RenderComponent : public Component
	{
	public:
		virtual glt::Node& GetNode() = 0;

	};
}
