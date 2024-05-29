#include "npc.h"
#include <godot_cpp/core/class_db.hpp>

using     namespace
godot ;

void
godot::NPC::_bind_methods()
{
ClassDB::bind_method(D_METHOD("update"), &NPC::update);
   ClassDB:: bind_method (D_METHOD("set_world_state", "world_state"), &NPC::set_world_state);
   ClassDB:: bind_method (D_METHOD("get_world_state"               ), &NPC::get_world_state);

   ADD_PROPERTY(PropertyInfo(Variant::OBJECT,     "world_state" , PROPERTY_HINT_RESOURCE_TYPE, "WorldState")
                                            , "set_world_state"
                                            , "get_world_state");

   //ClassDB:: bind_method (D_METHOD("set_action_queue", "action_queue"), &NPC::set_action_queue);
   //ClassDB:: bind_method (D_METHOD("get_action_queue"                ), &NPC::get_action_queue);
   //
   //
   //ADD_PROPERTY(PropertyInfo(Variant::ARRAY,     "action_queue" , PROPERTY_HINT_ARRAY_TYPE, vformat("%s/%s:%s", Variant::OBJECT, PROPERTY_HINT_RESOURCE_TYPE
   //                                        ,     "Action"      ))
   //                                        , "set_action_queue"
   //                                        , "get_action_queue");

   ClassDB:: bind_method (D_METHOD("set_goap_planner", "goap_planner"), &NPC::set_goap_planner);
   ClassDB:: bind_method (D_METHOD("get_goap_planner"                ), &NPC::get_goap_planner);

   ADD_PROPERTY(PropertyInfo(Variant::OBJECT,     "goal_planner" , PROPERTY_HINT_RESOURCE_TYPE, "GOAPPlanner")
                                            , "set_goap_planner"
                                            , "get_goap_planner");
}

void
godot::NPC::_notification(
       int p_notification)
{
////godot::_err_print_error("_notification", "npc.cpp", 39, "call", true, true);
    switch(p_notification)
    {
      case   NOTIFICATION_PHYSICS_PROCESS:
         {
godot::_err_print_error("_notification", "npc.cpp", 44, "LALALA", false, false);
try
{
             if  (current_action == nullptr
             || !(current_action -> are_precondition_collection_met(world_state.ptr())))
             {
//godot::_err_print_error("_notification", "npc.cpp", 48, "ok 1", true, true);
                 action_queue = goap_planner.ptr()->plan           (world_state.ptr())  ;
             if (action_queue . size            () > 0 )
                 {
//godot::_err_print_error("_notification", "npc.cpp", 48, "ok 2", true, true);
                     auto action =  action_queue.pop_front();
            this->current_action =( Action*)
                                  (&action );
                 }
             }
             else
             {
//godot::_err_print_error("_notification", "npc.cpp", 48, "ok 3", true, true);
                 if (this->    has_method                       (
                     this->current_action->get_NPC_method_name()))
                 {
//godot::_err_print_error("_notification", "npc.cpp", 48, "ok 4", true, true);
                     this->call                                 (
                     this->current_action->get_NPC_method_name());
                 }
                 else
                 {
////godot::_err_print_error("_notification", "npc.cpp", 60, "method not found", true, true);
//godot::_err_print_error("_notification", "npc.cpp", 48, "ok 5", true, true);
                 }
             }

}
catch (exception& e)
{
godot::_err_print_error("_notification", "npc.cpp", 80,  e.what(), false, false);
}
         }
         break;
    }
}

godot::NPC:: NPC()
{
//this->set_script((const Variant&)((Object)NPCScript()));
}

godot::NPC::~NPC()
{
}

//void
//godot::NPC::        _process(double delta)
//{
//}
//
//void
//godot::NPC::_physics_process(double delta)
//{
//
//}

void godot::NPC::update()
{
godot::_err_print_error("_notification", "npc.cpp", 48, "ok 0", false, false);
//    if  (current_action == nullptr
//    || !(current_action -> are_precondition_collection_met(world_state.ptr())))
//    {
////godot::_err_print_error("_notification", "npc.cpp", 48, "ok 1", false, false);
//        action_queue = goap_planner.ptr()->plan           (world_state.ptr())  ;
//    if (action_queue . size            () > 0 )
//        {
////godot::_err_print_error("_notification", "npc.cpp", 48, "ok 2", false, false);
//            auto action =  action_queue.pop_front();
//   this->current_action =( Action*)
//                         (&action );
//        }
//    }
//    else
//    {
////godot::_err_print_error("_notification", "npc.cpp", 48, "ok 3", false, false);
//        this->call                                 (
//        this->current_action->get_NPC_method_name());
//    }

}

void
godot::NPC::set_world_state(const Ref<WorldState>& world_state)
{
    this->      world_state                      = world_state;
}

Ref<WorldState>
godot::NPC::get_world_state(                                  )
const
{
    return
    this->      world_state;
}

void
godot::NPC::set_goap_planner(const Ref<GOAPPlanner>& goap_planner)
{
    this->      goap_planner                       = goap_planner;
}

Ref<GOAPPlanner>
godot::NPC::get_goap_planner(                                    )
const
{
    return
    this->      goap_planner;
}

//void
//godot::NPC::set_action_queue(const TypedArray<Ref<Action>>& action_queue)
//{
//    this->      action_queue                              = action_queue;
//}
//
//TypedArray<Ref<Action>>
//godot::NPC::get_action_queue(                                           ) const
//{
//    return
//    this->      action_queue;
//}















