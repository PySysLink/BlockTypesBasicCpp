#ifndef SRC_IEVENT_HANDLER
#define SRC_IEVENT_HANDLER

#include <string>
#include "ConfigurationValue.h"

namespace BlockTypes::BasicCpp
{
    class IEventHandler
    {
        public:
        virtual void NotifyNewValueEvent(double simulationTime, std::string valueId, ConfigurationValue value) = 0;
    };
}

#endif /* SRC_IEVENT_HANDLER */
