#ifndef HELLO_H
#define HELLO_H

#ifdef WIN32
#include <windows.h>
#endif

namespace godot
{
	class Hello
	{
protected:
	static void _bind_methods();

public   :
		  Hello();
	     ~Hello();

	int   Greet();
	};
}

#endif // HELLO_H






