#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class bgp
{
public:
    bgp();
    bgp(int i, vector<int> nlist);
    int get_index() const;
    int get_size() const;
    vector<int> get_neibor() const;
    void print() const;
    void add_neibor(vector<int> s);             
    void sort_neibor();

private:
    int index;
    int neibor_size;
    vector<int> neibor_list;
};

