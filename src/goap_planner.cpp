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
           ClassDB:: bind_method (D_METHOD("set_action_collection", "action_collection"), &GOAPPlanner::set_action_collection);
           ClassDB:: bind_method (D_METHOD("get_action_collection"                     ), &GOAPPlanner::get_action_collection);

           ClassDB::add_property("GOAPPlanner", PropertyInfo(Variant::ARRAY,     "action_collection" , PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":Action"      )
                                                                           , "set_action_collection"
                                                                           , "get_action_collection");

           ClassDB:: bind_method (D_METHOD("set_goal_collection", "goal_collection"), &GOAPPlanner::set_goal_collection);
           ClassDB:: bind_method (D_METHOD("get_goal_collection"                   ), &GOAPPlanner::get_goal_collection);

           ClassDB::add_property("GOAPPlanner", PropertyInfo(Variant::ARRAY,       "goal_collection" , PROPERTY_HINT_TYPE_STRING, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) +         ":Goal")
                                                                           ,   "set_goal_collection"
                                                                           ,   "get_goal_collection");

}

godot::GOAPPlanner:: GOAPPlanner()
{
}

godot::GOAPPlanner::~GOAPPlanner()
{
}

void
godot::GOAPPlanner::set_action_collection(const TypedArray<Action>& action_collection)
{
    this->              action_collection                         = action_collection;
}

TypedArray<Action>
godot::GOAPPlanner::get_action_collection(                                           ) const
{
    return
    this->              action_collection;
}

void
godot::GOAPPlanner::set_goal_collection(const TypedArray<Goal>& goal_collection)
{
    this->              goal_collection                       = goal_collection;
}

TypedArray<Goal>
godot::GOAPPlanner::get_goal_collection(                                       ) const
{
    return
    this->              goal_collection;
}

TypedArray<Action>
godot::GOAPPlanner::plan(const WorldState& world_state) const
{
TypedArray<Action> valid_action_collection       ;
    for (int index = 0;
             index <     action_collection.size();
           ++index                              )
    {
           Action action=action_collection[index];
        if (      action.
               are_precondition_collection_met        (
                                           world_state)
           )
           {
                   valid_action_collection.append(action);
           }
    }

    Goal* chosen_goal = nullptr;
    for (int index = 0;
             index < goal_collection.size();
++index)
{
Goal goal = goals[index];
if (world_state.is_required_state_collection_met(goal.get_desired_state_collection()))
{
continue;
}
if (chosen_goal == nullptr || goal.get_priorities()>chosen_goal->get_priorities())
{
chosen_goal = &goal;
}
}


if (chosen_goal == nullptr) return TypedArray<Action>();

TypedArray<Action> plan_action_collection;
Dictionary current_state_collection = world_state.get_state_collection().duplicate(true);
while (!world_state.is_required_state_collection_met(chosen_goal->get_desired_state_collection()))
{
Action* best_action = nullptr;
for (int index = 0; index < valid_action_collection.size(); ++index)
{
Action action = valid_action_collection[index];
  if (action.are_precondition_collection_met(world_state))
  {
    if (best_action == nullptr || action.get_cost() < best_action->get_cost())
      {
        best_action = &action;
       }
  }
}

if (best_action == nullptr)
  return TypedArray<Action>();

best_action->apply_effect_collection(world_state);
plan_action_collection.append(*best_action);
valid_action_collection.erase(*best_action);

}

    return plan_action_collection;
}
