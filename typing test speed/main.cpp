#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Function to calculate typing speed (words per minute)
double calculateSpeed(int timeInSeconds, int wordCount)
{
    return (wordCount / (double)timeInSeconds) * 60;
}

// Function to calculate accuracy
double calculateAccuracy(const string &original, const string &userInput)
{
    int correctWords = 0;
    stringstream origStream(original), userStream(userInput);
    string origWord, userWord;

    while (origStream >> origWord && userStream >> userWord)
    {
        if (origWord == userWord)
        {
            correctWords++;
        }
    }
    stringstream tempStream(original);
    int totalWords = distance(istream_iterator<string>(tempStream), istream_iterator<string>());
    return (correctWords / (double)totalWords) * 100; // Accuracy as percentage
}

int main()
{
    vector<string> sentences = {
        "The quick brown fox jumps over the lazy dog",
        "A journey of a thousand miles begins with a single step",
        "To be or not to be that is the question",
        "All that glitters is not gold",
        "The pen is mightier than the sword",
        "When in Rome do as the Romans do",
        "A picture is worth a thousand words",
        "The early bird catches the worm",
        "The grass is always greener on the other side",
        "The squeaky wheel gets the grease",
        "The best things in life are free",
        "You can't judge a book by its cover",
    };

    srand(time(0));
    string sentence = sentences[rand() % sentences.size()]; // Randomly select a sentence
    string userInput;

    cout << "Typing Test!" << endl;
    cout << "Type the following sentence:" << endl;
    cout << "\"" << sentence << "\"" << endl;

    cout << "Press Enter when you are ready..." << endl;
    cin.get(); // Wait for user to press Enter

    auto start = high_resolution_clock::now(); // Start timing

    // Get user input
    cout << "Start typing: ";
    getline(cin, userInput);

    auto stop = high_resolution_clock::now(); // Stop timing
    auto duration = duration_cast<seconds>(stop - start);
    int timeInSeconds = duration.count();
    int wordCount = userInput.empty() ? 0 : std::count(userInput.begin(), userInput.end(), ' ') + 1;

    double speed = timeInSeconds == 0 ? 0 : calculateSpeed(timeInSeconds, wordCount);
    double accuracy = calculateAccuracy(sentence, userInput);

    cout << "Time taken: " << timeInSeconds << " seconds" << endl;
    cout << "Typing speed: " << speed << " words per minute" << endl;
    cout << "Accuracy: " << accuracy << "%" << endl;

    return 0;
}
