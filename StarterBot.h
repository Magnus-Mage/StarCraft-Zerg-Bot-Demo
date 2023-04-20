#pragma once

#include "MapTools.h"

#include <BWAPI.h>
#include <set>
#include <ctime>
//#include <BWTA.h>
//#include <BWSAL.h>
//#include <BWSAL/EnhancedUI.h>
//#include "OffenseManager.h"
//#include "BwapiEventLogger.h"

class StarterBot
{
    MapTools m_mapTools;

	BWAPI::Unit m_scout = nullptr;
	

public:

    StarterBot();

    virtual void onReceiveText(BWAPI::Player player, std::string text);
    virtual void onPlayerLeft(BWAPI::Player player);
    virtual void onNukeDetect(BWAPI::Position target);
    virtual void onUnitDiscover(BWAPI::Unit unit);
    virtual void onUnitEvade(BWAPI::Unit unit);
    virtual void onSaveGame(std::string gameName);
    
    // Everything below this line is safe to modify.

    const std::string startOfLineSentinel = "||->";
    const std::string endOfLineSentinel = "<-||";
    const std::string startOfUpdateSentinel = "|->";
    const std::string endOfUpdateSentinel = "<-|";

    const std::string delim = "\t";

    const std::string initUpdateSignifier = "init";
    const std::string raceScoutedUpdateSignifier = "raceScouted";
    const std::string onPlayerLeftUpdateSignifier = "onPlayerLeft";
    const std::string onEndUpdateSignifier = "onEnd";

    int enemyPlayerID = -1;
    std::string enemyWriteFilePath;

    std::time_t timerAtGameStart = std::time(nullptr);

    struct StratSettings
    {
        bool is4PoolBO;
        bool isSpeedlingBO;
        bool isHydraRushBO;
        bool isMutaRushBODecidedAfterScoutEnemyRace;
        bool isMutaRushBO;

        // For normal queries, query isMutaRushBO, not these because they are only used
        // in conjunction with isMutaRushBODecidedAfterScoutEnemyRace.
        bool isMutaRushBOVsProtoss;
        bool isMutaRushBOVsTerran;
        bool isMutaRushBOVsZerg;

        bool isSpeedlingPushDeferred;
        bool isEnemyWorkerRusher;
        bool isNumSunkensDecidedAfterScoutEnemyRace;
        int numSunkens;

        // For normal queries, query numSunkens, not these because they are only used
        // in conjunction with isNumSunkensDecidedAfterScoutEnemyRace.
        int numSunkensVsProtoss;
        int numSunkensVsTerran;
        int numSunkensVsZerg;

        inline bool operator <(const StratSettings& other) const
        {
            if (!is4PoolBO && other.is4PoolBO) return true;
            if (is4PoolBO && !other.is4PoolBO) return false;
            if (!isSpeedlingBO && other.isSpeedlingBO) return true;
            if (isSpeedlingBO && !other.isSpeedlingBO) return false;
            if (!isHydraRushBO && other.isHydraRushBO) return true;
            if (isHydraRushBO && !other.isHydraRushBO) return false;
            if (!isMutaRushBODecidedAfterScoutEnemyRace && other.isMutaRushBODecidedAfterScoutEnemyRace) return true;
            if (isMutaRushBODecidedAfterScoutEnemyRace && !other.isMutaRushBODecidedAfterScoutEnemyRace) return false;
            if (!isMutaRushBO && other.isMutaRushBO) return true;
            if (isMutaRushBO && !other.isMutaRushBO) return false;
            if (!isMutaRushBOVsProtoss && other.isMutaRushBOVsProtoss) return true;
            if (isMutaRushBOVsProtoss && !other.isMutaRushBOVsProtoss) return false;
            if (!isMutaRushBOVsTerran && other.isMutaRushBOVsTerran) return true;
            if (isMutaRushBOVsTerran && !other.isMutaRushBOVsTerran) return false;
            if (!isMutaRushBOVsZerg && other.isMutaRushBOVsZerg) return true;
            if (isMutaRushBOVsZerg && !other.isMutaRushBOVsZerg) return false;
            if (!isSpeedlingPushDeferred && other.isSpeedlingPushDeferred) return true;
            if (isSpeedlingPushDeferred && !other.isSpeedlingPushDeferred) return false;
            if (!isEnemyWorkerRusher && other.isEnemyWorkerRusher) return true;
            if (isEnemyWorkerRusher && !other.isEnemyWorkerRusher) return false;
            if (!isNumSunkensDecidedAfterScoutEnemyRace && other.isNumSunkensDecidedAfterScoutEnemyRace) return true;
            if (isNumSunkensDecidedAfterScoutEnemyRace && !other.isNumSunkensDecidedAfterScoutEnemyRace) return false;
            if (numSunkens < other.numSunkens) return true;
            if (numSunkens > other.numSunkens) return false;
            if (numSunkensVsProtoss < other.numSunkensVsProtoss) return true;
            if (numSunkensVsProtoss > other.numSunkensVsProtoss) return false;
            if (numSunkensVsTerran < other.numSunkensVsTerran) return true;
            if (numSunkensVsTerran > other.numSunkensVsTerran) return false;
            if (numSunkensVsZerg < other.numSunkensVsZerg) return true;
            if (numSunkensVsZerg > other.numSunkensVsZerg) return false;
            return true;
        }

