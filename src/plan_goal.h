#ifndef PLAN_GOAL_H
#define PLAN_GOAL_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>

namespace godot
{
    class PlanGoal : public Resource
    {

  GDCLASS(PlanGoal ,        Resource)

protected:

          static void _bind_methods();

          StringName
                name;
          float            value;
          float change_over_time;

public   :

          PlanGoal();
         ~PlanGoal();

          virtual float get_discontentment(float value);

          StringName get_name(                      ) const;
                void set_name(const StringName &name)      ;

          float get_value(                  ) const;
          void  set_value(const float& value)      ;

          float get_change_over_time(                             ) const;
          void  set_change_over_time(float const& change_over_time)      ;

    };
}

#endif // PLAN_GOAL_H














