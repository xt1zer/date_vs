#include "String.h"
#include <iostream>

String::String() : m_len(0) {
    m_str = new char[0]; // it's empty, right?
}

String::String(const char str[]) : m_len(strlen(str)) {
    m_str = new char[m_len + 1]; // '\0' char at the end
    copy(str, 0);
}

String::String(const String & copyStr) : m_len(copyStr.m_len) {
    m_str = new char[copyStr.m_len + 1];

    copy(copyStr.m_str, 0);
}

String::~String() {
    m_len = 0;

    delete[] m_str;
    m_str = nullptr;
}

const bool String::operator==(const String & rhs) {
    int i(0);

    while (i < m_len - 1 && i < rhs.m_len - 1) {
        if (m_str[i] != rhs.m_str[i]) // if any char mismatches then knock if off
            return false;

        ++i;
    }

    if (m_len != rhs.m_len) // if strings match, but lengths unequal
        return false;

    return true;
}

void String::copy(const char s[], const size_t & pos) {
    if (m_len - pos < strlen(s)) // length overflow
        return;

    for (size_t i(pos); i <= m_len; ++i)
        m_str[i] = s[i - pos];
}

String* String::divide(const char delim[], const size_t & count) const {
    char src[m_len + 1];
    strcpy(src, m_str);

    String * words = new String[count];

    // all part until [for] is needed for first word until delimeter
    
    char * token = strtok(src, delim);
    delete[] words[0].m_str;
    words[0].m_len = strlen(token);
    words[0].m_str = new char[words[0].m_len + 1];
    strcpy(words[0].m_str, token);

    for(size_t i(1); i < count; ++i){
        delete[] words[i].m_str;

        token = strtok(NULL, delim);
        words[i].m_len = strlen(token);
        words[i].m_str = new char[words[i].m_len + 1];
        strcpy(words[i].m_str, token);
    }

    return words;
}

const size_t String::length() const {
    return m_len;
}

void String::print() const {
    std::cout << m_str;
}

void String::append(const char s[]) {
    char oldStr[m_len + 1];
    strcpy(oldStr, m_str);

    delete[] m_str;

    m_len += strlen(s);

    m_str = new char[m_len + 1];
    copy(oldStr, 0);
    copy(s, m_len - strlen(s));
}

void String::append(const String & s) { // different parameter
    append(s.m_str);
}

String String::substr(const unsigned int & pos, const unsigned int & num) const {
    if (m_len - pos < num) // length overflow
        return String("");

    char res[num + 1];

    for (size_t i(0); i < num; ++i)
        res[i] = m_str[i + pos];

    return String(res);
}

String * String::split(const char & delim) const {
    if (strchr(m_str, delim)) {
        size_t count = 0;

        for (size_t i(0); i < m_len; ++i) {
            if (m_str[i] == delim)
                ++count;
        }

        const char delims[] = { delim, '\0' };
        return divide(delims, ++count);
    }
}

void String::replace(const char from[], const char to[]) {
    char * str = strstr(m_str, from);

    if (strstr(m_str, from)) { // hell of a job
        char afterStr[strlen(str) - strlen(from) + 1];
        strcpy(afterStr, &str[strlen(from)]);

        char beforeStr[m_len - strlen(str) + 1];
        strncpy(beforeStr, m_str, m_len - strlen(str));
        beforeStr[m_len - strlen(str)] = '\0';

        size_t beforeInd = strlen(beforeStr);
        size_t afterInd = strlen(beforeStr) + strlen(to);

        delete[] m_str;
        m_len = m_len - strlen(from) + strlen(to);
        m_str = new char[m_len + 1];

        copy(beforeStr, 0);
        copy(to, beforeInd);
        copy(afterStr, afterInd);
    }
}
