#include <iostream>
#include <string>

using namespace std;

class ForceBeing {
  private: 
    int power_level;
    string name;
    bool evil;

  protected: 
    ForceBeing(int level) {
      power_level = level;
    }

    void setPowerLevel(int level) {
      power_level = level;
    }

    void setName(string characterName) {
      name = characterName;
    }

  public: 
    virtual int getPowerLevel() {
      return power_level;
    }

    virtual string getName() {
      return name;
    }

    void setEvil() {
      evil = true;
    }

    void setGood() {
      evil = false;
    }
};

class Jedi: public ForceBeing {
  
  public: 
    Jedi(string jediName, int level):ForceBeing(level) {
      setName(jediName);
      setGood();
    }

    int getPowerLevel() {
      return ForceBeing::getPowerLevel() + 1;
    }
};

class Sith: public ForceBeing {
  public: 
    Sith(string sithName, int level):ForceBeing(level) {
      setName(sithName);
      setEvil();
    }

    int getPowerLevel() {
      return ForceBeing::getPowerLevel() - 1;
    }

    string getName() {
      return "Sith Lord: " + ForceBeing::getName();
    }
};

static string getWinner(ForceBeing &player1, ForceBeing &player2) {
  return player1.getPowerLevel() > player2.getPowerLevel() ?player1.getName() : player2.getName();
}

static void printWinner(string winner) {
  cout << "The winner is: " << winner << endl;
}     

int main() {
  Sith darthVader("Darth Vader",100);
  Jedi lukeSkyWalker("Luke Skywalker",99);
  printWinner(getWinner(darthVader, lukeSkyWalker));
  return 0;
}