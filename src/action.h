#ifndef ACTION_H
#define ACTION_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>
#include                                <godot_cpp/variant/dictionary.hpp>
#include                                                                 <godot_cpp/variant/variant.hpp>
#include                                                                                               <godot_cpp/classes/gd_script.hpp>

namespace godot
{

    class WorldState;

    class Action : public Resource
    {

  GDCLASS(Action ,        Resource)

protected:

          static void       _bind_methods ();
          Dictionary precondition_collection;
          Dictionary       effect_collection;
          float  cost;

          //Script
          //script     ;

public   :

          Action();
         ~Action();

                void set_precondition_collection(const Dictionary& precondition_collection)      ;
          Dictionary get_precondition_collection(                                         ) const;

                void       set_effect_collection(const Dictionary&       effect_collection)      ;
          Dictionary       get_effect_collection(                                         ) const;

           void set_cost(const float& cost)         ;
          float get_cost(                 )    const;

          bool are_precondition_collection_met(const WorldState& world_state) const;
          void     apply_effect_collection    (      WorldState& world_state)      ;

          //void   set_script(const Script& script)      ;
          //Script get_script(                    ) const;
    };
}

#endif//ACTION_H














