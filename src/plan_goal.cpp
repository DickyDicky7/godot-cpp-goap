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
    ClassDB::bind_method(D_METHOD("get_discontentment", "value"), &PlanGoal::get_discontentment);

    ClassDB::bind_method(D_METHOD("set_name", "name"), &PlanGoal::set_name);
    ClassDB::bind_method(D_METHOD("get_name"        ), &PlanGoal::get_name);

    ClassDB::bind_method(D_METHOD("set_value", "value"), &PlanGoal::set_value);
    ClassDB::bind_method(D_METHOD("get_value"         ), &PlanGoal::get_value);

    ClassDB::bind_method(D_METHOD("set_change_over_time", "change_over_time"), &PlanGoal::set_change_over_time);
    ClassDB::bind_method(D_METHOD("get_change_over_time"                    ), &PlanGoal::get_change_over_time);

    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME,     "name")
                                                  , "set_name"
                                                  , "get_name");

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,     "value")
                                            , "set_value"
                                            , "get_value");

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT,     "change_over_time")
                                            , "set_change_over_time"
                                            , "get_change_over_time");
}








