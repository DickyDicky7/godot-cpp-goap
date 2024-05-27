#include "plan_world_model.h"
#include                   <godot_cpp/core/class_db.hpp>

using namespace
          godot;


PlanWorldModel:: PlanWorldModel()
{
    this->possible_actions = new TypedArray<Ref<PlanAction>>();
    this->           goals = new TypedArray<Ref<PlanGoal  >>();
}

PlanWorldModel::~PlanWorldModel()
{
}

void
PlanWorldModel::_bind_methods()
{
}
