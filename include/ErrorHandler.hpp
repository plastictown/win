#pragma once
#ifndef __ERROR_HANDLER_HPP__
#define __ERROR_HANDLER_HPP__
#include <Windows.h>
#include <crtdbg.h>

typedef enum CrtReportType
{
  Warn    = _CRT_WARN,
  Error   = _CRT_ERROR,
  Assert  = _CRT_ASSERT
}crt_report_type_t;

typedef enum CrtReportMode
{
  None    = 0x0,
  File    = _CRTDBG_MODE_FILE,
  Debug   = _CRTDBG_MODE_DEBUG,
  Window  = _CRTDBG_MODE_WNDW
}crt_report_mode_t;

class ErrorHandler
{
public:
  static void setCrtReportMode(CrtReportType type, CrtReportMode mode);
  static void setConsoleReportMode();
protected:
private:
  static void commonErrorHandler(PCTSTR expression, PCTSTR function, PCTSTR file,
    unsigned int line, uintptr_t reserved);
};

#endif //!__ERROR_HANDLER_HPP__