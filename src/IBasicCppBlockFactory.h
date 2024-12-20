#ifndef SRC_IBASIC_CPP_BLOCK_FACTORY
#define SRC_IBASIC_CPP_BLOCK_FACTORY

#include <memory>
#include "SimulationBlock.h"
#include <map>
#include "ConfigurationValue.h"
#include "IEventHandler.h"
#include <string>
#include <vector>

namespace BlockTypes::BasicCpp
{
   class IBasicCppBlockFactory {
      public:
         // virtual ~ISimulationBlockFactory() = default;
         virtual std::vector<std::string> GetSupportedBlockClasses() const = 0;
         virtual std::unique_ptr<BlockTypes::BasicCpp::SimulationBlock> CreateBlock(std::string blockClass, std::map<std::string, ConfigurationValue> blockConfiguration, std::shared_ptr<IEventHandler> eventHandler) = 0;
   };
}

#endif /* SRC_IBASIC_CPP_BLOCK_FACTORY */
