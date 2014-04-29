#ifndef _SOUNDEX_H_
#define _SOUNDEX_H_ 1

#include <string>
#include <unordered_map>

class Soundex
{
public:
    static const size_t MaxCodeLength{4};
    static const std::string NotADigit;

    Soundex() {};

    std::string Encode(const std::string &word) const {
        return ZeroPad(UpperFront(Head(word)) +Tail(EncodedDigits(word)));
    }

    std::string EncodedDigits(const std::string &word) const {
        std::string encoding;
        EncodeHead(encoding, word);
        EncodeTail(encoding, word);

        return encoding;
    }

private:
    std::string ZeroPad(const std::string &word) const {
        auto zeroNeeded = MaxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }

    std::string Head(const std::string &word) const {
        return word.substr(0, 1);
    }

    std::string Tail(const std::string &word) const {
        if (!word.empty())
            return word.substr(1);
        else
            return "";
    }

    char Lower(char letter) const {
        return std::tolower(letter);
    }

    bool IsComplete (const std::string &encoding) const {
        return encoding.length() == MaxCodeLength;
    }

    std::string LastDigit(const std::string &word) const {
        if (word.empty()) return "";
        return std::string(1, word.back());
    }

    std::string UpperFront(const std::string &word) const {
        return std::string(1, std::toupper(word.front()));
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

        auto it = encodings.find(tolower(letter));
        return it == encodings.end() ? NotADigit : it->second;
    }

    void EncodeHead(std::string &encoding, const std::string &word) const {
        encoding += EncodedDigit(word.front());
    }

    void EncodeTail(std::string &encoding, const std::string &word) const {
        for (auto i = 1u; i < word.size(); ++i) {
            if (!IsComplete(encoding))
                EncodeLetter(encoding, word[i], word[i - 1]);
        }
    }

    void EncodeLetter(std::string &encoding, char letter, char lastLetter) const {
        auto digit = EncodedDigit(letter);
        if (digit != NotADigit && (IsVowel(lastLetter) || digit != LastDigit(encoding)))
            encoding += digit;
    }

    bool IsVowel(char letter) const {
        return std::string("aeiouy").find(letter) != std::string::npos;
    }
};

const std::string Soundex::NotADigit{"*"};

#endif
