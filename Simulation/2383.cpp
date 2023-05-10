#include "inc.h"

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int cnt = 0, n = experience.size();
        for (int i = 0; i < n;) {
            if (initialEnergy > energy[i] && initialExperience > experience[i]) {
                initialEnergy -= energy[i];
                initialExperience += experience[i];
                i++;
            } else {
                if (initialEnergy <= energy[i]) {
                    cnt += (energy[i] - initialEnergy + 1);
                    initialEnergy += (energy[i] - initialEnergy + 1);
                }
                if (initialExperience <= experience[i]) {
                    cnt += (experience[i] - initialExperience + 1);
                    initialExperience += (experience[i] - initialExperience + 1);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<int> energy{1,4,3,2}, experience{2,6,3,1};
    Solution sl;
    sl.minNumberOfHours(5, 3, energy, experience);
    return 0;
}