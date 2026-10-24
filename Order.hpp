#pragma once 
#include <cstdint>





struct Order
{
    uint64_t timestamp;
    uint8_t event;
    uint64_t order_id;
    uint32_t size;
    int64_t price;
    int8_t direction;

    void reduce(uint32_t given_sz)
    {
        if (given_sz>=size)
        {
            size=0;
        }
        else
        {
            size-=given_sz;
    
        }
    }
    
    bool is_filled() const{

        return (size==0);

    }

};