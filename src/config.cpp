#include "config.hpp"

namespace gateway {
std::shared_ptr<Config> _instance = nullptr;

void Config::Load(err::Error &e, const std::string &path) {}

void Config::Reload(err::Error &e, const std::string &path) {}

}