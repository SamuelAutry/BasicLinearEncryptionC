#include <iostream>
#include <string>
#include <vector>
using namespace std;

//vector split method
const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	return v;
}

//key tiling method
string tile(string key, string text)
{
    string tiledKey;
    int tLen = text.size(), kLen = key.size(), baseTile = tLen/kLen;
    for(int i = 0; i<baseTile; i++)
        tiledKey+=key;
    int complexTile = (tLen-(baseTile*kLen));
    string addon = key.substr(0,complexTile);
    tiledKey+=addon;
    return tiledKey; 
}

//encryption method
string en(string key, string text)
{
    string enText, tiledKey = tile(key,text);
    for(int i = 0; i<text.size();i++)
        enText+=to_string( ((int)text.at(i)) + ((int)(tiledKey.at(i))) )+"-";
    enText.at(enText.size()-1) = ' ';
    return enText;
}

//decryption method
string de(string key, string text)
{
    string deText,temptileval;
    vector<string> v{explode(text, '-')};
    for(int i = 0; i<v.size();i++)
        temptileval+="a";
    string tiledKey = tile(key,temptileval);
    for(int i = 0; i<v.size();i++)
        deText+=(char)(stoi(v[i]) - (char)tiledKey.at(i));
    return deText;
}

//main method
int main()
{
    //main loop
    bool run = true;
    while(run == true)
    {
        
        //init input values
        string uText, uKey, uChoice;

        //record user input
        cout<<"\n\n+--------+\n new form \n+--------+\n\ntext : ";
        getline(cin, uText);
        cout<<"key: "; 
        getline(cin, uKey);
        cout<<"encrypt or decrypt? (0/1): "; 
        getline(cin, uChoice);
        switch (stoi(uChoice))
        {
            case 0:
                cout<<"value: "+en(uKey, uText);
                break;
            case 1:
                cout<<"value: "+de(uKey, uText);
                break;
        }
    }
    return 0;
}