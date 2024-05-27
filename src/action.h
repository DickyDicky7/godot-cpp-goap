#ifndef ACTION_H
#define ACTION_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/resource.hpp>
#include                                <godot_cpp/variant/dictionary.hpp>
#include                                                                 <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/node3d.hpp>
//#include <godot_cpp/classes/node>
namespace godot
{

    class WorldState;
    //class Node3D;

    class Action : public Resource
    {

  GDCLASS(Action ,        Resource);

protected:

          static void       _bind_methods ();
          Dictionary precondition_collection;
          Dictionary       effect_collection;
          float  cost;

          TypedArray<Node3D> nodes;

public   :

          Action();
         ~Action();

                void set_precondition_collection(const Dictionary& precondition_collection)      ;
          Dictionary get_precondition_collection(                                         ) const;

                void       set_effect_collection(const Dictionary&       effect_collection)      ;
          Dictionary       get_effect_collection(                                         ) const;

           void set_cost(const float& cost)         ;
          float get_cost(                 )    const;

          bool are_precondition_collection_met(const WorldState& world_state) const;
          void     apply_effect_collection    (      WorldState& world_state)      ;

void set_nodes(const TypedArray<Node3D>& nodes){this->nodes=nodes};
TypedArray<Node3D> get_nodes(){return nodes;};
    };
}

#endif//ACTION_H











