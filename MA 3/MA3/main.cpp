#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //
    // Your code goes here
    //

    map<string, TwitterData> data; 

    for (int i =0; i<5; i++){
        data.insert(pair<string, TwitterData>(twitter_data[i].getUserName(),twitter_data[i]));
    }

    // printing map data
    map<string, TwitterData>::iterator itr;

    cout << "--MAP 1--" << endl;

    for (itr = data.begin(); itr != data.end(); itr++)
    {
        cout<<"Username : " << itr->first << endl;
        cout<<"TwitterData : " << itr->second.print(); // calls print function from twitter class
        cout<<endl<<endl;
    }

    // looking for key "savage1" printing the key pair

    for (itr = data.begin(); itr != data.end(); itr++)
    {
        if(itr->first == "savage1")
        {
            cout << "[[]] deleted: " << endl;
            cout << "Username : " << itr->first << endl;
            cout << "TwitterData : " << itr->second.print();
            cout << endl << endl;

            data.erase("savage1"); // deleting the pair from the map
            break;


        }
    }

    // test case 

    bool found = false;
    for(itr = data.begin(); itr != data.end(); itr++)
    {
        if (itr->first=="savage1")
        {
            found = true;
        }
    }

    if(found == true)
    {
        cout << "found" << endl;
    }
    else {
        cout << " not found" << endl;
    }

    map<string, TwitterData> data2; // key: EmailAddress 

    for (int i = 0;i<5; i++)
    {
        data2.insert(pair<string, TwitterData>(twitter_data[i].getEmail(),twitter_data[i]));

    }
    // Printing map data2

    map<string, TwitterData>::iterator itr2;

    cout << "-- MAP 2 --" << endl;

    for (itr2 = data2.begin(); itr2 != data2.end(); itr2++)
    {
        cout<< "Email Address : " << itr2->first << endl;
        cout << "TwitterData : " <<  itr2->second.print(); 
        cout << endl << endl;
    }

    for (itr2 = data2.begin(); itr2 != data2.end(); itr2++)
    {
        if (itr2->first == "kat@gmail.com")
        {
            cout << "[[]] deleted: " << endl;
            cout << "Email Address : " << itr2->first << endl;
            cout << "TwitterData : " << itr2->second.print();
            cout << endl << endl;

            data2.erase("kat@gmail.com"); // deleting the pair from the map

            break;
        }
    }

    // test case 

    found = false;

    for (itr2 = data2.begin(); itr2 != data2.end(); itr2++)
    {
        if (itr2->first == "kat@gmail.com")
        {
            found = true;
        }
    }
    if (found == true)
    {
        cout << "Found" << endl;
    }

    else 
    {
        cout << "Not Found" << endl;
    }



    return 0;
}