#include <gazebo/common/Plugin.hh>
#include "gazebo/physics/physics.hh"
#include <ros/ros.h>

namespace gazebo
{

class FrictionModifier : public WorldPlugin
{
public:
  FrictionModifier() : WorldPlugin()
  {
  }

  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
  {
    // Make sure the ROS node for Gazebo has already been initialized                                                                                    
    if (!ros::isInitialized())
    {
      ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
        << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
      return;
    }
    physics::PhysicsEnginePtr physics = _world->GetPhysicsEngine();
    const std::string frictionModel = "cone_model";
    physics->SetParam("friction_model", frictionModel);


    ROS_INFO("Hello World!");
  }

};
GZ_REGISTER_WORLD_PLUGIN(FrictionModifier)
}
