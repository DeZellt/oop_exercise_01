#ifndef D_BITSTRING_H_
#define D_BITSTRIGN_H_ 1

#include <iostream>
#include <cstdint>

class bitstring {

private:
    uint32_t m_first;
    uint64_t m_second;
    void shiftLeftOne();
    void shiftRightOne();
    int32_t findOne() const;
    int32_t findTwo() const;
    int32_t length() const;

public:
    bitstring(uint32_t first=0, uint64_t second=0);
    bitstring And(const bitstring& r) const;
    bitstring Or(const bitstring& r) const;
    bitstring Xor(const bitstring& r) const;
    bitstring Not() const;
    void shiftLeft(int32_t i);
    void shiftRight(int32_t i);
    int32_t countone() const;
    bool equal(const bitstring& r) const;
    bool include(const bitstring& r) const;
    uint64_t getS() const;
    uint32_t getF() const;
    void print();
};

#endif