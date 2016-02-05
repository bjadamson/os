#include <iostream>
#include <boost/hana.hpp>

struct Mittsy { int j; };
struct Moaney { short p; };
struct Samantha { std::string st; };
struct Benjamin { char b; };

using namespace boost;

int
main(int main, char **argv)
{
  auto us = hana::make_tuple(Mittsy{3}, Moaney{25}, Samantha{"l"}, Benjamin{'D'});
  return 0;
}
