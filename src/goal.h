#ifndef GOAL_H
#define GOAL_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/node.hpp>
#include                                <godot_cpp/variant/dictionary.hpp>
#include                                                                 <godot_cpp/variant/variant.hpp>

namespace godot
{
    class Goal : public Node
    {

  GDCLASS(Goal ,        Node)

protected:

static          void   _bind_methods()       ;
          float                    priorities;
          Dictionary desired_state_collection;

public   :

          Goal();
         ~Goal();

           void set_priorities(const float& priorities)     ;
          float get_priorities(                       )const;

                void set_desired_state_collection(const Dictionary& desired_state_collection)     ;
          Dictionary get_desired_state_collection(                                          )const;

    };
}

#endif//GOAL_H
