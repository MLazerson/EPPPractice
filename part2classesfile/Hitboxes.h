#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
// Vectors will be used here to store file data, and then to search for specific.
// The vectors will be of the appropriate datatype, in the new c++11 style.
// There will be the use of built in functions.
// For loops and while loops will be used for the vectors and files, respectively.
// Shortcut calculations may be used, to be more efficient.
class Hitboxes {
//private variables to read file info into
private:
//variables to read into
std::string name;
std::string type;
int len, wdt; // temporary for hitSize vector
// vectors for categories
std::vector<std::string> names;
std::vector<std::string> types;
// dropped in favor of overall hitbox size
std::vector<int> hitSize;
public:
  // default constr
   Hitboxes(){}
   Hitboxes(const std::string& filename){
     int temp;// to store hitSize total
     // for file reading
     std::ifstream infile;
     infile.open(filename);
     // if file is open
     if (infile.is_open()) {
      // while reading is possible, not end of file
      while (infile >> name >> type >> len >> wdt) {
      // add to vectors
      names.push_back(name);
      types.push_back(type);
      // calculaute len adn wdt, then add this new number to hitSize vector
      // a large hitbox = larger numbers
      temp = len * wdt;
      hitSize.push_back(temp);
     }
    }
   }
// setters and getters, good practice just in case
void set_name(std::string n) { name = n; }
std::string get_name() { return name;}
void set_type(std::string t) {type = t;}
std::string get_type() {return type;}
void set_len(int l) {len = l;}
int get_len() {return len;}
void set_wdt(int w) {wdt = w;}
int get_widt() {return wdt;}

//member functions
// Find the smallest type of character
std::string smallestType() {
  // for apex.txt
  int sc, df, sld = 0;
  // loop through vector "type"
  for (int i = 0; i < types.size(); i++) {
    //count how many of scout, defense, Soldier
      if (types.at(i) == "Scout") {
        sc++;
      } else if (types.at(i) == "Defense") {
        df++;
      } else {
        sld++;
      }
  }
  // compare for smallest
  if (sc < df) {
    if (sc < sld) {
      return "Scout";
    }
  }
  if (df < sc) {
    if (df < sld) {
      return "Defense";
    }
  }
  // if scout and defense not smallest, return solider
  return "Soldier";
}
//  Find the smallest character based on hitbox size
std::string smallestCharacter() {
  // works for all files
  int smallestIndex = 0;
  int min = hitSize.at(0); // start with 1st element
  // loop
  for (int i=1; i < hitSize.size(); i++) {
    // if element i is < the min value, it is the new smallest
      if (hitSize.at(i) < min) {
        smallestIndex = i;
      }
  }
// return name at smallest index
return names.at(smallestIndex);
}
// end of file
};
