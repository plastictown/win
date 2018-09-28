#include <StringProcessor.hpp>
#include <string>
#include <exception>
#include <utility>
#include <Windows.h>
#include <stdio.h>

using namespace std;

string StringProcessor::toAnsi(const wstring& const wstr)try
{
  const size_t ansi_len = wstr.length() + 1;
  PCHAR buf = new CHAR[ansi_len];
  SecureZeroMemory(buf, ansi_len);
  BOOL usedDefaultChar{ FALSE };

  int rv = WideCharToMultiByte(
    CP_ACP,
    WC_COMPOSITECHECK, 
    wstr.c_str(), 
    wstr.length(), 
    buf, 
    ansi_len, 
    NULL, 
    &usedDefaultChar);

  if (0 == rv)
  {
    delete[] buf;
    buf = nullptr;
    return string();
  }
  string ansiString(buf);
  delete[] buf;
  buf = nullptr;
  return ansiString;
}
catch (const std::exception& e)
{
  errorOutA(e.what());
  return string();
}

void StringProcessor::errorOutA(const char* err)
{
  size_t len = strlen(err);
  fwrite(err, sizeof(char), len, stderr);
}

wstring StringProcessor::toUnicode(const string& const str)try
{
  const size_t uc_len = str.length() + 1;
  PWCHAR buf = new WCHAR[uc_len];
  SecureZeroMemory(buf, uc_len*sizeof(WCHAR));

  int rv = MultiByteToWideChar(
    CP_ACP,
    NULL,
    str.c_str(),
    str.length(),
    buf,
    uc_len);

  if (0 == rv)
  {
    delete[] buf;
    buf = nullptr;
    return wstring();
  }

  wstring uc_string(buf);
  delete[] buf;
  buf = nullptr;
  return uc_string;
}
catch (const std::exception& e)
{
  errorOutA(e.what());
  return wstring();
}