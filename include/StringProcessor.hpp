#pragma once

#ifndef __STRING_PROCESSOR_HPP__
#define __STRING_PROCESSOR_HPP__

#if defined UNICODE
#define tcout wcout
#define tcerr wcerr
#else
define tcout cout
#define tcerr cerr
#endif

#include <string>
using namespace std;

class StringProcessor
{
public:
  //unsafe
  static void errorOutA(const char* const err);
  static string toAnsi(const wstring& const wstr);
  static wstring toUnicode(const string& const str);
protected:
private:
};

#endif //!__STRING_PROCESSOR_HPP__