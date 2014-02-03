#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>

using namespace std;

class tree {
public:
    tree() {}
    
    tree(istream& source) {
        string line;
        while (!source.eof()) {
            source >> line;
            addString(line);
        }
    }
    
    ~tree() {
// C++11 style
//        for (auto child: children) {
//            delete child.second;
//        }
// pre-C++11 style
        for (map<char, tree*>::iterator i=children.begin(); i!=children.end(); i++) {
            delete i->second;
        }
    }
    
    void addString(const string& str) {
        char index = str[0];
        if (str.length()==1) {
            leaves.insert(index);
        } else {
            if (!children[index]) children[index] = new tree();
            children[index]->addString(str.substr(1));
        }
    }
    
    bool exists(const string& str) {
        return leaves.find(str[0])!=leaves.end() ||
            (children[str[0]] && children[str[0]]->exists(str.substr(1)));
    }
    
private:
    set<char> leaves;
    map<char, tree*> children;
};



int main(int argc, const char * argv[])
{
    if (argc<2) {
        cout << "USAGE: tree <strings-dictionary.txt>" << endl;
        return 1;
    }
    
    ifstream haystack(argv[1]);
    tree t(haystack);
    string needle;

    cout << "String to search = ";
    cin >> needle;
    cout << (t.exists(needle) ? "Found in dictionary!" : "String not found in dictionary") << endl;
    
    return 0;
}

