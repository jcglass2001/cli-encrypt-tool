#pragma once
#include <iostream>

class ParserBase
{
    public :
        virtual ~ParserBase();
        virtual bool load(const std::string& configFilePath)=0;
        virtual bool getValue(const std::string& key)=0;
        
};