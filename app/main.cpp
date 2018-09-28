#include <cstdlib>
#include <string>
#include <iostream>
#include <tchar.h>
#include <locale>
#include <StringProcessor.hpp>
#include <ErrorHandler.hpp>

using namespace std;

int _tmain(int argc, TCHAR** argv)
{
  setlocale(LC_ALL, "rus");
  ErrorHandler::setConsoleReportMode();

  wstring wstr(L"Русский текст");
  //to ansi
  string ansi(StringProcessor::toAnsi(wstr));
  cout << "ansi len: " << ansi.length() << "; ansi string: " << ansi << endl;
  wstr.clear();
  //from ansi
  wstr.assign(StringProcessor::toUnicode(ansi));
  wcout << L"unicode len: " << wstr.length() << L"; unicode string: " << wstr << endl;
  cin.get();
  return EXIT_SUCCESS;
}