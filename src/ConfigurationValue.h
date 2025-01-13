#ifndef SRC_BASIC_CPP_CONFIGURATION_VALUE
#define SRC_BASIC_CPP_CONFIGURATION_VALUE


#include <string>
#include <variant>
#include <vector>
#include <memory>
#include <map>
#include <stdexcept>
#include <complex>

namespace BlockTypes::BasicCpp
{
    using ConfigurationValuePrimitive  = std::variant<
        int,
        double,
        bool,
        std::complex<double>,
        std::string,
        std::vector<int>,
        std::vector<double>,
        std::vector<bool>,
        std::vector<std::complex<double>>,
        std::vector<std::string>>;
    
    using ConfigurationValue = std::variant<
        int,
        double,
        bool,
        std::complex<double>,
        std::string,
        std::vector<int>,
        std::vector<double>,
        std::vector<bool>,
        std::vector<std::complex<double>>,
        std::vector<std::string>,
        ConfigurationValuePrimitive,
        std::vector<ConfigurationValuePrimitive>>;

    class ConfigurationValueManager
    {
        public:
        template <typename T> 
        static T TryGetConfigurationValue(std::string keyName, std::map<std::string, ConfigurationValue> configurationValues)
        {
            ConfigurationValue findedValue;
            auto it = configurationValues.find(keyName);
            if (it == configurationValues.end()) {
                throw std::invalid_argument("Key name: " + keyName + " not found in configuration.");
            } else {
                findedValue = it->second;
            }
            try
            {
                return std::get<T>(findedValue);
            }
            catch (std::bad_variant_access const& ex)
            {
                throw std::invalid_argument("Configuration option of key: " + keyName + " was not of expected type: " + ex.what());
            }
        }
    };
    
} // namespace BlockTypes::BasicCpp



#endif /* SRC_BASIC_CPP_CONFIGURATION_VALUE */
