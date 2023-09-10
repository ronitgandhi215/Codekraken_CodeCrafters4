#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

// Define a map of user prompts and corresponding bot responses
std::map<std::string, std::vector<std::string>> conversation = {
    {"hello", {"Hello!", "Hi there!", "Hey!"}},
    {"how are you", {"I'm good, thanks!", "I'm doing well, how about you?", "I'm great!"}},
    {"what's your name", {"I'm a user.", "I don't have a name. Call me user."}},
    {"bye", {"Goodbye!", "See you later!", "Bye! Have a great day!"}},
    {"what are you doing",{"eating","playing","sleeping"}},
    {"i am not feeling good today",{"should i call the doctor","dont worry i am with you take medicene on time "}},
    {"how's your day",{"fine day just going","very great how's your babe?"}},
    {"no",{"fine","leave it"}},
    {"mere babu ne thana thaya",{"haa babu kha liya","nahi babu nahi khaya "}},
    {"kidhar hai",{"ghar pe","family walo ke sath bhar hu"}},
    {"achaa",{"hmm"}},
    {"good night sooja",{"good night","thodi der aur baat kare"}},
    {"wow you are good singer",{"thank you :)"}},
    {"sing a song",{"tu mann meri baat","pehla nasha pehla khuma naya pyaar hai naya intezar"}}
};

// Function to generate a bot response
std::string generateResponse(const std::string& user_input) {
    std::string response = "I'm not sure how to respond to that.";

    for (const auto& entry : conversation) {
        if (user_input.find(entry.first) != std::string::npos) {
            const std::vector<std::string>& responses = entry.second;
            response = responses[rand() % responses.size()];
            break;
        }
    }

    return response;
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator

    std::cout << "user: Hello! How can I assist you today?" << std::endl;

    while (true) {
        std::string user_input;
        std::cout << "You: ";
        std::getline(std::cin, user_input);

        if (user_input == "bye") {
            std::cout << "user: Goodbye!" << std::endl;
            break;
        }

        std::string bot_response = generateResponse(user_input);
        std::cout << "user: " << bot_response << std::endl;
    }

    return 0;
}
