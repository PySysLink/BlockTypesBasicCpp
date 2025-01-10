#ifndef SRC_IEVENT_HANDLER
#define SRC_IEVENT_HANDLER

#include <string>
#include "FullySupportedSignalValue.h"

namespace BlockTypes::BasicCpp
{
    class IEventHandler
    {
        public:
        virtual void NotifyNewValueEvent(double simulationTime, std::string valueId, FullySupportedSignalValue value) = 0;
    };
}

#endif /* SRC_IEVENT_HANDLER */
