/**
 * O(m * n) - m is length of array of words, n is the length of a word
 * 
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * link: https://leetcode.com/problems/group-anagrams/
*/

/**
 * @brief we almost do the same thing but instead of storing the key as the word's sorted version, we make a special key of its hash table.
 * the hash function is another private function we make and use it to make a key for every word. 
 * if we encounter an anagram for a word, we get the same key, hence we are able to store every anagram against the same key.
 * 
 * again later on we store every array of anagram in the map in the result vector.
 */

class Solution {
public:

/*----hash table to string key - map O(m*n)  m is length of array, n is word length-----*/
/*----106mb, 27mb-----*/

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map <string, vector<string>> count;

        //iterate strs array to put every word against its key in the map
        for (int i = 0; i < strs.size(); i++) {
            //gets key as the hash table string
            string key = getKey(strs[i]);

            //push the word as value in map
            count[key].push_back(strs[i]); 
        }

        vector<vector<string>> result;

        //push string vectors in result vector
        for (auto& entry : count) {
            result.push_back(entry.second);
        }

        return result;

    }

private :

    //generate strings as key from the hash function
    string getKey(string word) {
        int arr[26] = {0};

        for (int i = 0; i < word.length(); i++) {
            arr[word[i] - 'a']++;
        }

        string key = "";
        
        //we need to use # or any other character as separator in key formulation because of reason i dont know yet. but we cant directly use the hashed array as (string) key as its raising errors.
        for (int i = 0; i < 26; i++) {
            key.append(to_string(arr[i]) + '#');
        }
        return key;
    }

};