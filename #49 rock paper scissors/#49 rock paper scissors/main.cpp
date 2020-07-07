//
//  main.cpp
//  #49 rock paper scissors
//
//  Created by Владислав Легков on 06/05/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using std::string;
using std::cout;
using std::ifstream;
using namespace std;

class fight{

public:
    fight();
    ~fight();
    void take_str(string&);
    void check_winner(string &);
    void who_wins ();
    
private:
    //string full_str;
    string buf_str;
    long int l_str;
    int result;
    
    //очки игроков
    int first_player_points = 0;
    int second_player_points = 0;
};

fight :: fight ()
{
    //cout << "\nconstructor colled\n";
}

fight :: ~fight()
{
    //cout << "\ndestructor called\n";
}

void fight::who_wins()
{
    if (first_player_points > second_player_points)
    {
        cout << "1 ";
    } else
        cout << "2 ";
   // cout << first_player_points << "  " << second_player_points << "\n";
        
}

void fight::check_winner(string &buf)
{
    if ((buf[0] == 'S' && buf[1] == 'P') || (buf[0] == 'P' && buf[1] == 'R')
        ||(buf[0] == 'R' && buf[1] == 'S'))
        first_player_points++;
    else if ((buf[0] == 'P' && buf[1] == 'S') || (buf[0] == 'R' && buf[1] == 'P')
    ||(buf[0] == 'S' && buf[1] == 'R'))
        second_player_points++;
}

void fight :: take_str (string &a)
{
    l_str = a.size();
    
    for (int k = 0; k < l_str; k+=3)
    {
       
        buf_str = a.substr(k,2);
        check_winner(buf_str);
        //cout << buf_str << "  \n";
    }
    
}

int main(int argc, const char * argv[]) {
    ifstream fin ("/Users/vlad99902ipad/Desktop/CodeAbbey/#49 rock paper scissors/input.txt");
    string times;
    getline(fin, times);
    int times_int = atoi(&times[0]);
    if (times_int == 0 )
    {
        cout << "ERROR\n";
        return 1;
    }
    string str;
    int real_times = 0;
    fight *first_play = new fight[times_int];
    while (getline(fin,str)) {
        first_play[real_times].take_str(str);
        first_play[real_times].who_wins();
        real_times++;
        if (real_times > times_int){
            cout << "ERROR 203\n";
            return 1;
        }
    }
    
    //cout << a << "\n\n";
    
    
    delete [] first_play;
    fin.close();
    return 0;
}
