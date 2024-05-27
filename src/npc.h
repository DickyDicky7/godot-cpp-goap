#ifndef NPC_H
#define NPC_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/node.hpp>
#include                            <godot_cpp/variant/dictionary.hpp>
#include                                                             <godot_cpp/variant/variant.hpp>

namespace godot
{

    class WorldState ;
    class Action;
    class GOAPPlanner;

    class NPC : public Node
    {

  GDCLASS(NPC ,        Node)

protected:

          static void       _bind_methods ();

          WorldState  world_state  ;
          GOAPPlanner  goap_planner;
          Action current_action;
          TypedArray<Action> action_queue;

public   :

          virtual void _process(double delta) override;
          virtual void _physics_process(double delta) override;

           void perform_action(Action action, double delta);
    };
}

#endif//NPC_H
