#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stringset
{
private:
    int wordsize;
    vector<string>first;
    vector<string>second;
    set<string>sett;
public:
    Stringset()
    {
        string infile;
        cin >> infile;
        fstream file;
        file.open(infile+".txt", ios::in);
        string text;
        ///store all the file in a vector
        while (!file.eof())
        {
            file >> text;
            first.push_back(text);
        }
        ///turn all the vector to lower case
        for (int i = 0; i < first.size(); i++)
        {
            for (auto &t : first[i])
            {
                t = tolower(t);
            }
        }
        ///to ignore punctuation
        for (int i = 0; i < first.size(); i++)
        {
            for (auto &t : first[i])
            {
                t = tolower(t);
                auto it = remove_if(first[i].begin(), first[i].end(), ::ispunct);
                first[i].erase(it, first[i].end());
            }
        }
        ///store the data in the set
        for (size_t i = 0; i < first.size(); i++)
        {
            sett.insert(first[i]);
        }
    }

    Stringset(string word)
    {
        addtext(word);
    }

    void addtext(string word)
    {
        cout<<"Enter the text: ";
        string text;
        cin.ignore();
        getline(cin,text);

        for(int i=0; i<text.length(); i++)
        {
            text[i]= tolower(text[i]);
        }
        second.push_back(text);

// second.push_back(text);
//    for (int i = 0; i < second.size(); i++)
//    {
//        for (auto &c : second[i])
//        {
//            c = tolower(c);
//        }
//    }


        for (int i = 0; i < second.size(); i++)
        {
            for (auto &t : second[i])
            {
                t = tolower(t);
                auto it = remove_if(second[i].begin(), second[i].end(), ::ispunct);
                second[i].erase(it, second[i].end());
            }
        }
        for (int i = 0; i < second.size(); i++)
        {
            sett.insert(second[i]);
        }
    }

    void removetext(string word)
    {
        cout<<"Enter the word you want to remove: ";
        string text;
        cin>>text;
        sett.erase(text);
    }

    void clearset()
    {
        sett.clear();
    }

    int wordsnum()
    {
        return sett.size();
    }
    ///return the union between two sets
    Stringset operator+(Stringset s2){
        for(auto i=s2.sett.begin();i!=s2.sett.end();i++){
            sett.insert(*i);
        }
        return *this;
    }
    ///return the intersection between two sets
    Stringset operator*(Stringset s2){
        for(auto i=sett.begin();i!=sett.end();i++){
            if(s2.sett.count(*i)==1){
                cout<< *i <<' ';
            }
        }
        return *this;
    }

    Stringset simi(Stringset s2){
        for(auto i=sett.begin();i!=sett.end();i++){
            if(s2.sett.count(*i)==1){
                s2.second.push_back(*i);
            }
        }
        double sec_size=s2.second.size();
        double percent = (sec_size/(sett.size()*s2.sett.size()))*100;
        cout<<"The similarity = "<<percent<<'%'<<endl;
        return *this;
    }

    friend ostream& operator<<(ostream& out, Stringset s);

};

ostream& operator<<(ostream& out, Stringset s)
{
    for (auto it = s.sett.begin(); it !=s.sett.end(); it++)
    {
        out << *it<< ' ';
    }
    out<< endl;
    return out;
}





int main()
{
    cout << "Welcome!" <<endl<< "Enter the name of the document of the first set: " << endl;
    Stringset s1;
    cout << "Enter the name of the document of the second set: " << endl;
    Stringset s2;
    while(true)
    {
        cout<<"Choose an operation to do: "<<endl;
        cout << "1)To add a string" << endl << "2)To remove a string" << endl<<"3)To clear the set" << endl
             << "4)Return number of strings"<< endl<< "5)Output the set of strings"<<endl
             << "6)To get the union of two strings"<<"\n"<< "7)To get the intersection of two strings"<<endl
             <<"8)To get the similarity"<<"\n"<< "9)Exit" << endl<<endl;
        int x;
        cin >> x;
        string s;

        switch(x)
        {
        case 1:
            s1.addtext(s);
            break;
        case 2:
            s1.removetext(s);
            break;
        case 3:
            s1.clearset();
            break;
        case 4:
            cout<<"The first file size = "<<s1.wordsnum()<<endl;
            cout<<"The second file size = "<<s2.wordsnum()<<endl;
            break;
        case 5:
            cout<<"The first file: "<<endl<<s1<<endl
            <<"The second file: "<<endl<<s2<<endl;
            break;
        case 6:
            s1 = s1+s2;
            cout<<s1<<endl;
            break;
        case 7:
            s1 = s1*s2;
            cout<<endl;
            break;
        case 8:
            s1.simi(s2);
            break;
        default:
            return 0;
        }
        cout<<"Do you want another operation?"<<endl<<
        "1)Yes"<<endl<<"2)No"<<endl;
        int choice;
        cin>>choice;
        if(choice==2){
            return 0;
        }
    }
    return 0;
}
