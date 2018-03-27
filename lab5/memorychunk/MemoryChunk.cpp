//
// Created by damian on 27.03.18.
//

#include "MemoryChunk.h"


namespace memorychunk
{


    MemoryChunk::MemoryChunk(size_t sz) {

        size = sz;
        ptr = new int8_t[sz];


    }

    size_t MemoryChunk::ChunkSize() const {
        return size;
    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        return (ptr+offset);
    }

    MemoryChunk::~MemoryChunk() {
        delete[](ptr);

    }

    MemoryChunk::MemoryChunk(const MemoryChunk &other) {
        this->size = other.size;
        this->ptr = new int8_t[size];

        for (size_t i = 0; i < other.size; ++i) {
            *(this->MemoryAt(i)) = *(other.MemoryAt(i));

        }

    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &other) {

        if (this == &other) {
            return *this;
        }

        delete[] ptr;

        size = other.size;
        ptr = new int8_t[size];

        for (size_t i = 0; i < other.size; ++i) {
            *(this->MemoryAt(i)) = *(other.MemoryAt(i));

        }

        return *this;
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&other): ptr(other.ptr), size(other.size)
    {
        other.ptr = nullptr;
        other.size = 0;
    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&other)
    {
        if(this != &other)
        {
            delete[](this->ptr);
            //this->ptr = new int8_t [other.size];
            //std::copy(other.ptr,other.ptr+other.size,this->ptr);
            this->ptr = other.ptr;
            this->size = other.size;
            //delete[](other.ptr);
            other.ptr = nullptr;
            other.size = 0;
        }
        return *this;
    }



}