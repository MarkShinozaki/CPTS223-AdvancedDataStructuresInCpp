#include "Rules.cpp"


struct node
{
    string commands;
    string descriptions;
    bool generated;
    node* next;
};

struct stored_Profiles
{
    string name;
    int score;
};

class Linked_List
{
    public:
        Linked_List();
        ~Linked_List();

        void add_node(string command, string desc);
        void remove_node(string command);
        void add_profile(string name);
        void add_command(string new_command);
        void remove_command(string existing_command);
        void set_profile_data(string name, int score);
        void get_profile_data();
        void open_File();
        void create_Profile();
        void open_Profiles();
        void display_Profiles();
        bool command_check(string check);
        void exiting();
        void generate_Commands(node* temp, string* desc);
        int generate_Descriptions(node* temp, string desc, string aDescription[3]);
        void Play_Game();

    private:
        node* head;
        node* tail;
        vector<stored_Profiles> profile_Data;
        string user_Profile;
        fstream inprofile;
        fstream incommands;
};

void run();