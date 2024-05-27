#ifndef PLAN_ACTION_H
#define PLAN_ACTION_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>

namespace godot
{
    class PlanAction:public Resource
    {
  GDCLASS(PlanAction,       Resource)

protected:

          static void _bind_methods();

          float
          duration                   ;

public   :
          PlanAction();
         ~PlanAction();

                 float  get_duration(                     ) const;
                 void   set_duration(const float &duration)      ;
         virtual float _get_duration(                     )      ;

         virtual void  _execute    ();
    };
}

#endif // PLAN_ACTION_H














