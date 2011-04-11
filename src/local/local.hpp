#ifndef __MESOS_LOCAL_HPP__
#define __MESOS_LOCAL_HPP__

#include <process.hpp>

#include "configurator/configurator.hpp"

#include "master/master.hpp"


namespace mesos { namespace internal { namespace local {

// Register the options recognized by the local runner (a combination of
// master and slave options) with a configurator.
void registerOptions(Configurator* configurator);


// Launch a local cluster with a given number of slaves and given numbers
// of CPUs and memory per slave. Additionally one can also toggle whether
// to initialize Google Logging and whether to log quietly.
process::PID<master::Master> launch(int numSlaves,
                                    int32_t cpus,
                                    int64_t mem,
                                    bool initLogging,
                                    bool quiet);


// Launch a local cluster with a given configuration.
process::PID<master::Master> launch(const Configuration& conf,
                                    bool initLogging);


void shutdown();

}}} // namespace mesos { namespace internal { namespace local {

#endif // __MESOS_LOCAL_HPP__
