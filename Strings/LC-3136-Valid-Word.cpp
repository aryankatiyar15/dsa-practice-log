class Solution {
public:
    bool isValid(string word) {
        // If the word is less than 3 characters, it's automatically invalid
        if(word.size() < 3) {
            return false;
        }

        // Flags to check presence of vowel and consonant
        bool has_vowel = false;
        bool has_consonant = false;

        // 🔍 Go through each character in the word
        for(auto c : word) {
            if(isalpha(c)) { // Check if character is a letter
                c = tolower(c); // Convert to lowercase for consistent checking

                // Check if it's a vowel
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    has_vowel = true;
                } else { // Otherwise, it's a consonant
                    has_consonant = true;
                }
            } 
            else if (!isdigit(c)) { 
                // If character is neither a letter nor a digit, it's invalid
                return false;
            }
        }

        // The word is valid only if it has at least one vowel and one consonant
        return has_vowel && has_consonant;
    }
};
