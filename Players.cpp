class Solution {
    #define ll long long
public:
    long long dividePlayers(vector<int>& skill) {
        ll n = skill.size();                        // Total number of players
        ll sum = 0;                                 // To store sum of all skills
        unordered_map<ll,ll> skillFreq;             // K->skill, V->frequency of each skill

        // Loop to calculate total skill sum and populate skill frequency map
        for(ll i = 0; i < n; ++i) {
            sum += skill[i];                        // Add skill of each player to sum
            skillFreq[skill[i]]++;                  // Increment frequency of the current skill
        }

        ll teams = n / 2;                           // Number of teams that need to be formed
        if(sum % teams != 0)                        // If the sum can't be evenly divided among teams
            return -1;                              // Return -1, as it's not possible to divide players

        ll target = sum / teams;                    // Target combined skill for each team
        ll chemistry = 0;                           // Variable to store total team chemistry

        // Loop through each skill and its frequency in the map
        for(auto [skill, freq] : skillFreq) {
            // Check if there's a complementary skill to form a team with target skill and if their frequencies match
            if(!skillFreq.count(target - skill) || freq != skillFreq[target - skill])
                return -1;                          // Return -1 if the pair doesn't exist or frequencies don't match

            // Add to chemistry based on the product of skill, complementary skill, and their frequency
            chemistry += skill * (target - skill) * freq;
        }

        return chemistry / 2;                       // Return half the total chemistry as each pair is counted twice
    }
};