        inline bool operator ==(const StratSettings& other) const
        {
            if (is4PoolBO != other.is4PoolBO) return false;
            if (isSpeedlingBO != other.isSpeedlingBO) return false;
            if (isHydraRushBO != other.isHydraRushBO) return false;
            if (isMutaRushBODecidedAfterScoutEnemyRace != other.isMutaRushBODecidedAfterScoutEnemyRace) return false;
            if (isMutaRushBO != other.isMutaRushBO) return false;
            if (isMutaRushBOVsProtoss != other.isMutaRushBOVsProtoss) return false;
            if (isMutaRushBOVsTerran != other.isMutaRushBOVsTerran) return false;
            if (isMutaRushBOVsZerg != other.isMutaRushBOVsZerg) return false;
            if (isSpeedlingPushDeferred != other.isSpeedlingPushDeferred) return false;
            if (isEnemyWorkerRusher != other.isEnemyWorkerRusher) return false;
            if (isNumSunkensDecidedAfterScoutEnemyRace != other.isNumSunkensDecidedAfterScoutEnemyRace) return false;
            if (numSunkens != other.numSunkens) return false;
            if (numSunkensVsProtoss != other.numSunkensVsProtoss) return false;
            if (numSunkensVsTerran != other.numSunkensVsTerran) return false;
            if (numSunkensVsZerg != other.numSunkensVsZerg) return false;
            return true;
        }
    } ss = {};

    // The key is the game ID.
    std::map<int, StratSettings> gameIDToStratSettings;

    // The key is the game ID. The value is the frame count in onEnd().
    std::map<int, int> gameIDToOnEndFrameCount;

    struct GameIDSet
    {
        // The value is the game ID.
        std::set<int> val;
    };

    struct TimerAtGameStartMap
    {
        // The key is the timer at the start of the game.
        std::map<int, GameIDSet> val;
    };

    struct OutcomeMap
    {
        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, TimerAtGameStartMap> val;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, std::map<StratSettings, int> > numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    };

    struct EnemyStartLocDeducedMap
    {
        // The key is the enemy start location if it is known at the start of the
        // game (e.g. if the CompleteMapInformation flag is enabled) or if it is.
        // deduced at the start of the game, otherwise it is Unknown.
        std::map<const BWAPI::TilePosition, OutcomeMap> val;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, std::map<StratSettings, int> > numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    };

    struct MyStartLocationMap
    {
        // The key is my start location.
        std::map<const BWAPI::TilePosition, EnemyStartLocDeducedMap> val;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, std::map<StratSettings, int> > numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    };

    struct MapHashMap
    {
        // The key is the mapHash().
        std::map<std::string, MyStartLocationMap> val;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, std::map<StratSettings, int> > numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    };

    struct NumStartLocationsMap
    {
        // The key is the total number of start locations for the map.
        std::map<int, MapHashMap> val;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, std::map<StratSettings, int> > numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    };

    struct EnemyRaceScoutedMap
    {
        // The key is enemyRaceInit if the enemy race is known at the start of the game,
        // otherwise if the enemy race is eventually scouted it is the enemy race scouted,
        // otherwise it is empty.
        std::map<std::string, NumStartLocationsMap> val;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, std::map<StratSettings, int> > numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    };

    struct EnemyRaceInitMap
    {
        // The key is the enemy race at the start of the game (which may be Unknown).
        std::map<std::string, EnemyRaceScoutedMap> val;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, std::map<StratSettings, int> > numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    };

    struct LearningMap
    {
        EnemyRaceInitMap enemyRaceInitMap;

        // The key is whether the value is about wins (i.e. true) or losses (i.e. false).
        std::map<bool, int> numOutcomes;

        int gameIDIfWonLastGame = -1;
        int gameIDIfLostLastGame = -1;
    } learningMap;



    // helper functions to get you started with bot programming and learn the API
    void sendIdleWorkersToMinerals();
    void trainAdditionalWorkers();
    void buildAdditionalSupply();
    void drawDebugInformation();
	void sendOverlordToScout();

    // functions that are triggered by various BWAPI events from main.cpp
	void onStart();
	void onFrame();
	void onEnd(bool isWinner);
    void Analysis(bool isWinner);
	void onUnitDestroy(BWAPI::Unit unit);
	void onUnitMorph(BWAPI::Unit unit);
	void onSendText(std::string text);
	void onUnitCreate(BWAPI::Unit unit);
	void onUnitComplete(BWAPI::Unit unit);
	void onUnitShow(BWAPI::Unit unit);
	void onUnitHide(BWAPI::Unit unit);
	void onUnitRenegade(BWAPI::Unit unit);

private:
	bool ovie_making = false;
	int ovie_count = 1;
};