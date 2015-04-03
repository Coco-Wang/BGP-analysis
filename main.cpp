#include "bgp.h"

using namespace std;

    vector<string>& split(const string& s, char delim,
                      vector<string>& subset);
    vector<string>& filter(vector<string>& data);
    vector<int> neibor_finder (int target,const vector<int>& vec);
    void print(const vector<int>& vec);
    vector<bgp>& obj_build (vector<bgp>& obj_lib,vector<int>& index_list,
                        const vector<int>& final_data);
    vector<int> convert (vector<string> data);
    bool sort_obj(bgp i, bgp j);

int main()
{
    string input;
    vector<string> subset;
    vector<string> target;
    vector<int> final_data;
    vector<bgp> obj_lib;
    vector<int> index_list;

    while (getline(cin,input))
    {
        if (input.empty())
            break;
        split(input,'|',subset);
        split(subset[6],' ',target);
        filter(target);
        final_data = convert(target);
        obj_lib=obj_build(obj_lib,index_list,final_data);
        subset.clear();
        target.clear();
    }
        sort(obj_lib.begin(),obj_lib.end(),sort_obj);
        for (int i=0;i<obj_lib.size();i++)
             { obj_lib[i].sort_neibor();
               obj_lib[i].print();}
        return 0;
}

vector<string>& split(const string& s, char delim,
                      vector<string>& subset)
{
     stringstream iss(s);
     string set;
     while (getline(iss,set,delim))
         subset.push_back(set);
     return subset;
}

vector<string>& filter(vector<string>& data)
{
   for(int i=0;i<data.size();i++)
    {
       if(data[i].find('[') !=string::npos)
            data.erase(data.begin()+i,data.end());
    }

    data.erase(unique(data.begin(),data.end()),data.end());
    return data;
}

vector<string>& filter(vector<string>& data)
{
   for(int i=0;i<data.size();i++)
    {
       if(data[i].find('[') !=string::npos)
            data.erase(data.begin()+i,data.end());
    }

    data.erase(unique(data.begin(),data.end()),data.end());
    return data;
}

vector<int> convert (vector<string> data)
{
    vector<int> temp;
    int x;
    for(int i=0;i<data.size();i++)
    {
        stringstream ss(data[i]);
        ss >> x;
        temp.push_back(x);
    }
    return temp;
}


vector<int> neibor_finder (int target,const vector<int>& vec)
{
    vector<int> temp;
    if (target==vec[0] && target!=vec[vec.size()-1])
        temp.push_back(vec[1]);
    else if (target==vec[vec.size()-1] && target!=vec[0])
        temp.push_back(vec[vec.size()-2]);
    else
         {
        for (int i=0;i<vec.size();i++)
            if (target==vec[i])
              {
                temp.push_back(vec[i-1]);
                temp.push_back(vec[i+1]);
              }
          }
    return temp;
}

void print(const vector<int>& vec)
{
    for (int i =0;i< vec.size();i++)
         cout << vec[i] << endl;

}



vector<bgp>& obj_build (vector<bgp>& obj_lib,vector<int>& index_list,const vector<int>& final_data)
{
    vector<int> nbor;
    vector<int>::iterator it;
    for (int i=0;i<final_data.size();i++)
       {
         nbor=neibor_finder(final_data[i],final_data);
         bgp obj(final_data[i],nbor);
         it=find(index_list.begin(),index_list.end(),final_data[i]);
         if(it==index_list.end())
            { obj_lib.push_back(obj); index_list.push_back(final_data[i]);}
         else
            { for (int j=0;j<obj_lib.size();j++)
                 {if ((*it)==obj_lib[j].get_index())
                      obj_lib[j].add_neibor(nbor);}
             }
        }
     return obj_lib;
}


bool sort_obj(bgp i, bgp j)
{
if(i.get_size()==j.get_size())
     return (i.get_index()<j.get_index());
else
     return (i.get_size()>j.get_size());
}



















