#ifndef SRC_SIMULATION_BLOCK_WITH_CONTINUOUS_STATES
#define SRC_SIMULATION_BLOCK_WITH_CONTINUOUS_STATES

#include "SimulationBlock.h"
#include <utility>
#include <iostream>

namespace BlockTypes::BasicCpp
{
    template <typename T>
    class SimulationBlockWithContinuousStates : public SimulationBlock<T>
    {
        public:
            SimulationBlockWithContinuousStates(std::map<std::string, BlockTypes::BasicCpp::ConfigurationValue> configurationValues, 
                                                std::shared_ptr<IEventHandler> eventHandler) : SimulationBlock<T>(configurationValues, eventHandler) {};

            virtual const std::vector<double> GetContinuousStates() const = 0;
            virtual void SetContinuousStates(std::vector<double> newStates) = 0;

            virtual const std::vector<double> GetContinuousStateDerivatives(const std::vector<T> inputs, const std::shared_ptr<BlockTypes::BasicCpp::SampleTime> sampleTime, double currentTime) const = 0;
            virtual const std::vector<std::vector<double>> GetContinuousStateJacobians(const std::vector<T> inputs, const std::shared_ptr<BlockTypes::BasicCpp::SampleTime> sampleTime, double currentTime) const
            {
                throw std::logic_error("Jacobian not implemented in this BasicCpp block. This is the default behaviour.");
            }
    };
}
#endif /* SRC_SIMULATION_BLOCK_WITH_CONTINUOUS_STATES */
