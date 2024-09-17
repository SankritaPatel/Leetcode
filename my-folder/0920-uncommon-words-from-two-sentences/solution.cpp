class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;

    // Function to split a sentence into words and update the count map
    auto splitAndCount = [&](const string& sentence) {
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            count[word]++;
        }
    };

    // Process both sentences
    splitAndCount(s1);
    splitAndCount(s2);

    // Collect uncommon words
    vector<string> result;
    for (const auto& entry : count) {
        if (entry.second == 1) {
            result.push_back(entry.first);
        }
    }

    return result;
    }
};
