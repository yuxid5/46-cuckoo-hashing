#ifndef __WORD_SET___HPP
#define __WORD_SET___HPP

#include <cstddef>
#include <string>

namespace shindler::ics46::project3 {

// You may assume, in writing this function, that the given
// string consists solely of lower-case letters.

// To get the "number" that a letter-digit represents,
// subtract 'a' from it.
// e.g., (s[0]-'a') is the most significant "digit" of s.
// That would give you a 0 for a, etc;  add one to get 'a' = 1, 'b' = 2, etc.

// After every "digit" is processed, mod the current value by mod.
// This will keep you from having overflow.
[[nodiscard]] size_t polynomialHashFunction(const std::string &string,
                                            unsigned base, unsigned mod);

// These are value template parameters. You can pass in a value rather than a
// type into the parameter and use its value. This allows them to be set
// dynamically rather than having static constants within the class.
// Think of them as class constants (you can just use them like a variables
// named H1, H2, and EvictThreshold)
template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
class BaseWordSet {
   private:
    // You may declare private functions and member variables here.
    size_t current_capacity;
    std::string* hashtable1;
    std::string* hashtable2;

   public:
    explicit BaseWordSet(size_t initialCapacity);
    ~BaseWordSet();

    // You do not need to worry about implementing these. They are only
    // here to ensure that we let the compiler know these functions
    // should not exist.
    BaseWordSet(const BaseWordSet &) = delete;
    BaseWordSet(BaseWordSet &&) = delete;
    BaseWordSet &operator=(const BaseWordSet &) = delete;
    BaseWordSet &operator=(BaseWordSet &&) = delete;

    // adds the given string to the WordSet, so that any
    // future calls to contains(s) will return true, unless that is later
    // removed.
    void insert(const std::string &string);

    [[nodiscard]] bool contains(const std::string &string) const;

    // return how many distinct strings are in the set
    [[nodiscard]] size_t size() const noexcept;

    // return how large the underlying array is.
    [[nodiscard]] size_t capacity() const noexcept;

    void erase(const std::string &string);
};

// You Should not use anything within the _impl namespace in your code.
// Instead reference the H1, H2, and EvictThreshold template parameters
namespace _impl {
const static unsigned int BASE_H1 = 37;
const static unsigned int BASE_H2 = 41;
const unsigned int BASE_EVICTION_THRESHOLD = 5;
}  // namespace _impl

// Add a usings statement with the default values for the project.
using WordSet =
    BaseWordSet<_impl::BASE_H1, _impl::BASE_H2, _impl::BASE_EVICTION_THRESHOLD>;

template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
BaseWordSet<H1, H2, EvictThreshold>::BaseWordSet(size_t initialCapacity):current_capacity{initialCapacity},
hashtable1{new std::string[initialCapacity]}, 
hashtable2{new std::string[initialCapacity]} {
    // TODO: Implement this
}

template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
BaseWordSet<H1, H2, EvictThreshold>::~BaseWordSet() {
    // TODO: Implement this
    delete[] hashtable1;
    delete[] hashtable2;
}

template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
void BaseWordSet<H1, H2, EvictThreshold>::insert(const std::string &string) {
    // TODO: Implement this
    unsigned position = polynomialHashFunction(string, H1, current_capacity);
    unsigned evict_times = 
    while()
    if (!hashtable1[position].empty()){
        hashtable1[position] = string;
    }
    else{
        unsigned position2 = polynomialHashFunction(hashtable1[position], H2, current_capacity)
        if (!hashtable2[position2].empty()){
            hashtable2[position2]
        }
    }
}

template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
bool BaseWordSet<H1, H2, EvictThreshold>::contains(
    const std::string &string) const {
    // TODO: Implement this. Stub is only to allow code to compile
    //       (you may remove it)
    for(unsigned i; i < current_capacity; ++i){
        std::string compare_str1 = hashtable1[i];
        std::string compare_str2 = hashtable2[i];
        if (string == compare_str1 || string == compare_str2){
            return true;
        }
    }
    return false;
}

// return how many distinct strings are in the set
template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
size_t BaseWordSet<H1, H2, EvictThreshold>::size() const noexcept {
    // TODO: Implement this. Stub is only to allow code to compile
    //       (you may remove it)
    return {};
}

// return how large the underlying array is.
template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
size_t BaseWordSet<H1, H2, EvictThreshold>::capacity() const noexcept {
    // TODO: Implement this. Stub is only to allow code to compile
    //       (you may remove it)
    return {};
}

// removes this word if it is in the wordset.
template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
void BaseWordSet<H1, H2, EvictThreshold>::erase(const std::string &string) {
    // TODO: Implement this.
}

}  // namespace shindler::ics46::project3

#endif
