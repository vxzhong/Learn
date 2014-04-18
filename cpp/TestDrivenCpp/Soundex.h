#ifndef _SOUNDEX_H_
#define _SOUNDEX_H_ 1

#include <string>
#include <unordered_map>

class Soundex
{
public:
    static const size_t MaxCodeLength{4};

    Soundex() {};

    std::string Encode(const std::string &word) const {
        return ZeroPad(Head(word) + EncodedDigits(Tail(word)));
    }

private:
    std::string ZeroPad(const std::string &word) const {
        auto zeroNeeded = 4 - word.length();
        return word + std::string(zeroNeeded, '0');
    }

    std::string Head(const std::string &word) const {
        return word.substr(0, 1);
    }

    std::string Tail(const std::string &word) const {
        return word.substr(1);
    }

    std::string EncodedDigits(const std::string &word) const {
        std::string encoding;
        for (auto letter : word) {
            encoding += EncodedDigit(letter);

            if (IsComplete(encoding)) break;
        }
        return encoding;
    }

    bool IsComplete (const std::string& encoding) const {
        return encoding.length() == MaxCodeLength - 1; 
    }

    std::string EncodedDigit(char letter) const {
        const std::unordered_map<char, std::string>  encodings = {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"}
        };

        auto it = encodings.find(letter);
        return it == encodings.end() ? "" : it->second;
    }
};

#endif
