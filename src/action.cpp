#include "action.h"
#include <godot_cpp/core/class_db.hpp>
#include                             "world_state.h"

using     namespace
godot ;

void
godot::Action::_bind_methods()
{
      //ClassDB:: bind_method (D_METHOD("are_precondition_collection_met", "world_state"), &Action::are_precondition_collection_met);
      //ClassDB:: bind_method (D_METHOD(    "apply_effect_collection"    , "world_state"), &Action::    apply_effect_collection    );

      ClassDB:: bind_method (D_METHOD("set_precondition_collection", "precondition_collection"), &Action::set_precondition_collection);
      ClassDB:: bind_method (D_METHOD("get_precondition_collection"                           ), &Action::get_precondition_collection);

      ClassDB:: bind_method (D_METHOD("set_effect_collection", "effect_collection"), &Action::set_effect_collection);
      ClassDB:: bind_method (D_METHOD("get_effect_collection"                     ), &Action::get_effect_collection);

      ClassDB:: bind_method (D_METHOD("set_cost", "cost"), &Action::set_cost);
      ClassDB:: bind_method (D_METHOD("get_cost"        ), &Action::get_cost);

      ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY,     "precondition_collection")
                                                   , "set_precondition_collection"
                                                   , "get_precondition_collection");

      ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY,     "effect_collection")
                                                   , "set_effect_collection"
                                                   , "get_effect_collection");

      ADD_PROPERTY(PropertyInfo(Variant::FLOAT,     "cost")
                                              , "set_cost"
                                              , "get_cost");


      ClassDB:: bind_method (D_METHOD("set_script", "script"), &Action::set_script);
      ClassDB:: bind_method (D_METHOD("get_script"          ), &Action::get_script);

      //ClassDB::add_property("Action", PropertyInfo(Variant::OBJECT,     "script" , PROPERTY_HINT_RESOURCE_TYPE, String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":GDScript")
      //                                                            , "set_script"
      //                                                            , "get_script");

      ADD_PROPERTY(PropertyInfo(Variant::OBJECT,     "script" , PROPERTY_HINT_RESOURCE_TYPE, vformat("%s/%s:%s", Variant::OBJECT, PROPERTY_HINT_RESOURCE_TYPE
                                               ,   "GDScript"))
                                               , "set_script"
                                               , "get_script");
}

godot::Action:: Action()
{
    this->cost   = 1.0f      ;
    this->script = GDScript();
    this->script .set_source_code("extend Action;\nfunc on_action_performed_by_npc() -> void:\n\tpass;");
       Object::   set_script     ((const Variant&) this -> script                                      );
}

godot::Action::~Action()
{

}

void
godot::Action::set_precondition_collection(const Dictionary& precondition_collection)
{
    this->         precondition_collection                 = precondition_collection;
}

Dictionary
godot::Action::get_precondition_collection(                                         )
const
{
    return
    this->         precondition_collection;
}

void
godot::Action::set_effect_collection(const Dictionary& effect_collection)
{
    this->         effect_collection                 = effect_collection;
}

Dictionary
godot::Action::get_effect_collection(                                   )
const
{
    return
    this->         effect_collection;
}

void
godot::Action::set_cost(const float& cost)
{
    this->         cost            = cost;
}

float
godot::Action::get_cost(                 )
const
{
    return
    this->         cost;
}

bool
godot::Action::are_precondition_collection_met(const WorldState& world_state)
const
{
    return                                                       world_state.is_required_state_collection_met
                  (precondition_collection);
}

void
godot::Action::    apply_effect_collection    (      WorldState& world_state)
{
             Array              keys = this->effect_collection.keys(       );
    for (int index = 0; index < keys.size(); ++index)
    {
        world_state.set_state ( keys[index], effect_collection[keys[index]]);
    }
}

void
godot::Action::set_script( const Script &          script)
{
    this->         script                        = script ;
       Object::set_script((const Variant&) this -> script);
}

Script
godot::Action::get_script(                               )
const
{
	return
    this->         script;
}
























