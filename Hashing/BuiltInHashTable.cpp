#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> ages;
    
    // Insert
    ages["Alice"] = 30;
    ages.insert({"Bob", 25});
    ages.emplace("Carol", 28);

    // Lookup
    cout << ages["Alice"] << endl;
    if(ages.find("Bob") != ages.end()){
        cout << "Bob Found: " << ages.at("Bob") << endl;
    }

    // Check Existence
    if(ages.contains("Carol"));

    // Erase
    ages.erase("Bob");

    // Iterate
    for(const auto& [name, age]: ages){
        cout << name << ": " << age << endl;
    }


    return 0;
}