#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> map_int_int; //key : integer, value integer;
    map<int,string> map_int_string; //key : integer, value string;
    map<string,int> map_string_int; //key : string, value integer;

    for (int i = 1 ; i <= 5 ; i++)
    {
        map_int_int[i] = i * 5; // (key,value) = (1,5) , (2,10) , (3,15) , (4,20) , (5,25)
    }

    map_int_string[1] = "satu";
    map_int_string[2] = "dua";
    map_int_string[3] = "tiga"; // (key,value) = (1,"satu") , (2,"dua") , (3,"tiga")

    for (map<int,string>::iterator it = map_int_string.begin() ; it != map_int_string.end() ; ++it) // mengiterasi semua isi dari map_int_string
    {
        pair<int,string> cur = *it;
        map_string_int[cur.second] = cur.first; //(key,value) = ("satu",1) , ("dua",2) , ("tiga",3)
    }    

    cout << "ukuran map_int_string : " << map_int_string.size() << endl;
    map_int_string.clear();
    cout << "ukuran map_int_string setelah diclear : " << map_int_string.size() << endl;

    for (int i = 1 ; i <= 7 ; i++)
    {
        if (map_int_int.count(i))
            cout << "elemen dengan key " << i << " ada di dalam map" << endl;
        else
            cout << "elemen dengan key " << i << " tidak ada di dalam map" << endl; 
    }
}