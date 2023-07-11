// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#define PART_LENGTH 50

#include "MessageOperations.hh"

int main() {

try {
  sendMessage("../datasets/Inwokacja.txt",PART_LENGTH);
  reciveMessage("../datasets/InwokacjaCopy.txt");
}
catch (Exception& e) {
  std::cerr << "Error: " << e.getErrorMessage() << " Example 1" << std::endl;
  return 1;
}

try {
  sendMessage("../datasets/excelTest.xlsx",PART_LENGTH);
  reciveMessage("../datasets/excelCopy.xlsx");
}
catch (Exception& e) {
  std::cerr << "Error: " << e.getErrorMessage() << " Example 2" << std::endl;
  return 1;
}

try {
  sendMessage("../datasets/wordTest.docx",PART_LENGTH);
  reciveMessage("../datasets/wordCopy.docx");
}
catch (Exception& e) {
  std::cerr << "Error: " << e.getErrorMessage() << " Example 3" << std::endl;
  return 1;
}

return 0;
}
