#ifndef SRC_SIMULATION_BLOCK
#define SRC_SIMULATION_BLOCK

#include <map>
#include <vector>
#include <string>
#include "ConfigurationValue.h"
#include "IEventHandler.h"
#include "SampleTime.h"
#include <stdexcept>

namespace BlockTypes::BasicCpp
{
    template <typename T>
    class SimulationBlock
    {
        protected:
        std::shared_ptr<IEventHandler> eventHandler;
        public:
        SimulationBlock(std::map<std::string, BlockTypes::BasicCpp::ConfigurationValue> configurationValues, std::shared_ptr<IEventHandler> eventHandler) : eventHandler(eventHandler) {};
        virtual const std::shared_ptr<SampleTime> GetSampleTime() const = 0;
        virtual const int GetInputPortAmount() const = 0;
        virtual const int GetOutputPortAmount() const = 0;
        virtual const std::vector<bool> InputsHasDirectFeedthrough() const = 0;

        virtual std::vector<T> CalculateOutputs(const std::vector<T> inputs, std::shared_ptr<SampleTime> sampleTime, double currentTime, bool isMinorStep=false) = 0;

        virtual bool TryUpdateConfigurationValue(std::string keyName, ConfigurationValue value) {return false;}

        virtual const std::vector<std::pair<double, double>> GetEvents(const std::vector<T> inputs, const std::shared_ptr<BlockTypes::BasicCpp::SampleTime> sampleTime, double eventTime, std::vector<double> eventTimeStates, bool includeKnownEvents=false) const
        {
            return {};
        }

        virtual const std::vector<double> GetKnownEvents(const std::shared_ptr<BlockTypes::BasicCpp::SampleTime> resolvedSampleTime, double simulationStartTime, double simulationEndTime) const
        {
            return {};
        }
    };
} // namespace BlockTypes::BasicCpp


#endif /* SRC_SIMULATION_BLOCK */
