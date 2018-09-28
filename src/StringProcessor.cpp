#include <StringProcessor.hpp>
#include <string>
#include <exception>
#include <utility>
#include <Windows.h>
#include <stdio.h>

using namespace std;

string StringProcessor::toAnsi(const wstring& const wstr)
{
  const size_t ansi_len = wstr.length() + 1;
  PCHAR buf = (PCHAR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, ansi_len * sizeof(CHAR));
  if (buf == NULL)
    return string();
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
    HeapFree(GetProcessHeap(), NULL, buf);
    buf = nullptr;
    return string();
  }
  string ansiString(buf);
  HeapFree(GetProcessHeap(), NULL, buf);
  buf = nullptr;
  return ansiString;
}


void StringProcessor::errorOutA(const char* err)
{
  size_t len = strlen(err);
  fwrite(err, sizeof(char), len, stderr);
}

wstring StringProcessor::toUnicode(const string& const str)
{
  const size_t uc_len = str.length() + 1;
  //PWCHAR buf = new WCHAR[uc_len];
  //SecureZeroMemory(buf, uc_len*sizeof(WCHAR));
  PWCHAR buf = (PWCHAR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, uc_len * sizeof(WCHAR));
  if (buf == NULL)
    return wstring();
  int rv = MultiByteToWideChar(
    CP_ACP,
    NULL,
    str.c_str(),
    str.length(),
    buf,
    uc_len);

  if (0 == rv)
  {
    HeapFree(GetProcessHeap(), NULL, buf);
    buf = nullptr;
    return wstring();
  }

  wstring uc_string(buf);
  HeapFree(GetProcessHeap(), NULL, buf);
  buf = nullptr;
  return uc_string;
}