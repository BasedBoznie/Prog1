#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>




template<typename K, typename V>
void print(const std::map<K,V>& m) {
for(const auto& a : m) { //(std::pair<K,V>& a : m)
std::cout << a.first << '\t' << a.second << std::endl;
}
}

void read_map(std::map<std::string, int>& m){
std::string s;
int i = 0;

while(m.size() < 10){
std::cin >> s >> i;
m[s] = i; //ez is jó
//m.insert(std::make_pair(s,i)); //ez is jó
}
}

void mapsum(const std::map<std::string, int>& m) {
int sum = 0;
for(const auto& a : m) {
sum = sum+a.second;
}
std::cout << "\nA map <int> értékeinek összege: \n" << sum << std::endl;
}

int main()
try {

std::map<std::string, int> msi;

msi["a"] = 19;
msi["b"] = 24;
msi["c"] = 31;
msi["d"] = 47;
msi["e"] = 52;
msi["f"] = 68;
msi["g"] = 72;
msi["aa"] = 83;
msi["ar"] = 99;
msi["w"] = 10;

print(msi); //automatikusan rendezi kulcs alapján, jelenesetben ABC sorrend

msi.erase("a");

std::cout << "\nTörlés után\n";
print(msi);

msi.erase(msi.begin(),msi.end());
std::cout << "\nTeljes törlés után\n";
print(msi);

std::cout << "\n10 kulcs-érték pár\n";
read_map(msi);
std::cout << "\nA megadott map: \n";
print(msi);

mapsum(msi); //

std::map<int,std::string> mis;

for(const auto& a : msi){
mis[a.second] = a.first;
}
std::cout << "\nmis map: " << std::endl;
print(mis);


} catch (std::exception& e) {
std::cerr << "Exception: " << e.what() << '\n';
return 1;
} catch (...) {
std::cerr << "Exception" << '\n';
return 2;
}
