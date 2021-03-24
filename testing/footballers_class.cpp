#include <iostream>
#include <fstream>
#include <time.h>


using namespace std;
enum Months
{
    January,
    February,
    March,
    April,  
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};
time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int day = aTime->tm_mday;
int month = aTime->tm_mon; 
int year = aTime->tm_year + 1900; 
class date_of_birth
{
    public:
        int year;
        Months month;
        int day;
};
class Player
{
    int goals_scored;
    int minutes_played;
    int assists;
    public:
        string name;
        date_of_birth date;
        double minutes_for_goal();
        void set_minutes_played (int minutes_played);
        void set_goals_scored (int goals_scored);
        void set_assist(int assists);
        double rate_player_usefulness ();
        int age ();
        bool birthday();
};

double Player::minutes_for_goal ()
{
    return minutes_played/goals_scored;
}
void Player::set_minutes_played (int minutes_played)
{
    this->minutes_played = minutes_played;
}
void Player::set_goals_scored (int goals_scored)
{   
    this->goals_scored = goals_scored;
}
void Player::set_assist(int assists)
{
    this->assists = assists;
}
double Player::rate_player_usefulness ()
{
    if (minutes_played!=0)
    {
        int score = 2*goals_scored + assists;
        return (double)minutes_played/(double)score;
    }
    return -1;
}
int Player::age()
{
    if (month > date.month)
    {
        return year - date.year;
    }
    if (month == date.month && day >= date.day)
    {
        return year - date.year;
    }
    return year - date.year - 1;
}
bool Player::birthday()
{
    if (date.day == day && date.month == month)
        return true;
    return false;
}
int main ()
{
    Player lewy;
    lewy.name= "Robert Lewandowski";
    lewy.set_minutes_played(25*90);
    lewy.set_goals_scored(35);
    lewy.set_assist(6);
    lewy.date.year = 1988;
    lewy.date.month = September;
    lewy.date.day = 21;
    if (lewy.birthday())
    {
        cout << "dzisiaj pan pilkarz ma urodziny"<< endl;
    }
    cout << lewy.rate_player_usefulness() << endl;
    //cout << lewy.age() << endl;
}