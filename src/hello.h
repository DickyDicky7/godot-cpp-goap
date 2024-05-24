#ifndef HELLO_H
#define HELLO_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/node.hpp>

namespace godot 
{
	class Hello : public Node
	{
		GDCLASS(Hello  , Node )
protected:
	static void _bind_methods();

public   :
		  Hello();
	     ~Hello();

	int   Greet();
	};
}

#endif // HELLO_H






