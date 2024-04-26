# Valid Anagram
- Use unorder\_map to store (char, count) pairs.
- Iterate through 2 strings.
  - Get the (char, count) pairs representing the number of char occurence in first string.
  - When encoutering the char in string No. 2, find the count using the key (char).
    - If the key does not exist, return false.

