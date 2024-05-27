#ifndef WORLD_STATE_H
#define WORLD_STATE_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>
#include                                <godot_cpp/variant/dictionary.hpp>
#include                                                                 <godot_cpp/variant/variant.hpp>

namespace godot
{
    class WorldState : public Resource
    {

  GDCLASS(WorldState ,        Resource)

protected:

          static void      _bind_methods() ;
          Dictionary       state_collection;

public   :

          WorldState();
         ~WorldState();

          Dictionary   get_state_collection    (                                           ) const;
          void         set_state_collection    (const Dictionary &         state_collection)      ;

             Variant   get_state               (const    Variant &key                      ) const                ;
          void         set_state               (const    Variant &key                      , const Variant &value);

          bool is_required_state_collection_met(const Dictionary &required_state_collection) const;

    };
}

#endif//WORLD_STATE_H



















