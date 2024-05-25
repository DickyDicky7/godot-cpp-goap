#include "plan_goal.h"
#include <godot_cpp/core/class_db.hpp>

using namespace
          godot;

PlanGoal:: PlanGoal()
{
}

PlanGoal::~PlanGoal()
{
}

float
PlanGoal::get_discontentment(float value)
{
                            return value;
}

StringName
PlanGoal::get_name(                      ) const
{
    return    name;
}

void
PlanGoal::set_name(const StringName& name)
{
        this->name                 = name;
}

float
PlanGoal::get_value(                  ) const
{
    return    value;
}

void
PlanGoal::set_value(const float& value)
{
        this->value            = value;
}

float
PlanGoal::get_change_over_time(                             ) const
{
    return    change_over_time;
}

void
PlanGoal::set_change_over_time(float const& change_over_time)
{
        this->change_over_time            = change_over_time;
}

void
PlanGoal::_bind_methods()
{

}








