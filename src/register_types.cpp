#include        "register_types.h"
#include <gdextension_interface.h>
#include                         <godot_cpp/core/class_db.hpp>
#include                                                     <godot_cpp/core/defs.hpp>
#include                                                                             <godot_cpp/godot.hpp>

#include     "hello.h"
#include "plan_goal.h"
#include "plan_action.h"
#include               "world_state.h"
#include                      "goal.h"
#include "action.h"
#include "goap_planner.h"

using namespace godot;

void   initialize_gdextension_types(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }
//GDCLASS(WorldState,Resource);
    ClassDB::register_class<WorldState>();
    ClassDB::register_class<Hello>();
    ClassDB::register_class<PlanGoal  >();
    ClassDB::register_class<PlanAction>();
    ClassDB::register_class<    Goal  >();
    ClassDB::register_class<  Action  >();
    ClassDB::register_class<GOAPPlanner>();

      ClassDB:: bind_method (D_METHOD("are_precondition_collection_met", "world_state"), &Action::are_precondition_collection_met);
      ClassDB:: bind_method (D_METHOD(    "apply_effect_collection"    , "world_state"), &Action::    apply_effect_collection    );

}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }
}

extern "C"
{
// Initialization
    GDExtensionBool GDE_EXPORT godot_cpp_goap_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
    GDExtensionBinding::InitObject       init_obj         (                                   p_get_proc_address,                            p_library,                            r_initialization);
         init_obj.register_initializer(  initialize_gdextension_types);
         init_obj.register_terminator (uninitialize_gdextension_types);
         init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

         return
         init_obj.init();
    }
}










