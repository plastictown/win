#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <ErrorHandler.hpp>
#include <StringProcessor.hpp>

using namespace std;

void ErrorHandler::commonErrorHandler(PCTSTR expression, PCTSTR function, PCTSTR file,
  unsigned int line, uintptr_t reserved)
{
  tcerr << "***---CRT error---***" << endl
    << "* message: " << expression << endl
    << "* function: " << function << endl
    << "* file: " << file << endl
    << "* line: " << line << endl
    << "* errno: " << errno << endl
    << "***---CRT error---***" << endl;
}

void ErrorHandler::setCrtReportMode(CrtReportType type, CrtReportMode mode)
{
  _CrtSetReportMode(type, mode);
}

void ErrorHandler::setConsoleReportMode()
{
  _set_invalid_parameter_handler(ErrorHandler::commonErrorHandler);
  setCrtReportMode(CrtReportType::Assert, CrtReportMode::None);
}