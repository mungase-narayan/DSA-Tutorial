#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    unordered_map<string, int> mapping;

    // cteate pair
    pair<string, int> p = make_pair("Narayan", 19);

    pair<string, int> q("Rushikesh", 23);

    pair<string, int> r;
    r.first = ("Hari");
    r.second = (21);

    // insertion
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    // second type of insertion
    mapping["Krish"] = 20;

    // Access
    cout << endl << "Access of Value From Key : " << mapping.at("Narayan") << endl;
    cout << "Access of Value From Key : " << mapping.at("Rushikesh") << endl;
    cout << "Access of Value From Key : " << mapping.at("Hari") << endl;
    cout<<endl;

    // Searching
    if (mapping.find("Narayan") != mapping.end()){
        cout << "Key Found" << endl;
    }
    else{
        cout << "Key Not Found" << endl;
    }

    cout << "Size of Map : " << mapping.size() << endl;

    return 0;
}