4 Nov 2026 
- Added OrderBook.hpp
- Created the struct OrderBook to utilize how LOB data is actually treated.
- Created maps for bids and asks and stored it using the relation price : list(Orders), utilizing std:greater<> for descending bids.
- Created const read only funcitons get_best_bid() and get_best_ask() to get a peek at the top level data.
- Created add_order function to add an order in an order book.
- Created the struct OrderLocation as a helper to store the iterator / pointer everytime an order is stored in the bids/ask queue.
- Using unordered_map orders, you can get information on any specific order instantly (it's a hash lookup). The relation pair is order_id : OrderLocation.
- Modified main.cpp to include sample insertions and assert tests to check accuracy.
