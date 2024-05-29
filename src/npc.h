#ifndef NPC_H
#define NPC_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/node.hpp>
#include                            <godot_cpp/variant/dictionary.hpp>
#include                                                             <godot_cpp/variant/variant.hpp>
#include "world_state.h"
#include      "action.h"
#include               "goap_planner.h"

namespace godot
{

    class NPC : public Node
    {

  GDCLASS(NPC ,        Node)

protected:

          static void _bind_methods();

          Ref<WorldState> world_state;
                                     Ref<GOAPPlanner> goap_planner;
                     Action*current_action      ;
          TypedArray<Action>        action_queue;

         // void _notification
         //(int p_notification);
public   :

          NPC();
         ~NPC();

          virtual void         _process(double delta) override;
          //virtual void _physics_process(double delta) override;

          void            set_world_state(const Ref<WorldState>& world_state)      ;
          Ref<WorldState> get_world_state(                                  ) const;

          void             set_goap_planner(const Ref<GOAPPlanner>& goap_planner)      ;
          Ref<GOAPPlanner> get_goap_planner(                                    ) const;
    };
}

#endif//NPC_H

