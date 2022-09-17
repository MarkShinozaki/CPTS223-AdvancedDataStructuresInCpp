
#include "Wrapper.hpp"

Linked_List::Linked_List()
{   
    //without pointer symbol, storing the address as NULL
    head = NULL;
    tail = NULL;
    user_Profile = '\0';

    inprofile.open("profiles.csv");
    incommands.open("commands.csv");

    if(!inprofile.is_open() || !incommands.is_open())
    {
        cout << "Files did not open correctly.." << endl;
        to_Continue();
    }

    get_profile_data();
}

Linked_List::~Linked_List()
{
    node* current = head, *tmp;
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    head = NULL;

    inprofile.close();
    incommands.close();
}

void Linked_List::set_profile_data(string name, int score)
{
    profile_Data.push_back({name, score});
    user_Profile = name;
}

void Linked_List::get_profile_data()
{
    string name, score;

    while(!inprofile.eof())
    {
        getline(inprofile, name, ',');
        getline(inprofile, score);
        profile_Data.push_back({name, stoi(score)});
    }
}

void Linked_List::add_node(string command, string desc)
{
    //Create a new node and set data inside the new node and set 
    //the next pointer to NULL
    node* tmp = new node;
    tmp->commands = command;
    tmp->descriptions = desc;
    tmp->generated = false;
    tmp->next = NULL;

    //If head pointer is NULL meaning there is no data stored currently,
    //then the head will be set to the newly added node
    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    //Else there is currently data stored in the linked list
    //so set the next pointer of the last node to the new node made
    // and set the tail as the last node
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void Linked_List::remove_node(string command)
{
    //First, check if linked list has data
    if(head == NULL)
    {
        //Linked list is empty. Nothing to remove
        return;
    }
    else
    {
        //Linked list is not empty. Remove node.
        node* tmp = head, *prev;

        while(tmp != NULL)
        {
            if(tmp->commands == command)
            {
                //Check if head
                if(tmp == head)
                {
                    head = tmp->next;
                    delete tmp;
                }
                else
                {
                    prev->next = tmp->next;
                    delete tmp;
                    break;
                }
            }
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void Linked_List::display_Profiles()
{
    string stored_Profiles, scores, profile_Choice;

    cout << "List of Profiles: Name: Score" << endl;
    for(int i = 0; i < profile_Data.size(); i++)
    {
        cout << profile_Data[i].name << ": " << profile_Data[i].score << endl;
    }
}

void Linked_List::open_File()
{
    string command = "", desc = "";

    if(incommands.is_open())
    {
        while(!incommands.eof())
        {
            //Get line of string from file and separate string by comma
            getline(incommands, command, ',');
            getline(incommands, desc);
            
            //Opening file works. Now parse data into linked list
            add_node(command, desc);
        }
    }
    else
    {
        cout << "Error opening file..." << endl;
        to_Continue();
    }
}

void Linked_List::create_Profile()
{
    string profileName;
    cout << "Enter a new profile name: ";
    getline(cin, profileName);

    //When creating a new profile, sets the profile name to the user input and the score to 0 by default
    profile_Data.push_back({profileName, 0});
    user_Profile = profileName;
}

void Linked_List::open_Profiles()
{
    bool isEmpty;
    string name;

    if(profile_Data.empty())
    {
        //There are currently no profiles stored on file
        cout << "No profiles are stored on file. Please create a profile name" << endl;
        create_Profile();
    }
    else
    {
        //Profiles are stored in a file. Display files to user and have them select which one
        //They would like to load or create a new profile

        int option = 0;
        string stored_Profiles, scores, new_Profile, profile_Choice;

        do
        {
            cout << "Profiles currently exist. Would you like to:\n1. Create a new profile\n2. Load an existing profile" << endl;
            cin >> option;
            cin.ignore();
            system("clear");
            
            switch(option)
            {
                case 1:
                    //Create new profile if option 1
                    create_Profile();
                    break;
            
                case 2:
                    //Load from an existing profile. Parse the data into the profile vector
                    do
                    {
                        display_Profiles();
                        cout << "\nSelect which profile you would like to load" << endl;
                        cin >> profile_Choice;
                        cin.ignore();
                        inprofile.clear();
                        inprofile.seekg(0);
                        while(!inprofile.eof())
                        {
                            getline(inprofile, stored_Profiles, ',');
                            getline(inprofile, scores);

                            if(profile_Choice == stored_Profiles)
                            {
                                set_profile_data(stored_Profiles, stoi(scores));
                                system("clear");
                                cout << "Profile loaded successfully" << endl;
                                to_Continue();
                                break;
                            }
                            else if(inprofile.eof() && (profile_Choice != stored_Profiles))
                            {
                                system("clear");
                                cout << "There are no existing profiles with the name: " << profile_Choice << endl;
                                to_Continue();
                            }
                        }
                    }while (profile_Choice != stored_Profiles);

                    break;

                default:
                    system("clear");
                    cout << "Invalid input. Please select an appropriate option." << endl;
                    break;

            }

        }while(option < 1 || option > 2);
    }
}

bool Linked_List::command_check(string check)
{
    string command, desc;

    incommands.clear();
    incommands.seekg(0);
    while(!incommands.eof())
    {
        getline(incommands, command, ',');
        getline(incommands, desc);
        
        if(check == command)
        {
            //Return true meaning the command already exists in the file
            return true;
        }
        else
        {
            //Return false meaning the command does not exist
            return false;
        }
        
    }
}

// This adds command and description if it doesnt exist
void Linked_List::add_command(string new_command)
{
    bool check = command_check(new_command);
    if(check == false)
    {
        string new_desc;
        cout << "Enter a description for the new command: \n";
        getline(cin, new_desc);
        add_node(new_command, new_desc);
    }
    else
    {
        cout << "Command already exists.." << endl;
        to_Continue();
        system("clear");
    }
}

void Linked_List::remove_command(string existing_command)
{
    bool check = command_check(existing_command);
    if(check == true)
    {
        remove_command(existing_command);
        cout << "Command has been removed" << endl;
        to_Continue();
    }
    else
    {
        cout << "The command you have entered does not exist.." << endl;
        to_Continue();
        system("clear");
    }
}

void Linked_List::exiting()
{
    node* tmp = head;
    fstream commands, profiles;
    profiles.open("profiles.csv", ios::trunc | ios::out);
    commands.open("commands.csv", ios::trunc | ios::out);

    if(inprofile.is_open())
    {
        for(int i = 0; i < profile_Data.size(); i++)
        {
            if(i == 0)
            {
                profiles << profile_Data[i].name << "," << profile_Data[i].score;
            }
            else
            {
                profiles << '\n' << profile_Data[i].name << "," << profile_Data[i].score;
            }
        }
    }
    else
    {
        cout << "Could not update profile..";
        to_Continue();
    }
    if(commands.is_open())
    {
        bool isEmpty;
        while(tmp != NULL)
        {
            if(tmp == head)
            {
                commands << tmp->commands << ',' << tmp->descriptions;
                tmp = tmp->next;
            }
            else
            {
                commands << '\n' << tmp->commands << ',' << tmp->descriptions;
                tmp = tmp->next;
            }
        }
    }
    else
    {
        cout << "Cout not update commands..";
        to_Continue();
    }

    profiles.close();
    commands.close();
}

int Linked_List::generate_Descriptions(node* temp, string desc, string aDescription[3])
{
    string description[3];
    int x;

    for(int y = 0; y < 3; y++)
    {
        temp = head;
        x = (rand() % 30);

        for(int i = 0; i < x; i++)
        {
            temp = temp->next;
        }

        if(description[0] == temp->descriptions || description[1] == temp->descriptions || description[2] == temp->descriptions)
        {
            generate_Descriptions(temp, desc, &string);
        }
        else
        {
            description[y] = temp->descriptions;
        }
    }
    
    x = rand() % 3;
    description[x] = desc;

    for(int z = 0; z < 3; z++)
    {
        cout << z+1 << ": " << description[z] << '\n';
    }
    return x;
}

void Linked_List::generate_Commands(node* temp, string* desc)
{
    int x = (rand() % 30);

    for(int i = 0; i < x; i++)
    {
        temp = temp->next;
    }
    if(temp->generated == true)
    {
        generate_Commands(temp, desc);
    }
    else
    {
        temp->generated = true;
        cout << temp->commands << '\n' << endl;
        *desc = temp->descriptions;
    }
    
}

void Linked_List::Play_Game()
{
    int commands = 0, answer, Choice;
    string description, string;
    node* list = head;

    do
    {
        cout << "Choose the number of commands to be generated between 5 and 30: ";
        cin >> commands;
        cin.ignore();
        if(commands < 5 || commands > 30)
        {
            system("clear");
            cout << "Please pick a number between 5 and 30" << endl;
            to_Continue();
        }

    } while (commands < 5 || commands > 30);
    
    for(int i = 0; i < commands; i++)
    {
        generate_Commands(list, &description);
        answer = generate_Descriptions(list, description);

        cout << " Match the description that corresponds to the linux command: ";
        cin >> Choice;
        cin.ignore();

        if(Choice == answer)
        {
            cout << "A point has been awarded" << endl;
            for(int x = 0; x < profile_Data.size(); x++)
            {
                if(profile_Data[x].name == user_Profile)
                {
                    profile_Data[x].score = profile_Data[x].score + 1;
                    cout << "Current score: " << profile_Data[x].score;
                    x = profile_Data.size() - 1;
                    to_Continue();
                    system("clear");
                }
            }
        }
        else
        {
            cout << "Incorrect. A point has been deducted" << endl;
            for(int z = 0; z < profile_Data.size(); z++)
            {
                if(profile_Data[z].name == user_Profile)
                {
                    profile_Data[z].score = profile_Data[z].score - 1;
                    cout << "Current score: " << profile_Data[z].score;
                    z = profile_Data.size() - 1;
                    to_Continue();
                    system("clear");
                }
            }
        }
    }

    cout << "The Game is Over!\nYour End score is: ";
    for(int w = 0; w < profile_Data.size(); w++)
    {
        if(profile_Data[w].name == user_Profile)
        {
            cout << profile_Data[w].score << endl;
            w = profile_Data.size() - 1;
            to_Continue();
            system("clear");
        }
    }

}

void run()
{
    int option = 0;
    string command_user = "";
    Linked_List List;
    List.open_File();

    do
    {
        cout << "1. Game Rules\n2. Play Game\n3. Create New game or Load Game\n4. Add Command \
        \n5. Remove Command\n6. Exit" << endl;
        cin >> option;
        cin.ignore();
        system("clear");

        switch(option)
        {
            case 1:
                Rules();
                to_Continue();
                system("clear");
                break;

            case 2:
                system("clear");
                cout << "Welcome to the Matching Game" << endl;
                List.open_Profiles();
                List.Play_Game();
                break;

            case 3:
                system("clear");
                List.open_Profiles();
                break;

            case 4:
                system("clear");
                cout << "Enter command: ";
                cin >> command_user;
                cin.ignore();
                List.add_command(command_user);
                system("clear");
                break;

            case 5:
                system("clear");
                cout << "Enter command to remove: ";
                cin >> command_user;
                cin.ignore();
                List.remove_command(command_user);
                system("clear");
                break;

            case 6:
                cout << "Thanks for playing the matching game" << endl;
                sleep(1);
                List.exiting();
                system("clear");
                break;

            default:
                cout << "Please try again.\n\n";
                sleep(1);
                system("clear");
                break;

        }
    }while(option != 6);
}