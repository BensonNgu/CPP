1. How to read in data from a file, line by line into my string variable

2. From a line of string, hpw to 'tokenize' (i.e. breakup the data into smaller token or smaller data items)

```c++
void readAndDisplay(string filename){
    ifstream inputFile;

    inputFile.open(filename.c_str());

    while(inputFile.good()){
        string aLine;
        getLine(inputFile, aLine);

        cout << "aLine:" << aLine << endl;
    }

    inputFile.close();
}
```

```c++
vector<string> splitString(string str, string delimiter){
    vector<string> result;

    size_t pos = 0;
    string token;

    while((pos=str.find(delimiter))!= std::string::npos){
        token = str.substr(0,pos);
        result.push_back(token);
        str.erase(0, pos_delimiter.length());
    }

    if(!str.empty()){
        result.push_back(str);
    }

    return result;

}
```