#ifndef SRC_SIMULATION_BLOCK
#define SRC_SIMULATION_BLOCK

#include <map>
#include <vector>
#include <string>
#include "ConfigurationValue.h"
#include "SampleTime.h"
#include <stdexcept>

namespace BlockTypes::BasicCpp
{
    class SimulationBlock
    {
        public:
        SimulationBlock(std::map<std::string, BlockTypes::BasicCpp::ConfigurationValue> configurationValues) {};
        virtual const std::shared_ptr<SampleTime> GetSampleTime() const = 0;
        virtual const int GetInputPortAmmount() const = 0;
        virtual const int GetOutputPortAmmount() const = 0;
        virtual const std::vector<bool> InputsHasDirectFeedthrough() const = 0;

        virtual std::vector<double> CalculateOutputs(const std::vector<double> inputs, std::shared_ptr<SampleTime> sampleTime) = 0;
    };
} // namespace BlockTypes::BasicCpp


#endif /* SRC_SIMULATION_BLOCK */
