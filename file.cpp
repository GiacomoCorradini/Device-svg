#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>
 
using namespace std;
 
int main() {
 
 // Create and open a text file
 ofstream MyFile("filename.svg");
 
 string string_to_write = "Files can be tricky, but it is fun enough!";
 
 // Write to the file
 MyFile << string_to_write;
 
 // Close the file
 MyFile.close();
 
 
 // Read from file
 std::ifstream t("filename.svg");
 std::stringstream buffer;
 buffer << t.rdbuf();
 string s = buffer.str();
 
 cout << "I read this" << endl;
 cout << s << endl;
 
 
 return 0;
}
