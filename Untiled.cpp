#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int getMaxPeopleLeftCount(const std::vector<int>& people, const std::vector<char>& status) {
    std::unordered_map<int, char> personStatus;
    int maxPeopleLeft = 0;
    int currentPeople = 0;

    std::vector<int> dp(people.size(), 0); // Dynamic programming array to store max people left at each step

    for (size_t i = 0; i < people.size(); ++i) {
        int person = people[i];
        char event = status[i];

        if (event == '+') {
            if (personStatus.find(person) == personStatus.end()) {
                personStatus[person] = event;
            } else {
                ++personStatus[person];
            }
            currentPeople += person;
        } else if (event == '-') {
            if (personStatus.find(person) == personStatus.end() || personStatus[person] == 0) {
                return -1;  // Invalid scenario
            } else {
                --personStatus[person];
                if (personStatus[person] == 0) {
                    personStatus.erase(person);
                }
                currentPeople -= person;
            }
        }

        dp[i] = currentPeople;
        maxPeopleLeft = std::max(maxPeopleLeft, dp[i]);
    }

    if (currentPeople < 0) {
        return -1;  // Invalid scenario
    }

    int countPeopleLeft = std::count(dp.begin(), dp.end(), maxPeopleLeft);
    return countPeopleLeft;
}

int main() {
    std::vector<int> people = {1, 2, 2, 3, 4};
    std::vector<char> status = {'+', '+', '-', '+', '+'};
    int peopleLeftCount = getMaxPeopleLeftCount(people, status);

    if (peopleLeftCount == -1) {
        std::cout << "Invalid scenario" << std::endl;
    } else {
        std::cout << "Count of people left: " << peopleLeftCount << std::endl;
    }

    return 0;
}
