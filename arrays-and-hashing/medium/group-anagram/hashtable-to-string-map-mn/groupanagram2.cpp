/*
O(m * n) - m is length of array of words, n is the length of a word
link - https://leetcode.com/problems/group-anagrams/

*/

class Solution {
public:

/*----hash table to string key - map O(m*n)  m is length of array, n is word length-----*/
/*----106mb, 27mb-----*/

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map <string, vector<string>> count;

        
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

        for (int i = 0; i < 26; i++) {
            key.append(to_string(arr[i] + 'a'));
        }
        return key;
    }

};