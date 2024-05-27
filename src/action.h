#ifndef ACTION_H
#define ACTION_H

#ifdef WIN32
#include <windows.h>
#endif

//#include "world_state.h"
#include <godot_cpp/classes/node.hpp>
#include                                <godot_cpp/variant/dictionary.hpp>
#include                                                                 <godot_cpp/variant/variant.hpp>

namespace godot
{
    class Action : public Node
    {

  GDCLASS(Action ,        Node);

protected:

          static void       _bind_methods ();
          Dictionary precondition_collection;
          Dictionary       effect_collection;
          float  cost;

public   :

          Action();
         ~Action();

                void set_precondition_collection(const Dictionary& precondition_collection)     ;
          Dictionary get_precondition_collection(                                         )const;

                void set_effect_collection(const Dictionary& effect_collection)     ;
          Dictionary get_effect_collection(                                   )const;

           void set_cost(const float& cost)     ;
          float get_cost(                 )const;

          bool are_precondition_collection_met(const WorldState& world_state) const;
          void     apply_effect_collection    (      WorldState& world_state)      ;
    };
}

#endif//ACTION_H



