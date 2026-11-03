#include <iostream>
#include "Order.hpp"
#include "OrderBook.hpp"
#include <cassert>


int main()
{
    OrderBook book;

    assert(book.get_best_bid()==0);
    assert(book.get_best_ask()==0);


    book.add_order(Order{34200000000000ULL, 1, 101, 100, 1005000, 1});
    book.add_order(Order{34200000000001ULL, 1, 102, 200, 1007500, 1});

    book.add_order(Order{34200000000002ULL, 1, 103, 150, 1012500, -1});
    book.add_order(Order{34200000000003ULL, 1, 104, 300, 1010000, -1});

    assert(book.get_best_bid()==1007500);
    assert(book.get_best_ask()==1010000);

    assert(book.orders.find(102)!=book.orders.end());
    assert(book.orders[102].price == 1007500);
    assert(book.orders[102].side == 1);
    assert(book.orders[102].iterator->size == 200);
    


    std::cout<<"Best Bid "<<book.get_best_bid()<<"\n";
    std::cout<<"Best Ask "<<book.get_best_ask()<<"\n";

}