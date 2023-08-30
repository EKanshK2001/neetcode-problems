/**
 * O(n) specifically O(m + n) m is the length of s string and n is of t.
 * 
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
 * If there is no such substring, return the empty string "".
 * 
 * link: https://leetcode.com/problems/minimum-window-substring/
 */

/**
 * @brief so this problem is my first hard problem, and took me quite a while to get (i don't even know if i got it all or not) so ill try to explain it a little.
 * 
 * we are given the two strings so, first we perform basic checks like if s is lower length than t then its not even possible etc etc.
 * 
 * now like all the substring and sliding window combo problems, we will be maintaining the substring validity using a map. 
 * but we need another map to maintain the frequency of t string as well, which we will often use to compare to.
 * 
 * A VALID SUBSTRING : WHEN WE HAVE ALL THE CHARACTERS WE NEED, from the t string in the s substring. (i.e. have == need)
 * 
 * now we are to maintain two checks that decides if we are on a valid string or not and even after we get it can we shrink it with it still being valid.
 * 
 * the (1st) first check we have to do is to maintain how many elements are done being the required frequency as in the tstring.
 *      - this we do using the have and need variables, which we update when the requirement is fulfilled later.
 * 
 * the (2nd) second validity check is kind of a subset of the first, when we have to check if we have reached a required frequency of a certain character (with it being a tstring character as well).
 *      - for this we have the two maps that we use when we add encounter a new character, we add it into the map window and also check if its valid and if it has reached the threshold frequency
 *          - if yes, we increment have. if not, we keep adding.
 * 
 * before we actually start the loop tho, we have to maintain the limits of a valid substring in a result (that we can refer later to make our resultant string)
 *      - we need an array to store the l index and r index, with a length storer (this will determine if we found a shorter substring or no substring at all).
 * 
 * now when we start iterating the s string (to find substrings), we do these two things:
 *      - add the new element in the map or increase its count i.e. we have a bigger substring.
 *          - we perform the 2nd validity check here
 *      
 *      - otherwise when we have encountered a new (shorter) valid substring (when we 'have' all the characters we 'need')
 *          - we update the resLen and store the indices in the result array to store the indices.
 *          - then we push the l further so as to shrink the substring while its a valid string.
 *              - to shrink we need to update the map as well and not just increment l.
 *                  - here we also have to check the 2nd validity and update the 'have' in case it breaks being a valid substring.
 *              - whenever it breaks being a valid string, the r pointer starts going further again.
 * 
 * now after the loop ends we either have a valid substring stored and that too the minimum one, with the index in res array and its length in resLen array.
 * if we never found one, then resLen should still be the default one i.e. INT_MAX.
 * that means we return the substring calculated from the indices (in res array) or we return empty string ("") otherwise.
 * 
 * sorry for the big ass explanation i needed to clear it out myself as well. hopefully we understand it better and faster with time.
 */

class Solution {
public:
    string minWindow(string s, string t) {

        if (s.length() < t.length() || t.length() == 0) {
            return "";
        }

        //maintain a map for a t string
        unordered_map <char, int> tstring;
        unordered_map <char, int> window;

        for (auto &ch : t) {
            tstring[ch]++;
        }


        //maintain a have and need variable to check if a substring is valid or not
        int have = 0, need = tstring.size();


        //make results to store or refer from
        int res[2] = {-1, -1}, resLen = INT_MAX;
        int l = 0, r = 0;


        //iterate the s string now with r
        for (r = 0; r < s.length(); r++) {
            
            //while adding new characters with r, we check if we increased our 'have' counter
            char c = s[r];
            window[c]++;
                //we make sure we have a valid character we need and if it's count is now matching to how many we need.
            if (tstring.find(c) != tstring.end() && tstring[c] == window[c]) {
                have++;
            }

            //eventually we match or have all the characters we needed
            while (have == need) {
                //update our result whenever we find a shorter substring
                if ((r - l + 1) < resLen) {
                    res[0] = l;
                    res[1] = r;
                    resLen = r - l + 1;
                }

                //pop from the left and check if it was a need character and if it made the have != need now
                //if so we update the have
                window[s[l]]--;
                if (tstring.find(s[l]) != tstring.end() && window[s[l]] < tstring[s[l]]) {
                    have--;
                }

                //if not then we keep pushing from left
                l++;
            }
        }

        //after we have ended exhausted the s string characters,
        //we should now be left with a valid range of l and r or a non valid one.
        if (resLen != INT_MAX) {
            return s.substr(res[0], res[1] - res[0] + 1);
        }
        else {
            return "";
        }
    }
};
