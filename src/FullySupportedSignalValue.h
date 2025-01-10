#ifndef BASIC_CPP_SRC_FULLY_SUPPORTED_SIGNAL_VALUE
#define BASIC_CPP_SRC_FULLY_SUPPORTED_SIGNAL_VALUE



#include <string>
#include <variant>
#include <vector>
#include <memory>
#include <map>
#include <stdexcept>
#include <complex>

namespace BlockTypes::BasicCpp
{    
    using FullySupportedSignalValue = std::variant<
        int,
        double,
        bool,
        std::complex<double>,
        std::string>;


} // namespace BlockTypes::BasicCpp




#endif /* BASIC_CPP_SRC_FULLY_SUPPORTED_SIGNAL_VALUE */
