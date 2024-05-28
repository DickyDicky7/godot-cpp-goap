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

    class  WorldState  ;
    class ActionScript : public GDScript
    {

  GDCLASS(ActionScript ,        GDScript)

protected:

          static void       _bind_methods ()
          {
          }

public   :

          ActionScript()
          {
       this->set_source_code("extends Action;\nfunc on_action_performed_by_npc() -> void:\n\tpass;");
          }
         ~ActionScript()
          {
          }

    };

    class Action : public Resource
    {

  GDCLASS(Action ,        Resource)

protected:

          static void       _bind_methods ();
          Dictionary precondition_collection;
          Dictionary       effect_collection;
          float  cost;

          StringName NPC_method_name;

public   :

          Variant
          custom_script;

          Action();
         ~Action();

                void set_precondition_collection(const Dictionary& precondition_collection)      ;
          Dictionary get_precondition_collection(                                         ) const;

                void       set_effect_collection(const Dictionary&       effect_collection)      ;
          Dictionary       get_effect_collection(                                         ) const;

           void set_cost(const float& cost)      ;
          float get_cost(                 ) const;

          bool are_precondition_collection_met(WorldState* world_state) const;
          void     apply_effect_collection    (WorldState* world_state)      ;

          void    set_custom_script(const Variant& custom_script)      ;
          Variant get_custom_script(                            ) const;

          void       set_NPC_method_name(const StringName& NPC_method_name)      ;
          StringName get_NPC_method_name(                                 ) const;
    };

}

#endif//ACTION_H


























