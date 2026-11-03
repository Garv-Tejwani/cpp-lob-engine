#pragma once 
#include <cstdint>
#include "Order.hpp"
#include <map>
#include <unordered_map>
#include <list>
using orderiter = std::list<Order>::iterator;

struct OrderLocation
{
    int8_t side;
    int64_t price;
   
    orderiter iterator;
};



struct OrderBook
{
    std::map<int64_t, std::list<Order>> asks;
    std::map<int64_t, std::list<Order>, std::greater<int64_t>> bids;
    std::unordered_map<uint64_t , OrderLocation> orders;



    int64_t get_best_bid() const
    {
        return bids.empty()? 0 : bids.begin()->first;

    }

    int64_t get_best_ask() const
    {
        return asks.empty()?0: asks.begin()->first;
        
    }


    void add_order(const Order& order)
    {
        orderiter it;
        if (order.direction==1)
        {
            bids[order.price].push_back(order);
            it = std::prev(bids[order.price].end());

        }
        else 
        {
            asks[order.price].push_back(order);
            it = std::prev(asks[order.price].end());
        }

        orders[order.order_id]  = {order.direction, order.price, it};


        

    }

};
