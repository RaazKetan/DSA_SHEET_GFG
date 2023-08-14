#include <iostream>
#include <vector>
#include <algorithm>

int maxMeetings(std::vector<int>& firstDay, std::vector<int>& lastDay) {
    int n = firstDay.size();
    std::vector<std::pair<int, int>> schedule;

    // Create a schedule by pairing lastDay and firstDay
    for (int i = 0; i < n; ++i) {
        schedule.push_back({lastDay[i], firstDay[i]});
    }

    // Sort the schedule by the last day of availability
    std::sort(schedule.begin(), schedule.end());

    int meetings = 0;
    int current_day = 0;

    // Iterate through the sorted schedule
    for (const auto& slot : schedule) {
        if (slot.second > current_day) {
            // Schedule a meeting if it doesn't conflict with the current schedule
            ++meetings;
            current_day = slot.first;
        }
    }

    return meetings;
}

int main() {
    // Example input
    std::vector<int> firstDay = {1, 2, 1, 2, 2};
    std::vector<int> lastDay = {3, 2, 1, 3, 3};

    // Calculate the maximum number of meetings that can be scheduled
    int maxScheduledMeetings = maxMeetings(firstDay, lastDay);

    // Display the result
    std::cout << "Maximum number of meetings the owner can schedule: " << maxScheduledMeetings << std::endl;

    return 0;
}
