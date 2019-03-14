#pragma once
#include <cstring>

class String {

private:

    size_t m_len; // length of string
    char * m_str;

    void copy(const char * str, const size_t & pos); // copies all chars from [pos]
    String* divide(const char *, const size_t &) const; // for split() func

public:

    String();

    String(const char * str);

    String(const String & copy);

    ~String();


    const bool operator==(const String &);

    const size_t length() const;
    void print() const;

    void append(const String & str);
    void append(const char * str); // to end of string
    String substr(const unsigned int & pos, const unsigned int & num) const; // cuts [num] chars from [pos]
    String * split(const char & delim) const; // places strings to array
    void replace(const char * from, const char * to); // a substring to another one
};
