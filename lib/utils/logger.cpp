#include "logger.hpp"

namespace log {

std::shared_ptr<Logger> Logger::_instance = nullptr;

void Logger::Debug(){}

void Logger::Info(){}

void Logger::Warn(){}

void Logger::Error(){}

void Logger::Fatal(){}

}