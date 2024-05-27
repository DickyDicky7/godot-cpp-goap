//#ifndef PLAN_WORLD_MODEL_H
//#define PLAN_WORLD_MODEL_H
//
//#ifdef WIN32
//#include <windows.h>
//#endif
//
//#include <godot_cpp/classes/resource.hpp>
//#include                                <godot_cpp/variant/typed_array.hpp>
//#include                                                                  <godot_cpp/classes/ref.hpp>
//
//#include "plan_goal.h"
//#include "plan_action.h"
//
//namespace godot
//{
//    class PlanWorldModel : public Resource
//    {
//
//  GDCLASS(PlanWorldModel ,        Resource)
//
//protected:
//
//          static void _bind_methods();
//
//
//
//          int   actions_pointer   ;
//           bool actions_discovered;
//          float passing_timing    ;
//
//          TypedArray<Ref<PlanAction>> possible_actions;
//          TypedArray<Ref<PlanGoal  >>            goals;
//public   :
//
//          PlanWorldModel();
//         ~PlanWorldModel();
//
//          virtual void apply_action(PlanAction action) = 0;
//          virtual
//          PlanWorldModel       copy(                 ) = 0;
//          virtual void 
//    };
//}
//
//#endif//PLAN_WORLD_MODEL_H
