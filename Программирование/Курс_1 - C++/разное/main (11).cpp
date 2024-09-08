#include <iostream>

void findLongestIncreasingSequence(int nums[], int length) {
    int longestSequenceStart = 0;
    int longestSequenceLength = 1;
    int currentSequenceStart = 0;
    int currentSequenceLength = 1;

    for (int i = 1; i < length; ++i) {
        if (nums[i] >= nums[i - 1]) {
            currentSequenceLength++;
        } else {
            if (currentSequenceLength > longestSequenceLength) {
                longestSequenceStart = currentSequenceStart;
                longestSequenceLength = currentSequenceLength;
            }
            currentSequenceStart = i;
            currentSequenceLength = 1;
        }
    }

    // Check if the last sequence is the longest one
    if (currentSequenceLength > longestSequenceLength) {
        longestSequenceStart = currentSequenceStart;
        longestSequenceLength = currentSequenceLength;
    }

    std::cout << "Longest increasing sequence: ";
    for (int i = longestSequenceStart; i < longestSequenceStart + longestSequenceLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int sequence[] = {1, 2, 4, 6, 7, 4, 4, 6, 7, 5, 4, 6, 8, 9, 11, 12, 14};
    int length = sizeof(sequence) / sizeof(sequence[0]);

    findLongestIncreasingSequence(sequence, length);

    return 0;
}
