#include <algorithm>
#include "bgp.h"
using namespace std;

bgp::bgp():neibor_size(0),index(0)
{
}


bgp::bgp(int i, vector<int> nlist)
{
    index = i;
    neibor_size = nlist.size();
    neibor_list = nlist;
}

int bgp::get_index() const
{
    return index;
}

int bgp::get_size() const
{
    return neibor_size;
}

vector<int> bgp::get_neibor() const
{
    return neibor_list;
}

void bgp::print() const
{
    cout << index <<" "<< neibor_size << "\n";
    for (int i=0;i<neibor_size-1;i++)
    {
    cout << neibor_list[i]<<"|";
    }
    cout << neibor_list[neibor_size-1]<<"\n";
}

void bgp::sort_neibor()
{
    sort(neibor_list.begin(),neibor_list.end());
}

void bgp::add_neibor(vector<int> s)
{
    vector<int>::iterator it;
    for (int i=0;i<s.size();i++)
    {
        it =find(neibor_list.begin(),neibor_list.end(),s[i]);
        if (it==neibor_list.end())
         {
            neibor_list.push_back(s[i]);
            neibor_size+=1;
         }
     }
}

