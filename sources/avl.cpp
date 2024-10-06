//
// Created by claud on 6/10/2024.
//

#include "avl.h"

inline string operator+(const string& str, const char* arr_char) {
    return str + string(arr_char);
}

inline string operator+(const char* arr_char, const string& str) {
    return string(arr_char) + str;
}

bool operator>(const string& str, const char* charArray) {
    return str > string(charArray);
}
bool operator<(const string& str, const char* charArray) {
    return str < string(charArray);
}


template<class T>
string concatenate(T char1, const char* arr_char2) {
    if constexpr (is_same<T, char*>::value) {
        return char1 + string(arr_char2);
    }
    else if constexpr (is_same<T, int>::value) {
        return to_string(char1) + string(arr_char2);
    }
    else if constexpr (is_same<T, float>::value) {
        return to_string(char1) + string(arr_char2);
    }

    else if constexpr (is_same<T, string>::value) {
        return char1+string(arr_char2);
    }
    else {
        throw std::invalid_argument("Tipo no soportado");
    }
}

template<class T>
string convertToString (T input) {
    if constexpr (is_same<T, int>::value) {
        return to_string(input);
    }
    else if constexpr (is_same<T, string>::value) {
        return input;
    }
    else {
        throw std::invalid_argument("Tipo no soportado");
    }
}

template<class T>
T convert (string input) {
    if constexpr (is_same<T, int>::value) {
        return atoi(input.c_str());
    }
    else if constexpr (is_same<T, string>::value) {
        return string(input);
    }
    else {
        throw std::invalid_argument("Tipo no soportado");
    }
}

template<class R, class T>
long getPosFisical(long pos) {
    return pos*sizeof(NodeAVL<R,T>)+HEAD_FILE;
}