#include "goal.h"
#include <godot_cpp/core/class_db.hpp>

using     namespace
godot ;

void
godot::Goal::_bind_methods()
{
    ClassDB:: bind_method (D_METHOD("set_priorities", "priorities"), &Goal::set_priorities);
    ClassDB:: bind_method (D_METHOD("get_priorities"              ), &Goal::get_priorities);

    ClassDB:: bind_method (D_METHOD("set_desired_state_collection", "desired_state_collection"), &Goal::set_desired_state_collection);
    ClassDB:: bind_method (D_METHOD("get_desired_state_collection"                            ), &Goal::get_desired_state_collection);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,     "priorities")
                                            , "set_priorities"
                                            , "get_priorities");

    ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY,     "desired_state_collection")
                                                 , "set_desired_state_collection"
                                                 , "get_desired_state_collection");
}

godot::Goal:: Goal()
{
}

godot::Goal::~Goal()
{
}

void
godot::Goal::set_priorities(const float& priorities)
{
           this->priorities            = priorities;
}

float
godot::Goal::get_priorities(                       ) const
{
    return this->priorities;
}

void
godot::Goal::set_desired_state_collection(const Dictionary& desired_state_collection)
{
           this->desired_state_collection                 = desired_state_collection;
}

Dictionary
godot::Goal::get_desired_state_collection(                                          ) const
{
    return this->desired_state_collection;
}




