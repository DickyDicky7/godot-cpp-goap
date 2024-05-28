#include "npc.h"
#include <godot_cpp/core/class_db.hpp>

using     namespace
godot ;

void
godot::NPC::_bind_methods()
{
ClassDB::bind_method(D_METHOD("set_world_state", "world_state"), &NPC::set_world_state);
ClassDB::bind_method(D_METHOD("get_world_state"), &NPC::get_world_state);

ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "world_state", PROPERTY_HINT_RESOURCE_TYPE,
vformat("%s/%s:%s", Variant::OBJECT, PROPERTY_HINT_RESOURCE_TYPE, "WorldState")), "set_world_state","get_world_state");
}

godot::NPC:: NPC()
{
}

godot::NPC::~NPC()
{
}

void godot::NPC::set_world_state(const Ref<WorldState>& world_state)
{this->world_state=world_state;
}

Ref<WorldState> godot::NPC::get_world_state() const
{
	return this->world_state;
}

