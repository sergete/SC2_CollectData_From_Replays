#include "sc2api/sc2_api.h"
#include "sc2lib/sc2_lib.h"
#include "sc2utils/sc2_manage_process.h"
#include "sc2utils/sc2_arg_parser.h"
#include "NeuralNetworkTraining.h"
#include <iostream>
#include "sc2renderer/sc2_renderer.h"

#include <string>
#include <filesystem>
#include "UnitData.h"
#include "CompileData.h"

//folder creation
#include <Windows.h>
#include <filesystem>

namespace fs = std::experimental::filesystem;
using namespace sc2;
const char* kReplayFolder = "D:/Program Files/StarCraft II/Replays/WCS Leipzig 2018 Replay pack/Grand Final/Serral vs ShoWTimE Acid Plant LE WCS Leipzig 2018.SC2Replay";
const char* URLFOLDER = "D:/ReplayData";

CompileData *compileGameData;
bool do_nothing;

#pragma region MYSCRIPT

#ifdef DEBUG

void CreateFolder(const char* url) {
	int check;
	if (!std::experimental::filesystem::exists(url))
	{
		std::experimental::filesystem::create_directories(url);
	}	
}

class Replay : public sc2::ReplayObserver {
public:

	Race Player1;
	Race Player2;
	double time;
	double speed = 3600;
	double gameLoopPerSecond;
	double totalDurationInGameLoops;
	std::vector<uint32_t> count_units_built_;

	Replay() :
		sc2::ReplayObserver() {
	}

	void OnGameStart() final {
		const sc2::ObservationInterface* obs = Observation();
		assert(obs->GetUnitTypeData().size() > 0);
		count_units_built_.resize(obs->GetUnitTypeData().size());
		std::fill(count_units_built_.begin(), count_units_built_.end(), 0);

		//Races from each player
		Player1 = Observation()->GetGameInfo().player_info[0].race_actual;
		Player2 = Observation()->GetGameInfo().player_info[1].race_actual;
		//time initializer
		time = 0;

		if (Player1 != Race::Protoss) {
			do_nothing = true;
		}
		else {
			do_nothing = false;
			compileGameData = new CompileData(Player1, Player2, this->Observation(), search::CalculateExpansionLocations(Observation(), Query()).size());
		}

		//game loops per second of the game
		gameLoopPerSecond = ReplayControl()->GetReplayInfo().GetGameloopsPerSecond();
		totalDurationInGameLoops = ReplayControl()->GetReplayInfo().duration_gameloops;
		double totalTime = (totalDurationInGameLoops / gameLoopPerSecond) / speed;

		std::cout << "Total GameLoops = " << totalDurationInGameLoops << std::endl;
		std::cout << "Match Total time = " << totalTime << std::endl;
	}

	void OnUnitCreated(const sc2::Unit* unit) final {		

		if (do_nothing) return;

		//same to structure and units
		compileGameData->addUnitOuptut(unit, time);
	}

	void OnUpgradeCompleted(sc2::UpgradeID upgrade_id) {

		//no protoss race then do nothing
		if (do_nothing) return;
		//add the upgrade to the output list
		compileGameData->addUpgradeOutput(upgrade_id, time);
	}

	void OnBuildingConstructionComplete(const sc2::Unit* unit) final {

		//no protoss race then do nothing
		if (do_nothing) return;

		//same to structure and units
		compileGameData->addUnitOuptut(unit, time);
	}

	void OnUnitDestroyed(const sc2::Unit* unit) final {
		//no protoss race then do nothing
		if (do_nothing) return;

		if (unit->alliance == Unit::Alliance::Enemy) {
			compileGameData->removeEnemyUnit(unit, this->Observation());
		}

	}

	void OnUnitEnterVision(const sc2::Unit* unit) final {

		//no protoss race then do nothing
		if (do_nothing) return;

		if (unit->alliance == Unit::Alliance::Enemy) {
			compileGameData->addEnemyUnit(unit, this->Observation());
		}
	}	

	void OnStep() final {

		//no protoss race then do nothing
		if (do_nothing) return;
		std::cout << "gameloop = " << Observation()->GetGameLoop() << std::endl;
		std::cout << "time = " << time << std::endl;

		auto start = std::chrono::system_clock::now();
		
		//do operations in our case introduce data
		compileGameData->IntroduceData(time);

		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		//time += Observation()->GetGameLoop() / speed;

		//elapsed_seconds.count() return the elapsed time in seconds
		time += elapsed_seconds.count();

		
	}

	void OnGameEnd() final {
		std::cout << "Units created:" << std::endl;
		const sc2::ObservationInterface* obs = Observation();
		const sc2::UnitTypes& unit_types = obs->GetUnitTypeData();
		for (uint32_t i = 0; i < count_units_built_.size(); ++i) {
			if (count_units_built_[i] == 0) {
				continue;
			}

			std::cout << unit_types[i].name << ": " << std::to_string(count_units_built_[i]) << std::endl;
		}
		std::cout << "Finished" << std::endl;

	}
};

int main(int argc, char* argv[]) {

	//Read all names of directory to load all replays to extract data
	std::vector<std::string> replays;
	std::string path = "D:/Program Files/StarCraft II/Replays/";
	for (const auto & entry : fs::directory_iterator(path)) {
		//std::cout << entry.path() << std::endl;
		std::string temp = entry.path().generic_string();
		replays.push_back(temp);
	}
	//

	int contador = 0;

	for (int i = 0; i < replays.size(); i++) {

		const char* kReplayDir = replays.at(i).c_str();

		sc2::Coordinator coordinator;

		if (!coordinator.LoadSettings(argc, argv)) {
			return 1;
		}
		if (!coordinator.SetReplayPath(kReplayDir)) {
			std::cout << "Unable to find replays." << std::endl;
			return 1;
		}
		
		Replay replay_observer;

		coordinator.SetMultithreaded(true);

		coordinator.AddReplayObserver(&replay_observer);
		//coordinator.AddReplayObserver(&replay_observer2);

		//if do nothing is true then not save the current replay and load the next one
		if (do_nothing) continue;

		while (coordinator.Update());
		while (!sc2::PollKeyPress());

		CreateFolder(URLFOLDER);
		compileGameData->saveData(URLFOLDER, i);
	}

}

#else
#include "LadderInterface.h"
int main(int argc, char* argv[])
{
	RunBot(argc, argv, new CryptBot(), sc2::Race::Protoss);

	return 0;
}
#endif
#pragma endregion
