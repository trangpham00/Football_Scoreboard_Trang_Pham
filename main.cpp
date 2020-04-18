// Trang Pham
// Unit 4: Football Scoreboard
// COSC 1437: Dr. T
// 4/18/2020


// Credit to Dr. T's basketball scoreboard template that this program was modified after

#include <iostream>

using namespace std;

class Team
{
  private:
    int score,
        timeoutCount;
    bool homeStatus;
    string name,
           coachName,
           homeCity;

  public:
    Team()     // default constructor
    {
      score = 0;
      timeoutCount = 3;
      homeStatus = true;    // team entered is home team by default (initially)
    }

    void setScore(int s)
    { score = s; }
    void setTimeoutCount(int t)
    { timeoutCount = t; }
    void setHomeStatus(bool hom)
    { homeStatus = hom; }
    void setName(string n)
    { name = n; }
    void setCoachName(string coach)
    { coachName = coach; }
    void setHomeCity(string city)
    { homeCity = city; }

    double getScore() const
    { return score; }
    double getTimeoutCount() const
    { return timeoutCount; }
    bool getHomeStatus() const
    { return homeStatus; }
    string getName() const
    { return name; }
    string getCoachName() const
    { return coachName; }
    string getHomeCity() const
    { return homeCity; }
};            // class Team modified to Football

class Scoreboard
{
  private:
    char quarter;
    int down,
        yardsToGo;
  //bool poss; //true = home, false = visitor
  //  Team team1; //double dot notation to get its data
  //  Team team2; //double dot notation to get its data
  public:
    Team team1; //double dot notation to get its data
    Team team2; //double dot notation to get its data
    Scoreboard()      // defualt constructor
    {
      quarter = '1';
      down = 1;
      yardsToGo = 10;
      //poss = true; //home team has the ball intially
    }

    void setQuarter(char q)
    { quarter = q; }
    //void setPoss(bool po)
    //{ poss = po; }
    void setDown (int d)
    { down = d; }
    void setYardsToGo (int yard)
    { yardsToGo = yard; }
    void setTeam1(Team t1)
    { team1 = t1; }
    void setTeam2(Team t2)
    { team2 = t2; }

    char getQuarter() const
    { return quarter; }
    //bool getPoss() const
    //{ return poss; }
    int getDown() const
    { return down; }
    int getYardsToGo() const
    { return yardsToGo; }
    Team getTeam1() const
    { return team1; }
    Team getTeam2() const
    { return team2; }

    void showScoreboard() //method to draw scoreboard
    {
        cout << "SCOREBOARD\n";
        cout << "Home Team" << endl;
        cout << team1.getName() << endl;
        cout << "Score: " << team1.getScore() << endl;
        cout << "Timeouts: " << team1.getTimeoutCount() << endl << endl;
        cout << "Away Team" << endl;
        cout << team2.getName() << endl;
        cout << "Score: " << team2.getScore() << endl;
        cout << "Timeouts: " << team2.getTimeoutCount() << endl << endl;
        cout << "Down: " << down << endl;
        cout << "Yards-To-Go: " << yardsToGo << endl;
        cout << "Quarter: " << quarter << endl << endl;

        //dealing with Boolean data
        /*
        if (poss == true)
        {
          cout << "Home Team has the ball" << endl << endl << endl;
        }
        else
        {
          cout << "Away Team has the ball" << endl << endl << endl;
        }
        */
    }


};    // class Scoreboard modified

void scoreboardControls(Scoreboard &sData)
{
  char decision = '\0';
  char newQuarter;
  int newScore = 0;
  int newTimeouts = 0;
  int newDown = 0;
  int newYardsToGo = 0;
  string newName,
         newCity,
         newCoach;

  do
  {
        //show the scoreboard
        system("clear");
        sData.showScoreboard();
        cout << "SCOREBOARD MENU: " << endl;
        cout << "A. Update Home Team Name" << endl;
        cout << "B. Update Away Team Name" << endl << endl;
        cout << "1. Update Home Team Score" << endl;
        cout << "2. Update Home Team Timeouts" << endl;
        cout << "3. Update Away Team Score" << endl;
        cout << "4. Update Away Team Timeouts" << endl;
        cout << "5. Update Down" << endl;
        cout << "6. Update Yards-To-Go" << endl;
        cout << "7. Update Quarter" << endl << endl;
        cout << "X. Exit" << endl << endl;
        cout << "Enter choice: ";
        cin >> decision;

        if (decision == 'a' || decision == 'A')
        {
          cout << "Home Team Name Update \n";
          cout << "Enter Home Team Name: ";
          cin.ignore();
          getline(cin, newName);
          sData.team1.setName(newName);
        }
        if (decision == 'b' || decision == 'B')
        {
          cout << "Away Team Name Update \n";
          cout << "Enter Away Team Name: ";
          cin.ignore();
          getline(cin, newName);
          sData.team2.setName(newName);
        }
        else if (decision == '1')
        {
          cout << "Home Team Score Update \n";
          cout << "New score: ";
          cin >> newScore;
          sData.team1.setScore(newScore);
        }
        else if (decision == '2')
        {
          cout << "Home Team Timeouts Update \n";
          cout << "New number of timeouts: ";
          cin >> newTimeouts;
          sData.team1.setTimeoutCount(newTimeouts);
        }
        else if (decision == '3')
        {
          cout << "Away Team Score Update \n";
          cout << "New score: ";
          cin >> newScore;
          sData.team2.setScore(newScore);
        }
        else if (decision == '4')
        {
          cout << "Away Team Timeouts Update \n";
          cout << "New number of timeouts: ";
          cin >> newTimeouts;
          sData.team2.setTimeoutCount(newTimeouts);
        }
        else if (decision == '5')
        {
          cout << "Down Update \n";
          cout << "New down: ";
          cin >> newDown;
          sData.setDown(newDown);
        }
        else if (decision == '6')
        {
          cout << "Yards-To-Go Update \n";
          cout << "New Yards-To-Go: ";
          cin >> newYardsToGo;
          sData.setYardsToGo(newYardsToGo);
        }
        else if (decision == '7')
        {
          cout << "Quarter Update \n";
          cout << "New quarter: ";
          cin >> newQuarter;
          sData.setQuarter(newQuarter);
        }
        else if (decision == 'x' || decision == 'X')
        {
          cout << "\nEXIT. Go Cowboys!" << endl;
        }

  }while(decision != 'x' && decision != 'X');

}

int main()
{
  Scoreboard s; //instantiate the the scoreboard object s
  //print the current scoreboard on screen
  //Team tOneMain; //instantiated a team 1 object
 // s.setTeam1(tOneMain); // placed that Team1 object in s

  s.showScoreboard();

  //pass the scoreboad s to the scoreboardControls function

  scoreboardControls(s);

  return 0;
}
