#include "world_state.h"
#include <godot_cpp/core/class_db.hpp>

using     namespace
godot ;

void
godot::WorldState::_bind_methods()
{
          ClassDB:: bind_method (D_METHOD("get_state_collection"                    ), &WorldState::get_state_collection);
          ClassDB:: bind_method (D_METHOD("set_state_collection", "state_collection"), &WorldState::set_state_collection);

          ClassDB:: bind_method (D_METHOD("get_state", "key"         ), &WorldState::get_state);
          ClassDB:: bind_method (D_METHOD("set_state", "key", "value"), &WorldState::set_state);

          ClassDB:: bind_method (D_METHOD("is_required_state_collection_met", "required_state_collection"),
                              &WorldState::is_required_state_collection_met);

          ADD_PROPERTY    (
              PropertyInfo(       Variant::DICTIONARY,     "state_collection")
                                                     , "set_state_collection"
                                                     , "get_state_collection");
}

godot::WorldState:: WorldState()
{
}

godot::WorldState::~WorldState()
{
}

Dictionary
godot::WorldState::get_state_collection(                                  ) const
{
    return       this->state_collection;
}

void
godot::WorldState::set_state_collection(const Dictionary& state_collection)
{
                 this->state_collection                 = state_collection;
}

Variant
godot::WorldState::get_state(const Variant& key                      ) const
{
    return       this->state_collection.get(key,                    0);
}

void
godot::WorldState::set_state(const Variant& key, const Variant& value)
{
                 this->state_collection    [key]              = value;
}

bool
godot::WorldState::is_required_state_collection_met(
const  Dictionary&    required_state_collection    ) const
{
	         Array              keys       =
                      required_state_collection.keys();
    for (int index = 0; index < keys.size();  ++index)
    {
     if (             required_state_collection.get(keys[index], 0)
     !=                        state_collection.get(keys[index], 0)
        )
        {
            return 0;
        }
            return 1;
    }
}
















