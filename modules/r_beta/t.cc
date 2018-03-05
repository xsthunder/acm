// set_terminate example
#include <iostream>       // std::cerr
#include <exception>      // std::set_terminate
#include <cstdlib>        // std::abort

void myterminate () {
  std::cout << "terminate handler called\n";
  std::exit(1);
  abort();  // forces abnormal termination
}

int main (void) {
  std::set_terminate (myterminate);
  throw 5;  // unhandled exception: calls terminate handler
  return 2;
}
