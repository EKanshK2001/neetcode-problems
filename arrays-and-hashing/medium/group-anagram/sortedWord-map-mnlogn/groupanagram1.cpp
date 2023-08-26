/**
 * O(m * nlogn) - m is length of array of words, n is the length of a word
 * 
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * link: https://leetcode.com/problems/group-anagrams/
*/

/**
 * @brief stores every word in an array against the key as its sorted version in a map.
 * this way every anagram is group together against its sorted version as the key.
 * 
 * later on we iterated the map to store every array (entry.second) in the result vector.
 */

class Solution {
public:

/*----sortedWord - map O(m*n)  m is length of array, n is word length-----*/
/*----much efficient idk why 20ms, 20mb----------*/

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramMap;


        //stores in sorted word to string vector type map
        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramMap[sortedWord].push_back(word);
        }

        //pushes the string vectors in result vector
        for (auto& entry : anagramMap) {
            result.push_back(entry.second);
        }

        return result;
    }
};