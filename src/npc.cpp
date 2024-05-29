#include "npc.h"
#include <godot_cpp/core/class_db.hpp>

using     namespace
godot ;

void
godot::NPC::_bind_methods()
{

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
    switch(p_notification)
    {
      case   NOTIFICATION_PROCESS:
         {

             if  (current_action == nullptr
             || !(current_action -> are_precondition_collection_met(world_state.ptr())))
             {
                 action_queue = goap_planner.ptr()->plan           (world_state.ptr())  ;
             if (action_queue . size            () > 0 )
                 {
                     auto action =  action_queue.pop_front();
            this->current_action =( Action*)
                                  (&action );
                 }
             }
             else
             {
                 if (this->    has_method                       (
                     this->current_action->get_NPC_method_name()))
                 {
                     this->call                                 (
                     this->current_action->get_NPC_method_name());
                 }
             }

         }
         break;
    }
}

godot::NPC:: NPC()
{
}

godot::NPC::~NPC()
{
}

//void
//godot::NPC::        _process(double delta)
//{
//    if  (current_action == nullptr
//    || !(current_action -> are_precondition_collection_met(world_state.ptr())))
//    {
//        action_queue = goap_planner.ptr()->plan           (world_state.ptr())  ;
//    if (action_queue . size            () > 0 )
//        {
//            auto action =  action_queue.pop_front();
//   this->current_action =( Action*)
//                         (&action );
//        }
//    }
//    else
//    {
//        this->call                                 (
//        this->current_action->get_NPC_method_name());
//    }
//}
//
//void
//godot::NPC::_physics_process(double delta)
//{
//
//}

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















