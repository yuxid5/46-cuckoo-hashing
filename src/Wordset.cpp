#include "Wordset.hpp"

#include <string>

namespace shindler::ics46::project3 {

// returns s, as a number in the given base, mod the given modulus
size_t polynomialHashFunction(const std::string &string, unsigned int base,
                              unsigned int mod) {
    // TODO: Implement this. You may remove the stub (it is only here
    //       to allow it to compile).
    unsigned index = 0;
    for(char letter : string){
        unsigned letter_int = letter - 'a' + 1;
        index = (index * base + letter) % mod;
    }
    return index;
}

}  // namespace shindler::ics46::project3
