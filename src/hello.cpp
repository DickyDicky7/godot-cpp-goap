#include "hello.h"
#include <godot_cpp/core/class_db.hpp>

using namespace
          godot;

Hello:: Hello()
{

}

Hello::~Hello()
{

}

int
Hello::Greet()
{
	return 69;
}

void
Hello      ::_bind_methods()
{
	ClassDB:: bind_method (D_METHOD("Greet"), &Hello::Greet);
}
 

