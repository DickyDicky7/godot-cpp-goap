#include "npc.h"
#include <godot_cpp/core/class_db.hpp>
#include                             "world_state.h"
#include                                           "action.h"
#include                                                    "goap_planner.h"

using     namespace
godot ;

void
godot::NPC::_bind_methods()
{
}

godot::NPC:: NPC()
{
}

godot::NPC::~NPC()
{
}

void godot::NPC::set_world_state(const WorldState& world_state)
{this->world_state=world_state;
}

WorldState godot::NPC::get_world_state() const
{
	return this->world_state;
}

