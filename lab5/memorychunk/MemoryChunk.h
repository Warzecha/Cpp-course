//
// Created by damian on 27.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk
{
    class MemoryChunk {

    public:
        MemoryChunk(size_t sz);
        MemoryChunk(const MemoryChunk &other);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;

        virtual ~MemoryChunk();
        MemoryChunk &operator= (MemoryChunk &other);

        MemoryChunk(MemoryChunk &&other);

        MemoryChunk& operator=(MemoryChunk && other);



    private:

        int8_t * ptr;
        size_t size;

    };

}



#endif //JIMP_EXERCISES_MEMORYCHUNK_H
