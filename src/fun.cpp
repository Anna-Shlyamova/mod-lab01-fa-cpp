// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
#include <cmath>

unsigned int faStr1(const char* str) {
    int count = 0;
    bool inWord = false;
    bool isNumberIn = false;
    while (*str) {
        if (!isspace(*str) && !inWord) {
            inWord = true;
            isNumberIn = false;
        } else if (isspace(*str) && inWord) {
            if (!isNumberIn) {
                count++;
            }
            inWord = false;
        } else if (isdigit(*str) && inWord) {
            isNumberIn = true;
        }
        str++;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    int count = 0;
    bool inWord = false;
    bool isLowerLetters = true;
    bool isFirstUpper = false;
    while (*str) {
        if (!isspace(*str) && !inWord) {
            if (isFirstUpper && isLowerLetters) {
                count++;
            }
            if (isupper(*str)) {
                isFirstUpper = true;
            }
            else isFirstUpper = false;

            inWord = true;
            isLowerLetters = true;
        } else if (isspace(*str) && inWord) {
            inWord = false;
        } else if (!islower(*str) && inWord) {
            isLowerLetters = false;
        }
        str++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    int wordLength = 0;
    int wordsCount = 0;
    bool inWord = false;
    bool isLowerLetters = true;
    bool isFirstUpper = false;
    while (*str) {
        if (!isspace(*str) && !inWord) {
            inWord = true;
            wordLength++;
            wordsCount++;
        } else if (isspace(*str) && inWord) {
            inWord = false;
        } else if (!isspace(*str) && inWord) {
            wordLength++;
        }
        str++;
    }

    return round(wordLength / wordsCount);
}
