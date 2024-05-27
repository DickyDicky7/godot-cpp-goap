#include "plan_action.h"
#include <godot_cpp/core/class_db.hpp>

using namespace
          godot;

PlanAction:: PlanAction()
{
}

PlanAction::~PlanAction()
{
}

float
PlanAction:: get_duration(                     ) const
{
    return       duration;
}

void
PlanAction:: set_duration(const float& duration)
{
      this->     duration            = duration;
}

float
PlanAction::_get_duration(                     )
{
    return       duration;
}

void
PlanAction::_execute     ()
{
}

void
PlanAction::_bind_methods()
{
   ClassDB:: bind_method (D_METHOD("_get_duration"), &PlanAction::_get_duration);

   ClassDB:: bind_method (D_METHOD(
"_execute"), &PlanAction::_execute);

   ClassDB:: bind_method (D_METHOD( "set_duration" , "duration"), &PlanAction::set_duration);
   ClassDB:: bind_method (D_METHOD( "get_duration"             ), &PlanAction::get_duration);

   ADD_PROPERTY(PropertyInfo(Variant::FLOAT,     "duration")
                                           , "set_duration"
                                           , "get_duration");
}





