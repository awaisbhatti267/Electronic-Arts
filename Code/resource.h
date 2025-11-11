#ifndef PATH_TO_GLORY_H
#define PATH_TO_GLORY_H

#include <string>
#include <vector>
#include <map>

class Stats {
private:
    int touchdowns;
    int interceptions;

public:
    Stats();
    void updateStats();
    int getTouchdowns() const;
    int getInterceptions() const;
    void setTouchdowns(int td);
    void setInterceptions(int intc);
};

class Effect {
private:
    float moraleChange;
    float reputationImpact;

public:
    Effect();
    void applyTo(void* target); // Generic target
    float getMoraleChange() const;
    float getReputationImpact() const;
};

class Choice {
private:
    std::string description;
    Effect effect;

public:
    Choice();
    void applyEffect();
    std::string getDescription() const;
};

class StoryEvent {
private:
    std::string eventId;
    std::string description;
    std::vector<Choice> choices;

public:
    StoryEvent();
    void triggerEvent();
    std::vector<Choice>& getChoices();
};

class StoryArc {
private:
    std::string title;
    bool isActive;
    int progress;
    std::vector<StoryEvent> events;

public:
    StoryArc();
    void advanceArc();
    void evaluateConditions();
};

class MediaOutlet {
private:
    std::string name;

public:
    MediaOutlet();
    void publishStory();
};

class Player; // Forward declaration

class Coach {
private:
    std::string name;
    float reputation;

public:
    Coach();
    void makeDecision();
    void evaluateTeam();
    std::string getName() const;
    float getReputation() const;
};

class Player {
private:
    std::string name;
    float morale;
    Stats stats;
    Coach* coach;

public:
    Player();
    void updateStats();
    void triggerEvent();
    std::string getName() const;
    float getMorale() const;
    Stats& getStats();
    Coach* getCoach() const;
};

class Team {
private:
    std::string name;
    int ranking;
    std::vector<Player> players;
    Coach* coach;

public:
    Team();
    void updateRanking();
    void addPlayer(const Player& player);
    std::vector<Player>& getPlayers();
    Coach* getCoach() const;
    std::string getName() const;
    int getRanking() const;
};

#endif // PATH_TO_GLORY_H
