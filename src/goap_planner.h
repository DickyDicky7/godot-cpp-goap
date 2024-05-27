#ifndef GOAP_PLANNER_H
#define GOAP_PLANNER_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>
#include                                <godot_cpp/variant/typed_array.hpp>
#include                                                                  <godot_cpp/variant/variant.hpp>

//#include                                            "world_state.h"
//#include                                                          "goal.h"
//#include                                                                 "action.h"


namespace godot
{
    class Goal      ;
    class     Action;
    class WorldState;

    class GOAPPlanner : public Resource
    {

  GDCLASS(GOAPPlanner ,        Resource)

protected:

          static     void     _bind_methods ();
          Ref<TypedArray<Action>> action_collection;
          Ref<TypedArray<Goal  >>   goal_collection;

public   :

          GOAPPlanner();
         ~GOAPPlanner();

                void              set_action_collection(const Ref<TypedArray<Action>>& action_collection)      ;
          Ref<TypedArray<Action>> get_action_collection(                                                ) const;

                void                set_goal_collection(const Ref<TypedArray<Goal  >>&   goal_collection)      ;
          Ref<TypedArray<Goal  >>   get_goal_collection(                                                ) const;

          Ref<TypedArray<Action>> plan(const WorldState& world_state) const;

    };
}

#endif//GOAP_PLANNER_H














