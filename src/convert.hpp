#ifndef ___PROJECT_3_CONVERT_HPP
#define ___PROJECT_3_CONVERT_HPP

#include <istream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

#include "Wordset.hpp"

namespace shindler::ics46::project3 {

template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
[[nodiscard]] std::vector<std::string> convert(const std::string& start,
                                               const std::string& end,
                                               const BaseWordSet<H1, H2, EvictThreshold>& words) {
    // TODO: Implement this. The stub is only to allow the code to remove
    //       (you can remove it).
    std::vector<std::string> result;
    std::unordered_map<std::string, std::string> word_map;
    std::queue<std::string> frontQueue;
    bool found = false;
    frontQueue.push(start);
    while (!frontQueue.empty()&& !found){
        std::string current_word = frontQueue.front();
        frontQueue.pop();
        for (unsigned i{0}; i < current_word.size() && !found; i++){
            for (char letter = 'a'; letter<='z'; letter++){
                std::string temp_str = current_word;
                temp_str[i] = letter;
                if (words.contains(temp_str)){
                    if(word_map.find(temp_str) == word_map.end() && temp_str != start){
                        frontQueue.push(temp_str);
                        word_map[temp_str] = current_word;
                    }
                }
                if(temp_str == end){
                    found = true;
                    break;
                }
            }
        }
    }
    if (word_map.find(end) != word_map.end()){
        result.push_back(end);
        std::string add_to_vector = word_map[end];
        result.push_back(add_to_vector);
        while(add_to_vector != start){
            add_to_vector = word_map[add_to_vector];
            result.push_back(add_to_vector);
        }
        std::reverse(result.begin(), result.end());
    }
    return result;
}

// You should not need to change this function
template <unsigned int H1, unsigned int H2, unsigned int EvictThreshold>
void loadWordsIntoTable(std::istream& istream,
                        BaseWordSet<H1, H2, EvictThreshold>& words) {
    std::string word;

    while (istream >> word) {
        words.insert(word);
    }
}

}  // namespace shindler::ics46::project3

#endif
