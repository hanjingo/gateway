#pragma once

#include <config.hpp>
#include <interface.hpp>

namespace gateway{

class StreamPlayerV1 : public StreamPlayerI
{
public:
    StreamPlayerV1(){};
    ~StreamPlayerV1(){};

    void Play(err::Error &e);
};

}