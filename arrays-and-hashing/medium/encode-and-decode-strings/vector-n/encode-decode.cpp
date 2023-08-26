/**
 * O(n) as even when there are nested loops no characters are repeated or looped over twice.
 * 
 * Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings. Please implement encode and decode
 * 
 * link: https://www.lintcode.com/problem/659/
 */

/**
 * @brief this is a design problem and we need to implement an encode function that encodes the trick to decode it in itself.
 * thus we just take the word length and a # sign in the beginning of every word before appending it to the main encoded string.
 * this way when we decode it, we reach to the # sign and take all the characters before it as the length of the word thats just after it.
 * 
 * technicalities:
 *  - we take two pointers essentially, to keep track of word length (if its 2 or 3 digits). i to j-1. (j is the # sign).
 *  - we convert the length to int using stoi function.
 *  - we take bits or pieces of strings using the .substr function, which takes the first number as index in string and next number as the length of characters after it to cut off.
 *  - the original word comes after # or j so j+1 to the length.
 *  - after this we need to make i shift after the word we found so j + 1 + length (the index right after the word)
 */

class Solution {
public:
    
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode (vector<string> &strs) {
        string encoded = "";
        while (auto &word : strs) {
            encoded.append(to_string(word.length()) + '#' + word);
        }

        return encoded;
    }


    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &strs) {
        vector<string> result;
        int i = 0, j;

        while (i < strs.length()){
            int j = i;
            while (j != '#') {
                j++;
            }
            int length = stoi(strs.substr(i, j - 1));
            string word = strs.substr(j + 1, length);
            result.push_back(word);
            i = j + 1 + length;
        }

        return result;
    }
};