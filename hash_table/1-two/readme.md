# Two Sum
- `auto a = {it->second, i};`
  - a has type `std::initializer_list<int> a`, which is interesting (I am not familiar with C++).
- auto is really convenient.
- Hash table can solve it in O(n) time complexity.
  - Iterate through the vector, and check if `target - nums[i]` is in the hash table.
  - Search in hash table `unordered_map` is of O(1) complexity.
  - [source](https://www.delftstack.com/howto/cpp/use-a-hashmap-in-cpp/)
