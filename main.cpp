#include <iostream>
#include "Order.hpp"



int main()
{
    Order order1 {1000000100000,2,10234522,100,100,-1};
    std::cout<<order1.price<<"\n";
    std::cout<<order1.is_filled()<<"\n";
}