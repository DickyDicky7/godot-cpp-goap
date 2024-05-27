#include "goap_planner.h"
#include                <godot_cpp/core/class_db.hpp>
#include                                            "world_state.h"
#include                                                          "goal.h"
#include                                                                 "action.h"

using     namespace
godot ;

void
godot::GOAPPlanner::_bind_methods()
{
ClassDB::bind_method(D_METHOD("set_action_collection", "action_collection"), &GOAPPlanner::set_action_collection);
ClassDB::bind_method(D_METHOD("get_action_collection"), &GOAPPlanner::get_action_collection);


ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "action_collection", PROPERTY_HINT_ARRAY_TYPE),"set_action_collection","get_action_collection");
}
#include <godot_cpp/classes/mesh_instance3d.hpp>
godot::GOAPPlanner:: GOAPPlanner()
{MeshInstance3D;
}

godot::GOAPPlanner::~GOAPPlanner()
{
}

void
godot::GOAPPlanner::set_action_collection(const TypedArray<Ref<Action>>& action_collection)
{
    this->              action_collection                              = action_collection;
}

TypedArray<Ref<Action>>
godot::GOAPPlanner::get_action_collection(                                                ) const
{
	return
    this->              action_collection;
}

void
godot::GOAPPlanner::set_goal_collection(const TypedArray<Ref<Goal>>& goal_collection)
{
    this->              goal_collection                            = goal_collection;
}

TypedArray<Ref<Goal>>  
godot::GOAPPlanner::get_goal_collection(                                            ) const
{
	return
    this->              goal_collection;
}

TypedArray<Ref<Action>> godot::GOAPPlanner::plan(const WorldState& world_state) const
{

return
TypedArray<Ref<Action>>();
    /*TypedArray<Action> valid_action_collection;
    for (int index = 0; index < action_collection;++index)
    {
      if (action_collection[index].)
    }
	return TypedArray<Action>();*/
}
