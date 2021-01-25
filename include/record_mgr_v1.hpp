#pragma once

#include "interface.hpp"
#include "config.hpp"

namespace gateway{

class RecordMgrV1 : public RecordMgrI
{
public:
    RecordMgrV1(){};
    ~RecordMgrV1(){};

    void Init(err::Error &e);
    void Run(err::Error &e);
    void Close();
    void Add(err::Error &e, const FileInfo &f);
    void Get(err::Error &e, FileInfo &f);
};

}