#include "UnitData.h"
//#include "Blinkerbot.h"


UnitData::UnitData()
{
}


UnitData::~UnitData()
{
}

bool UnitData::isWorker(const Unit *unit)
{
	if ((unit->unit_type == UNIT_TYPEID::TERRAN_SCV) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_MULE) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_PROBE) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_DRONE))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UnitData::isStructure(const Unit *unit)
{
	if ((unit->unit_type == UNIT_TYPEID::TERRAN_ARMORY) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_BARRACKS) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_BARRACKSFLYING) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_BARRACKSREACTOR) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_BARRACKSTECHLAB) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_BUNKER) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_COMMANDCENTER) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_COMMANDCENTERFLYING) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_ENGINEERINGBAY) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_FACTORY) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_FACTORYFLYING) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_FACTORYREACTOR) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_FACTORYTECHLAB) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_FUSIONCORE) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_GHOSTACADEMY) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_MISSILETURRET) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_ORBITALCOMMAND) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_PLANETARYFORTRESS) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_REACTOR) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_REFINERY) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_SENSORTOWER) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_STARPORT) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_STARPORTFLYING) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_STARPORTREACTOR) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_STARPORTTECHLAB) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_SUPPLYDEPOT) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_SUPPLYDEPOTLOWERED) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_TECHLAB) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_ASSIMILATOR) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_CYBERNETICSCORE) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_DARKSHRINE) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_FLEETBEACON) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_FORGE) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_GATEWAY) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_NEXUS) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_PHOTONCANNON) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_PYLON) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_PYLONOVERCHARGED) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_ROBOTICSBAY) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_SHIELDBATTERY) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_STARGATE) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_WARPGATE) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_BANELINGNEST) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_CREEPTUMOR) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_CREEPTUMORBURROWED) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_EVOLUTIONCHAMBER) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_EXTRACTOR) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_GREATERSPIRE) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_HATCHERY) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_HIVE) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_HYDRALISKDEN) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_INFESTATIONPIT) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_LAIR) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_LURKERDENMP) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_NYDUSCANAL) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_NYDUSNETWORK) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_ROACHWARREN) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_SPAWNINGPOOL) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_SPINECRAWLER) ||
		//(unit->unit_type == UNIT_TYPEID::ZERG_SPINECRAWLERUPROOTED) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_SPIRE) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_SPORECRAWLER)) //||
		//(unit->unit_type == UNIT_TYPEID::ZERG_SPORECRAWLERUPROOTED))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UnitData::isFightingUnit(const Unit *unit)
{
	/* unimplemented
	if ()
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;
}

bool UnitData::isTownHall(const Unit *unit)
{

	if (unit->unit_type == UNIT_TYPEID::TERRAN_COMMANDCENTER ||
		unit->unit_type == UNIT_TYPEID::TERRAN_ORBITALCOMMAND ||
		unit->unit_type == UNIT_TYPEID::TERRAN_COMMANDCENTERFLYING ||
		unit->unit_type == UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING ||
		unit->unit_type == UNIT_TYPEID::TERRAN_PLANETARYFORTRESS ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_NEXUS ||
		unit->unit_type == UNIT_TYPEID::ZERG_HATCHERY ||
		unit->unit_type == UNIT_TYPEID::ZERG_LAIR ||
		unit->unit_type == UNIT_TYPEID::ZERG_HIVE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UnitData::isSupplyProvider(const Unit *unit)
{
	/* unimplemented
	if ()
	{
	return true;
	}
	else
	{
	return false;
	}
	*/
	return false;
}

bool UnitData::isMinerals(const Unit *unit)
{
	if ((unit->unit_type == UNIT_TYPEID::NEUTRAL_BATTLESTATIONMINERALFIELD) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_BATTLESTATIONMINERALFIELD750) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_LABMINERALFIELD) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_LABMINERALFIELD750) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_MINERALFIELD) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_MINERALFIELD750) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_PURIFIERMINERALFIELD) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_PURIFIERMINERALFIELD750) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_PURIFIERRICHMINERALFIELD) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_PURIFIERRICHMINERALFIELD750) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD750))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UnitData::isVespeneGeyser(const Unit *unit)
{
	if ((unit->unit_type == UNIT_TYPEID::NEUTRAL_VESPENEGEYSER) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_PROTOSSVESPENEGEYSER) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_PURIFIERVESPENEGEYSER) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_SHAKURASVESPENEGEYSER) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_RICHVESPENEGEYSER) ||
		(unit->unit_type == UNIT_TYPEID::NEUTRAL_SPACEPLATFORMGEYSER))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UnitData::isOurs(const Unit *unit)
{
	if (unit->alliance == Unit::Alliance::Self)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns true if the unit can cloak, also returns true for lurkers as they can attack while burrowed
bool UnitData::canCloak(const Unit *unit)
{
	if ((unit->unit_type == UNIT_TYPEID::TERRAN_BANSHEE) ||
		(unit->unit_type == UNIT_TYPEID::TERRAN_GHOST) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_DARKTEMPLAR) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_MOTHERSHIP) ||
		(unit->unit_type == UNIT_TYPEID::PROTOSS_OBSERVER) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_LURKERMP) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_LURKERMPBURROWED) ||
		(unit->unit_type == UNIT_TYPEID::ZERG_LURKERMPEGG))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns which structure is required to produce a given ability(limited implementation)
UnitTypeID UnitData::requiredStructure(AbilityID ability)
{
	UnitTypeID required;

	switch (ABILITY_ID(ability))
	{
	case ABILITY_ID::RESEARCH_WARPGATE:
		required = UNIT_TYPEID::PROTOSS_CYBERNETICSCORE;
		break;
	case ABILITY_ID::RESEARCH_BLINK:
	case ABILITY_ID::RESEARCH_CHARGE:
		required = UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL;
		break;
	case ABILITY_ID::RESEARCH_EXTENDEDTHERMALLANCE:
		required = UNIT_TYPEID::PROTOSS_ROBOTICSBAY;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL1:
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL1:
	case ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL1:
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL2:
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL3:
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL2:
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL3:
	case ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL2:
	case ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL3:
		required = UNIT_TYPEID::PROTOSS_FORGE;
		break;
	case ABILITY_ID::RESEARCH_PSISTORM:
		required = UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE;
		break;
	case ABILITY_ID::TRAIN_ZEALOT:
	case ABILITY_ID::TRAINWARP_ZEALOT:
		required = UNIT_TYPEID::PROTOSS_GATEWAY;
		break;
	case ABILITY_ID::TRAIN_STALKER:
	case ABILITY_ID::TRAIN_SENTRY:
	case ABILITY_ID::TRAINWARP_STALKER:
	case ABILITY_ID::TRAINWARP_SENTRY:
		required = UNIT_TYPEID::PROTOSS_CYBERNETICSCORE;
		break;
	case ABILITY_ID::TRAIN_DARKTEMPLAR:
	case ABILITY_ID::TRAINWARP_DARKTEMPLAR:
		required = UNIT_TYPEID::PROTOSS_DARKSHRINE;
		break;
	case ABILITY_ID::TRAIN_OBSERVER:
	case ABILITY_ID::TRAIN_IMMORTAL:
		required = UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY;
		break;
	case ABILITY_ID::TRAIN_COLOSSUS:
		required = UNIT_TYPEID::PROTOSS_ROBOTICSBAY;
		break;
	case ABILITY_ID::TRAIN_VOIDRAY:
		required = UNIT_TYPEID::PROTOSS_STARGATE;
		break;
	default:
		UNIT_TYPEID::INVALID;
	}

	return required;
}

//returns true if the ability is a research (limited implementation)
bool UnitData::isResearch(AbilityID ability)
{
	if ((ABILITY_ID(ability) == ABILITY_ID::RESEARCH_WARPGATE) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_BLINK) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_EXTENDEDTHERMALLANCE) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_CHARGE) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PSISTORM) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMOR) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL1) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL2) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL3) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONS) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL1) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL2) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL3) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSSHIELDS) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL1) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL2) ||
		(ABILITY_ID(ability) == ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL3))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//checks if an AbilityID represents a trainable unit (only process implemented so far)
bool UnitData::isTrainableUnitType(AbilityID ability)
{
	if ((ABILITY_ID(ability) == ABILITY_ID::TRAINWARP_ADEPT) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAINWARP_DARKTEMPLAR) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAINWARP_HIGHTEMPLAR) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAINWARP_SENTRY) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAINWARP_STALKER) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAINWARP_ZEALOT) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_ADEPT) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_CARRIER) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_COLOSSUS) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_DARKTEMPLAR) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_DISRUPTOR) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_HIGHTEMPLAR) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_IMMORTAL) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_MOTHERSHIP) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_MOTHERSHIPCORE) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_OBSERVER) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_ORACLE) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_PHOENIX) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_PROBE) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_SENTRY) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_STALKER) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_WARPPRISM) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_VOIDRAY) ||
		(ABILITY_ID(ability) == ABILITY_ID::TRAIN_ZEALOT))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns a UnitTypeID based on a given AbilityID (only protoss implemented)
UnitTypeID UnitData::getUnitTypeID(AbilityID ability)
{
	switch (ABILITY_ID(ability))
	{
	case ABILITY_ID::TRAINWARP_ADEPT:
	case ABILITY_ID::TRAIN_ADEPT:
		return UNIT_TYPEID::PROTOSS_ADEPT;
		break;
	case ABILITY_ID::TRAINWARP_DARKTEMPLAR:
	case ABILITY_ID::TRAIN_DARKTEMPLAR:
		return UNIT_TYPEID::PROTOSS_DARKTEMPLAR;
		break;
	case ABILITY_ID::TRAINWARP_HIGHTEMPLAR:
	case ABILITY_ID::TRAIN_HIGHTEMPLAR:
		return UNIT_TYPEID::PROTOSS_HIGHTEMPLAR;
		break;
	case ABILITY_ID::TRAINWARP_SENTRY:
		return UNIT_TYPEID::PROTOSS_SENTRY;
		break;
	case ABILITY_ID::TRAINWARP_STALKER:
	case ABILITY_ID::TRAIN_STALKER:
		return UNIT_TYPEID::PROTOSS_STALKER;
		break;
	case ABILITY_ID::TRAINWARP_ZEALOT:
	case ABILITY_ID::TRAIN_ZEALOT:
		return UNIT_TYPEID::PROTOSS_ZEALOT;
		break;
	case ABILITY_ID::TRAIN_CARRIER:
		return UNIT_TYPEID::PROTOSS_CARRIER;
		break;
	case ABILITY_ID::TRAIN_COLOSSUS:
		return UNIT_TYPEID::PROTOSS_COLOSSUS;
		break;
	case ABILITY_ID::TRAIN_DISRUPTOR:
		return UNIT_TYPEID::PROTOSS_DISRUPTOR;
		break;
	case ABILITY_ID::TRAIN_IMMORTAL:
		return UNIT_TYPEID::PROTOSS_IMMORTAL;
		break;
	case ABILITY_ID::TRAIN_MOTHERSHIP:
		return UNIT_TYPEID::PROTOSS_MOTHERSHIP;
		break;
	case ABILITY_ID::TRAIN_MOTHERSHIPCORE:
		return UNIT_TYPEID::PROTOSS_MOTHERSHIPCORE;
		break;
	case ABILITY_ID::TRAIN_OBSERVER:
		return UNIT_TYPEID::PROTOSS_OBSERVER;
		break;
	case ABILITY_ID::TRAIN_ORACLE:
		return UNIT_TYPEID::PROTOSS_ORACLE;
		break;
	case ABILITY_ID::TRAIN_PHOENIX:
		return UNIT_TYPEID::PROTOSS_PHOENIX;
		break;
	case ABILITY_ID::TRAIN_PROBE:
		return UNIT_TYPEID::PROTOSS_PROBE;
		break;
	case ABILITY_ID::TRAIN_WARPPRISM:
		return UNIT_TYPEID::PROTOSS_WARPPRISM;
		break;
	case ABILITY_ID::TRAIN_VOIDRAY:
		return UNIT_TYPEID::PROTOSS_VOIDRAY;
		break;
	case ABILITY_ID::BUILD_ASSIMILATOR:
		return UNIT_TYPEID::PROTOSS_ASSIMILATOR;
		break;
	case ABILITY_ID::BUILD_CYBERNETICSCORE:
		return UNIT_TYPEID::PROTOSS_CYBERNETICSCORE;
		break;
	case ABILITY_ID::BUILD_DARKSHRINE:
		return UNIT_TYPEID::PROTOSS_DARKSHRINE;
		break;
	case ABILITY_ID::BUILD_FLEETBEACON:
		return UNIT_TYPEID::PROTOSS_FLEETBEACON;
		break;
	case ABILITY_ID::BUILD_FORGE:
		return UNIT_TYPEID::PROTOSS_FORGE;
		break;
	case ABILITY_ID::BUILD_GATEWAY:
		return UNIT_TYPEID::PROTOSS_GATEWAY;
		break;
	case ABILITY_ID::BUILD_NEXUS:
		return UNIT_TYPEID::PROTOSS_NEXUS;
		break;
	case ABILITY_ID::BUILD_PHOTONCANNON:
		return UNIT_TYPEID::PROTOSS_PHOTONCANNON;
		break;
	case ABILITY_ID::BUILD_PYLON:
		return UNIT_TYPEID::PROTOSS_PYLON;
		break;
	case ABILITY_ID::BUILD_ROBOTICSBAY:
		return UNIT_TYPEID::PROTOSS_ROBOTICSBAY;
		break;
	case ABILITY_ID::BUILD_ROBOTICSFACILITY:
		return UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY;
		break;
	case ABILITY_ID::BUILD_SHIELDBATTERY:
		return UNIT_TYPEID::PROTOSS_SHIELDBATTERY;
		break;
	case ABILITY_ID::BUILD_STARGATE:
		return UNIT_TYPEID::PROTOSS_STARGATE;
		break;
	case ABILITY_ID::BUILD_TEMPLARARCHIVE:
		return UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE;
		break;
	case ABILITY_ID::BUILD_TWILIGHTCOUNCIL:
		return UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL;
		break;
	default:
		return UNIT_TYPEID::INVALID;
		break;
	}
}

UpgradeID UnitData::getUpgradeID(AbilityID ability)
{
	switch (ABILITY_ID(ability))
	{
	case ABILITY_ID::RESEARCH_WARPGATE:
		return UPGRADE_ID::WARPGATERESEARCH;
		break;
	case ABILITY_ID::RESEARCH_BLINK:
		return UPGRADE_ID::BLINKTECH;
		break;
	case ABILITY_ID::RESEARCH_EXTENDEDTHERMALLANCE:
		return UPGRADE_ID::EXTENDEDTHERMALLANCE;
		break;
	case ABILITY_ID::RESEARCH_CHARGE:
		return UPGRADE_ID::CHARGE;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL1:
		return UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL1;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL2:
		return UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL2;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL3:
		return UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL3;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL1:
		return UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL1;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL2:
		return UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL2;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL3:
		return UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL3;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL1:
		return UPGRADE_ID::PROTOSSSHIELDSLEVEL1;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL2:
		return UPGRADE_ID::PROTOSSSHIELDSLEVEL2;
		break;
	case ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL3:
		return UPGRADE_ID::PROTOSSSHIELDSLEVEL3;
		break;
	case ABILITY_ID::RESEARCH_PSISTORM:
		return UPGRADE_ID::PSISTORMTECH;
		break;
	default:
		return UPGRADE_ID::INVALID;
		break;
	}
}

//returns true if the ability refers to a structure that a worker can build
bool UnitData::isBuildAbility(AbilityID ability)
{
	if (ability == ABILITY_ID::BUILD_ARMORY ||
		ability == ABILITY_ID::BUILD_ASSIMILATOR ||
		ability == ABILITY_ID::BUILD_BANELINGNEST ||
		ability == ABILITY_ID::BUILD_BARRACKS ||
		ability == ABILITY_ID::BUILD_BUNKER ||
		ability == ABILITY_ID::BUILD_COMMANDCENTER ||
		ability == ABILITY_ID::BUILD_CYBERNETICSCORE ||
		ability == ABILITY_ID::BUILD_DARKSHRINE ||
		ability == ABILITY_ID::BUILD_ENGINEERINGBAY ||
		ability == ABILITY_ID::BUILD_EVOLUTIONCHAMBER ||
		ability == ABILITY_ID::BUILD_EXTRACTOR ||
		ability == ABILITY_ID::BUILD_FACTORY ||
		ability == ABILITY_ID::BUILD_FLEETBEACON ||
		ability == ABILITY_ID::BUILD_FORGE ||
		ability == ABILITY_ID::BUILD_FUSIONCORE ||
		ability == ABILITY_ID::BUILD_GATEWAY ||
		ability == ABILITY_ID::BUILD_GHOSTACADEMY ||
		ability == ABILITY_ID::BUILD_HATCHERY ||
		ability == ABILITY_ID::BUILD_HYDRALISKDEN ||
		ability == ABILITY_ID::BUILD_INFESTATIONPIT ||
		ability == ABILITY_ID::BUILD_MISSILETURRET ||
		ability == ABILITY_ID::BUILD_NEXUS ||
		ability == ABILITY_ID::BUILD_NYDUSNETWORK ||
		ability == ABILITY_ID::BUILD_PHOTONCANNON ||
		ability == ABILITY_ID::BUILD_PYLON ||
		ability == ABILITY_ID::BUILD_REFINERY ||
		ability == ABILITY_ID::BUILD_ROACHWARREN ||
		ability == ABILITY_ID::BUILD_ROBOTICSBAY ||
		ability == ABILITY_ID::BUILD_ROBOTICSFACILITY ||
		ability == ABILITY_ID::BUILD_SENSORTOWER ||
		ability == ABILITY_ID::BUILD_SHIELDBATTERY ||
		ability == ABILITY_ID::BUILD_SPAWNINGPOOL ||
		ability == ABILITY_ID::BUILD_SPINECRAWLER ||
		ability == ABILITY_ID::BUILD_SPIRE ||
		ability == ABILITY_ID::BUILD_SPORECRAWLER ||
		ability == ABILITY_ID::BUILD_STARGATE ||
		ability == ABILITY_ID::BUILD_STARPORT ||
		ability == ABILITY_ID::BUILD_SUPPLYDEPOT ||
		ability == ABILITY_ID::BUILD_TEMPLARARCHIVE ||
		ability == ABILITY_ID::BUILD_TWILIGHTCOUNCIL ||
		ability == ABILITY_ID::BUILD_ULTRALISKCAVERN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns true for Assimilators, Extractors, and Refineries
bool UnitData::isGasStructure(const Unit *unit)
{
	if (unit->unit_type == UNIT_TYPEID::PROTOSS_ASSIMILATOR ||
		unit->unit_type == UNIT_TYPEID::TERRAN_REFINERY ||
		unit->unit_type == UNIT_TYPEID::ZERG_EXTRACTOR)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*
given an UpgradeID, returns the corresponding AbilityID needed to get that upgrade (limited implementation)
*/
AbilityID UnitData::getAbilityID(UpgradeID upgrade)
{
	switch (UPGRADE_ID(upgrade))
	{
	case UPGRADE_ID::WARPGATERESEARCH:
		return ABILITY_ID::RESEARCH_WARPGATE;
		break;
	case UPGRADE_ID::BLINKTECH:
		return ABILITY_ID::RESEARCH_BLINK;
		break;
	case UPGRADE_ID::EXTENDEDTHERMALLANCE:
		return ABILITY_ID::RESEARCH_EXTENDEDTHERMALLANCE;
		break;
	case UPGRADE_ID::CHARGE:
		return ABILITY_ID::RESEARCH_CHARGE;
		break;
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL1:
		return ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL1;
		break;
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL2:
		return ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL2;
		break;
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL3:
		return ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL3;
		break;
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL1:
		return ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL1;
		break;
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL2:
		return ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL2;
		break;
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL3:
		return ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL3;
		break;
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL1:
		return ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL1;
		break;
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL2:
		return ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL2;
		break;
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL3:
		return ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL3;
		break;
	case UPGRADE_ID::PSISTORMTECH:
		return ABILITY_ID::RESEARCH_PSISTORM;
		break;
	default:
		return ABILITY_ID::INVALID;
		break;
	}
}

/*
compares generic upgrade names like PROTOSSGROUNDWEAPONS with specific levels of those upgrades
and returns true if they're of the same type
*/
bool UnitData::isComparableUpgrade(AbilityID abilityA, AbilityID abilityB)
{
	if (compareUpgrades(abilityA, abilityB) || compareUpgrades(abilityB, abilityA))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
compares a generic upgrade (A) vs a specific upgrade level (B).
This method is one-directional; call isComparableUpgrade to check A vs B and B vs A.
*/
bool UnitData::compareUpgrades(AbilityID abilityA, AbilityID abilityB)
{
	if (abilityA == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONS &&
		(abilityB == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL1 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL2 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSGROUNDWEAPONSLEVEL3))
	{
		return true;
	}
	else if (abilityA == ABILITY_ID::RESEARCH_PROTOSSAIRWEAPONS &&
		(abilityB == ABILITY_ID::RESEARCH_PROTOSSAIRWEAPONSLEVEL1 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSAIRWEAPONSLEVEL2 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSAIRWEAPONSLEVEL3))
	{
		return true;
	}
	else if (abilityA == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMOR &&
		(abilityB == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL1 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL2 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSGROUNDARMORLEVEL3))
	{
		return true;
	}
	else if (abilityA == ABILITY_ID::RESEARCH_PROTOSSAIRARMOR &&
		(abilityB == ABILITY_ID::RESEARCH_PROTOSSAIRARMORLEVEL1 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSAIRARMORLEVEL2 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSAIRARMORLEVEL3))
	{
		return true;
	}
	else if (abilityA == ABILITY_ID::RESEARCH_PROTOSSSHIELDS &&
		(abilityB == ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL1 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL2 ||
			abilityB == ABILITY_ID::RESEARCH_PROTOSSSHIELDSLEVEL3))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true for TRAINWARP abilities
*/
bool UnitData::canWarpIn(AbilityID ability)
{
	if (ability == ABILITY_ID::TRAINWARP_ADEPT ||
		ability == ABILITY_ID::TRAINWARP_DARKTEMPLAR ||
		ability == ABILITY_ID::TRAINWARP_HIGHTEMPLAR ||
		ability == ABILITY_ID::TRAINWARP_SENTRY ||
		ability == ABILITY_ID::TRAINWARP_STALKER ||
		ability == ABILITY_ID::TRAINWARP_ZEALOT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true if the given unit can be trained from a warpgate
*/
bool UnitData::isWarpGateUnit(const Unit *unit)
{
	if (unit->unit_type == UNIT_TYPEID::PROTOSS_ADEPT ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_DARKTEMPLAR ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_HIGHTEMPLAR ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_SENTRY ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_STALKER ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_ZEALOT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true if the given unit type can be trained from a warpgate
*/
bool UnitData::isWarpGateUnit(UnitTypeID unitType)
{
	if (unitType == UNIT_TYPEID::PROTOSS_ADEPT ||
		unitType == UNIT_TYPEID::PROTOSS_DARKTEMPLAR ||
		unitType == UNIT_TYPEID::PROTOSS_HIGHTEMPLAR ||
		unitType == UNIT_TYPEID::PROTOSS_SENTRY ||
		unitType == UNIT_TYPEID::PROTOSS_STALKER ||
		unitType == UNIT_TYPEID::PROTOSS_ZEALOT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true for gateway TRAIN_ ability_ids
*/
bool UnitData::isTrainedFromGateway(AbilityID ability)
{
	if (ability == ABILITY_ID::TRAIN_ADEPT ||
		ability == ABILITY_ID::TRAIN_DARKTEMPLAR ||
		ability == ABILITY_ID::TRAIN_HIGHTEMPLAR ||
		ability == ABILITY_ID::TRAIN_SENTRY ||
		ability == ABILITY_ID::TRAIN_STALKER ||
		ability == ABILITY_ID::TRAIN_ZEALOT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns the TRAINWARP ability ID for a given unit type, or INVALID if it doesn't have one
*/
AbilityID UnitData::getTrainWarpAbilityID(UnitTypeID unitType)
{
	switch (UNIT_TYPEID(unitType))
	{
	case UNIT_TYPEID::PROTOSS_ADEPT:
		return ABILITY_ID::TRAINWARP_ADEPT;
		break;
	case UNIT_TYPEID::PROTOSS_DARKTEMPLAR:
		return ABILITY_ID::TRAINWARP_DARKTEMPLAR;
		break;
	case UNIT_TYPEID::PROTOSS_HIGHTEMPLAR:
		return ABILITY_ID::TRAINWARP_HIGHTEMPLAR;
		break;
	case UNIT_TYPEID::PROTOSS_SENTRY:
		return ABILITY_ID::TRAINWARP_SENTRY;
		break;
	case UNIT_TYPEID::PROTOSS_STALKER:
		return ABILITY_ID::TRAINWARP_STALKER;
		break;
	case UNIT_TYPEID::PROTOSS_ZEALOT:
		return ABILITY_ID::TRAINWARP_ZEALOT;
		break;
	default:
		return ABILITY_ID::INVALID;
		break;
	}
}

/*
returns true if the ability id represents a tech structure
*/
bool UnitData::isTechStructure(AbilityID ability)
{
	if (ability == ABILITY_ID::BUILD_CYBERNETICSCORE ||
		ability == ABILITY_ID::BUILD_TWILIGHTCOUNCIL ||
		ability == ABILITY_ID::BUILD_TEMPLARARCHIVE ||
		ability == ABILITY_ID::BUILD_ROBOTICSFACILITY ||
		ability == ABILITY_ID::BUILD_ROBOTICSBAY ||
		ability == ABILITY_ID::BUILD_STARGATE ||
		ability == ABILITY_ID::BUILD_FORGE ||
		ability == ABILITY_ID::BUILD_FLEETBEACON)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns the warpgate cooldown for the given unit type (measured in game loops)
*/
float UnitData::getWarpGateCoolDown(UnitTypeID unitType)
{
	switch (UNIT_TYPEID(unitType))
	{
	case UNIT_TYPEID::PROTOSS_ADEPT:
	case UNIT_TYPEID::PROTOSS_ZEALOT:
		return 448.0f;
		break;
	case UNIT_TYPEID::PROTOSS_STALKER:
	case UNIT_TYPEID::PROTOSS_SENTRY:
		return 515.2f;
		break;
	case UNIT_TYPEID::PROTOSS_DARKTEMPLAR:
	case UNIT_TYPEID::PROTOSS_HIGHTEMPLAR:
		return 716.8f;
		break;
	default:
		return 0;
		break;
	}
}

/*
returns true for unit types with energy-costing castable abilities
*/
bool UnitData::isCaster(UnitTypeID unitType)
{
	if ((unitType == UNIT_TYPEID::PROTOSS_HIGHTEMPLAR) ||
		(unitType == UNIT_TYPEID::PROTOSS_MOTHERSHIP) ||
		(unitType == UNIT_TYPEID::PROTOSS_ORACLE) ||
		(unitType == UNIT_TYPEID::PROTOSS_SENTRY) ||
		(unitType == UNIT_TYPEID::TERRAN_BANSHEE) ||
		(unitType == UNIT_TYPEID::TERRAN_GHOST) ||
		(unitType == UNIT_TYPEID::TERRAN_MEDIVAC) ||
		(unitType == UNIT_TYPEID::TERRAN_RAVEN) ||
		(unitType == UNIT_TYPEID::ZERG_INFESTOR) ||
		(unitType == UNIT_TYPEID::ZERG_INFESTORBURROWED) ||
		(unitType == UNIT_TYPEID::ZERG_QUEEN) ||
		(unitType == UNIT_TYPEID::ZERG_QUEENBURROWED) ||
		(unitType == UNIT_TYPEID::ZERG_VIPER) ||
		(unitType == UNIT_TYPEID::ZERG_OVERSEER))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true if the unit type is a changeling
*/
bool UnitData::isChangeling(UnitTypeID unitType)
{
	if (unitType == UNIT_TYPEID::ZERG_CHANGELING ||
		unitType == UNIT_TYPEID::ZERG_CHANGELINGMARINE ||
		unitType == UNIT_TYPEID::ZERG_CHANGELINGMARINESHIELD ||
		unitType == UNIT_TYPEID::ZERG_CHANGELINGZEALOT ||
		unitType == UNIT_TYPEID::ZERG_CHANGELINGZERGLING ||
		unitType == UNIT_TYPEID::ZERG_CHANGELINGZERGLINGWINGS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true if the attacker is able to hit the potential target
(based on unit attributes e.g. flying, not on ranges or visibility)
*/
bool UnitData::canTarget(const Unit *attacker, const Unit *potentialTarget)
{
	//filter out untargetable units and changelings
	if (isTargetable(potentialTarget->unit_type) && !isChangeling(potentialTarget->unit_type))
	{
		//for flying targets
		if (potentialTarget->is_flying)
		{
			if (canAttackAir(attacker->unit_type))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//for non-flying targets
		else
		{
			if (canAttackGround(attacker->unit_type))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	//untargetable units and changelings are ignored
	else
	{
		return false;
	}
}

/*
returns true if the unit type is able to target air units
*/
bool UnitData::canAttackAir(UnitTypeID unitType)
{
	if (unitType == UNIT_TYPEID::PROTOSS_ARCHON ||
		unitType == UNIT_TYPEID::PROTOSS_CARRIER ||
		unitType == UNIT_TYPEID::PROTOSS_INTERCEPTOR ||
		unitType == UNIT_TYPEID::PROTOSS_MOTHERSHIP ||
		unitType == UNIT_TYPEID::PROTOSS_PHOENIX ||
		unitType == UNIT_TYPEID::PROTOSS_PHOTONCANNON ||
		unitType == UNIT_TYPEID::PROTOSS_SENTRY ||
		unitType == UNIT_TYPEID::PROTOSS_STALKER ||
		unitType == UNIT_TYPEID::PROTOSS_TEMPEST ||
		unitType == UNIT_TYPEID::PROTOSS_VOIDRAY ||
		unitType == UNIT_TYPEID::TERRAN_AUTOTURRET ||
		unitType == UNIT_TYPEID::TERRAN_BATTLECRUISER ||
		unitType == UNIT_TYPEID::TERRAN_BUNKER ||
		unitType == UNIT_TYPEID::TERRAN_CYCLONE ||
		unitType == UNIT_TYPEID::TERRAN_GHOST ||
		unitType == UNIT_TYPEID::TERRAN_LIBERATOR ||
		unitType == UNIT_TYPEID::TERRAN_MARINE ||
		unitType == UNIT_TYPEID::TERRAN_MISSILETURRET ||
		unitType == UNIT_TYPEID::TERRAN_THOR ||
		unitType == UNIT_TYPEID::TERRAN_VIKINGFIGHTER ||
		unitType == UNIT_TYPEID::TERRAN_WIDOWMINE ||
		unitType == UNIT_TYPEID::TERRAN_WIDOWMINEBURROWED ||
		unitType == UNIT_TYPEID::ZERG_CORRUPTOR ||
		unitType == UNIT_TYPEID::ZERG_HYDRALISK ||
		unitType == UNIT_TYPEID::ZERG_INFESTOR ||
		unitType == UNIT_TYPEID::ZERG_INFESTORTERRAN ||
		unitType == UNIT_TYPEID::ZERG_MUTALISK ||
		unitType == UNIT_TYPEID::ZERG_QUEEN ||
		unitType == UNIT_TYPEID::ZERG_RAVAGER ||
		unitType == UNIT_TYPEID::ZERG_SPORECRAWLER)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true for units which are able to attack ground units
*/
bool UnitData::canAttackGround(UnitTypeID unitType)
{
	if (unitType == UNIT_TYPEID::PROTOSS_ADEPT ||
		unitType == UNIT_TYPEID::PROTOSS_ARCHON ||
		unitType == UNIT_TYPEID::PROTOSS_CARRIER ||
		unitType == UNIT_TYPEID::PROTOSS_COLOSSUS ||
		unitType == UNIT_TYPEID::PROTOSS_DARKTEMPLAR ||
		unitType == UNIT_TYPEID::PROTOSS_DISRUPTOR ||
		unitType == UNIT_TYPEID::PROTOSS_DISRUPTORPHASED ||
		unitType == UNIT_TYPEID::PROTOSS_HIGHTEMPLAR ||
		unitType == UNIT_TYPEID::PROTOSS_IMMORTAL ||
		unitType == UNIT_TYPEID::PROTOSS_INTERCEPTOR ||
		unitType == UNIT_TYPEID::PROTOSS_MOTHERSHIP ||
		unitType == UNIT_TYPEID::PROTOSS_MOTHERSHIPCORE ||
		unitType == UNIT_TYPEID::PROTOSS_ORACLE ||
		unitType == UNIT_TYPEID::PROTOSS_PHOTONCANNON ||
		unitType == UNIT_TYPEID::PROTOSS_PROBE ||
		unitType == UNIT_TYPEID::PROTOSS_SENTRY ||
		unitType == UNIT_TYPEID::PROTOSS_STALKER ||
		unitType == UNIT_TYPEID::PROTOSS_TEMPEST ||
		unitType == UNIT_TYPEID::PROTOSS_VOIDRAY ||
		unitType == UNIT_TYPEID::PROTOSS_ZEALOT ||
		unitType == UNIT_TYPEID::TERRAN_AUTOTURRET ||
		unitType == UNIT_TYPEID::TERRAN_BANSHEE ||
		unitType == UNIT_TYPEID::TERRAN_BATTLECRUISER ||
		unitType == UNIT_TYPEID::TERRAN_BUNKER ||
		unitType == UNIT_TYPEID::TERRAN_CYCLONE ||
		unitType == UNIT_TYPEID::TERRAN_GHOST ||
		unitType == UNIT_TYPEID::TERRAN_HELLION ||
		unitType == UNIT_TYPEID::TERRAN_HELLIONTANK ||
		unitType == UNIT_TYPEID::TERRAN_LIBERATORAG ||
		unitType == UNIT_TYPEID::TERRAN_MARAUDER ||
		unitType == UNIT_TYPEID::TERRAN_MARINE ||
		unitType == UNIT_TYPEID::TERRAN_PLANETARYFORTRESS ||
		unitType == UNIT_TYPEID::TERRAN_REAPER ||
		unitType == UNIT_TYPEID::TERRAN_SCV ||
		unitType == UNIT_TYPEID::TERRAN_SIEGETANK ||
		unitType == UNIT_TYPEID::TERRAN_SIEGETANKSIEGED ||
		unitType == UNIT_TYPEID::TERRAN_THOR ||
		unitType == UNIT_TYPEID::TERRAN_THORAP ||
		unitType == UNIT_TYPEID::TERRAN_VIKINGASSAULT ||
		unitType == UNIT_TYPEID::TERRAN_WIDOWMINE ||
		unitType == UNIT_TYPEID::TERRAN_WIDOWMINEBURROWED ||
		unitType == UNIT_TYPEID::ZERG_BANELING ||
		unitType == UNIT_TYPEID::ZERG_BANELINGBURROWED ||
		unitType == UNIT_TYPEID::ZERG_BROODLING ||
		unitType == UNIT_TYPEID::ZERG_BROODLORD ||
		unitType == UNIT_TYPEID::ZERG_DRONE ||
		unitType == UNIT_TYPEID::ZERG_HYDRALISK ||
		unitType == UNIT_TYPEID::ZERG_INFESTOR ||
		unitType == UNIT_TYPEID::ZERG_INFESTORBURROWED ||
		unitType == UNIT_TYPEID::ZERG_INFESTORTERRAN ||
		unitType == UNIT_TYPEID::ZERG_LOCUSTMP ||
		unitType == UNIT_TYPEID::ZERG_LURKERMPBURROWED ||
		unitType == UNIT_TYPEID::ZERG_MUTALISK ||
		unitType == UNIT_TYPEID::ZERG_QUEEN ||
		unitType == UNIT_TYPEID::ZERG_RAVAGER ||
		unitType == UNIT_TYPEID::ZERG_ROACH ||
		unitType == UNIT_TYPEID::ZERG_SPINECRAWLER ||
		unitType == UNIT_TYPEID::ZERG_ULTRALISK ||
		unitType == UNIT_TYPEID::ZERG_ZERGLING)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns false for unit types that can't be attacked (not including neutral units)
*/
bool UnitData::isTargetable(UnitTypeID unitType)
{
	if (unitType == UNIT_TYPEID::PROTOSS_ADEPTPHASESHIFT ||
		unitType == UNIT_TYPEID::TERRAN_KD8CHARGE ||
		unitType == UNIT_TYPEID::ZERG_PARASITICBOMBDUMMY)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*
returns true if the enemy unit is either not cloaked, or is cloaked but has been revealed
*/
bool UnitData::isVisible(const Unit *enemy)
{
	if (enemy->display_type != Unit::DisplayType::Visible || enemy->cloak == Unit::CloakState::Cloaked)
	{
		if (enemy->cloak == Unit::CloakState::Cloaked)
		{
			//std::cerr << "found a cloaked enemy" << std::endl;
		}
		return false;
	}
	else
	{
		if (enemy->cloak == Unit::CloakState::CloakedDetected)
		{
			//std::cerr << "found a detected cloaked enemy" << std::endl;
		}
		return true;
	}
}

/*
returns true if Dustin Browder loves this unit
*/
bool UnitData::isNeutralRock(const Unit *unit)
{
	if (unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLEROCKTOWERDEBRIS ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLEROCKTOWERDIAGONAL ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLEROCKTOWERPUSHUNIT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLETERRANTOWERDEBRIS ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLETERRANTOWERDIAGONAL ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLETERRANTOWERPUSHUNIT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLETERRANTOWERPUSHUNITRAMPLEFT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLETERRANTOWERPUSHUNITRAMPRIGHT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLETERRANTOWERRAMPLEFT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_COLLAPSIBLETERRANTOWERRAMPRIGHT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_DEBRISRAMPLEFT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_DEBRISRAMPLEFT ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_DESTRUCTIBLEDEBRIS6X6 ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_DESTRUCTIBLEDEBRISRAMPDIAGONALHUGEBLUR ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_DESTRUCTIBLEDEBRISRAMPDIAGONALHUGEULBR ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_DESTRUCTIBLEROCK6X6 ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_DESTRUCTIBLEROCKEX1DIAGONALHUGEBLUR ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_UNBUILDABLEBRICKSDESTRUCTIBLE ||
		unit->unit_type == UNIT_TYPEID::NEUTRAL_UNBUILDABLEPLATESDESTRUCTIBLE ||
		unit->unit_type == UNIT_TYPEID(472)) //472 is UNBUILABLEROCKSDESTRUCTIBLE
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
returns true if point a and point b are at the same location
*/
bool UnitData::isSamePoint2D(Point2D a, Point2D b)
{
	if ((a.x == b.x) && (a.y == b.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

#pragma region CustomFunctions

bool UnitData::isUsefulUnit(const Unit* unit)
{
	if (unit->unit_type == UNIT_TYPEID::PROTOSS_ZEALOT ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_STALKER ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_PHOENIX ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_VOIDRAY ||
		unit->unit_type == UNIT_TYPEID::PROTOSS_DARKTEMPLAR) {
		return true;
	}
	else
		return false;
}

bool UnitData::isUsefulStructure(const Unit* unit)
{
	if (unit->unit_type == UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE)
	{
		return false;
	}
	else
		return true;
}

UNIT_TYPEID UnitData::getClosestUnitInCost(const ObservationInterface* obs, Unit *unit)
{
	const ObservationInterface* observation_ = nullptr;

	//initialize
	UNIT_TYPEID u = unit->unit_type;

	double Mineralcost = std::numeric_limits<double>().max();
	double Gascost = std::numeric_limits<double>().max();

	//Units
	int ZealotMineralCost = 100;	int ZealotGasCost = 0;
	int ZealotTotalCost = 100 + 0;
	int StalkerMineralCost = 125;	int StalkerGasCost = 50;
	int StalkerTotalCost = 125 + 50;
	int PhoenixMineralCost = 150;	int PhoenixGasCost = 100;
	int PhoenixTotalCost = 150 + 100;
	int VoidRayMineralCost = 250;	int VoidRayGasCost = 150;
	int VoidRayTotalCost = 250 + 150;

	if (isStructure(unit)) {
		if (!isUsefulStructure(unit)) {
			return UNIT_TYPEID::PROTOSS_GATEWAY;
		}
	}
	else {
		if (!isUsefulUnit(unit)) {
			int cost = observation_->GetUnitTypeData().at(unit->unit_type).mineral_cost + observation_->GetUnitTypeData().at(unit->unit_type).vespene_cost;
			int difference = std::numeric_limits<int>().max();

			int tempDif = (cost - ZealotTotalCost);
			if (cost < ZealotTotalCost && tempDif < difference){
				u = UNIT_TYPEID::PROTOSS_ZEALOT;
			}

			tempDif = (cost - StalkerTotalCost);
			if (cost < StalkerTotalCost && tempDif < difference) {
				u = UNIT_TYPEID::PROTOSS_STALKER;
			}

			tempDif = (cost - PhoenixTotalCost);
			if (cost < PhoenixTotalCost && tempDif < difference) {
				u = UNIT_TYPEID::PROTOSS_PHOENIX;
			}

			tempDif = (cost - VoidRayTotalCost);
			if (cost < VoidRayTotalCost && tempDif < difference) {
				u = UNIT_TYPEID::PROTOSS_VOIDRAY;
			}

		}
	}

	return u;
}

bool UnitData::isEnemyArmy(const Unit * unit, const ObservationInterface *obs)
{
	auto attributes = obs->GetUnitTypeData().at(unit->unit_type).attributes;
	for (const auto& attribute : attributes) {
		if (attribute == Attribute::Structure) {
			return false;
		}
	}
	switch (unit->unit_type.ToType()) {
	case UNIT_TYPEID::ZERG_OVERLORD: return false;
	case UNIT_TYPEID::PROTOSS_PROBE: return false;
	case UNIT_TYPEID::ZERG_DRONE: return false;
	case UNIT_TYPEID::TERRAN_SCV: return false;
	case UNIT_TYPEID::ZERG_QUEEN: return false;
	case UNIT_TYPEID::ZERG_LARVA: return false;
	case UNIT_TYPEID::ZERG_EGG: return false;
	case UNIT_TYPEID::TERRAN_MULE: return false;
	case UNIT_TYPEID::TERRAN_NUKE: return false;
	default: return true;
	}
}

bool UnitData::isEnemyHarvester(const Unit * unit)
{
	switch (unit->unit_type.ToType()) {
	case UNIT_TYPEID::ZERG_DRONE: return true;
	case UNIT_TYPEID::TERRAN_SCV: return true;
	case UNIT_TYPEID::PROTOSS_PROBE: return true;
	default: return false;
	}
}

double UnitData::getTimeToProduceUpgrade(sc2::UpgradeID upgrade_id)
{
	double buildTime = 0.0;

	//double Level1 = 129;
	//double Level2 = 154;
	//double Level3 = 179;

	switch (UPGRADE_ID(upgrade_id))
	{
		//ForgeUpgrades
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL1:
		{double Level1 = 129;
		buildTime = calculateTime(Level1);
		break; }
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL1:
		{double Level1 = 129;
		buildTime = calculateTime(Level1);
		break; }
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL1:
		{double Level1 = 129;
		buildTime = calculateTime(Level1);
		break; }
		//Cybernetics Core
	case UPGRADE_ID::WARPGATERESEARCH:
		{double warpGateTime = 100;
		buildTime = calculateTime(warpGateTime);
		break; }
	case UPGRADE_ID::PROTOSSAIRWEAPONSLEVEL1:
		{double Level1 = 129;
		buildTime = calculateTime(Level1);
		break; }
	case UPGRADE_ID::PROTOSSAIRARMORSLEVEL1:
		{double Level1 = 129;
		buildTime = calculateTime(Level1);
		break; }
		//Twilight Council
	case UPGRADE_ID::BLINKTECH:
		{double BlinkTime = 121;
		buildTime = calculateTime(BlinkTime);
		break; }
	case UPGRADE_ID::CHARGE:
		{double chargeTime = 100;
		buildTime = calculateTime(chargeTime);
		break; }
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL2:
		{double Level2 = 154;
		buildTime = calculateTime(Level2);
		break; }
	case UPGRADE_ID::PROTOSSGROUNDWEAPONSLEVEL3:
		{double Level3 = 179;
		buildTime = calculateTime(Level3);
		break; }
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL2:
		{double Level2 = 154;
		buildTime = calculateTime(Level2);
		break; }
	case UPGRADE_ID::PROTOSSGROUNDARMORSLEVEL3:
		{double Level3 = 179;
		buildTime = calculateTime(Level3);
		break; }
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL2:
		{double Level2 = 154;
		buildTime = calculateTime(Level2);
		break; }
	case UPGRADE_ID::PROTOSSSHIELDSLEVEL3:
		{double Level3 = 179;
		buildTime = calculateTime(Level3);
		break; }
		//RoboticsBay
	case UPGRADE_ID::OBSERVERGRAVITICBOOSTER:
		{double graviticTime = 57;
		buildTime = calculateTime(graviticTime);
		break; }
	case UPGRADE_ID::GRAVITICDRIVE:
		{double graviticTime = 57;
		buildTime = calculateTime(graviticTime);
		break; }
	case UPGRADE_ID::EXTENDEDTHERMALLANCE:
		{double TermalLanceTime = 100;
		buildTime = calculateTime(TermalLanceTime);
		break; }
		//Fleet Beacon
	case UPGRADE_ID::PHOENIXRANGEUPGRADE:
		{double anyonPulseCrystalsTime = 64;
		buildTime = calculateTime(anyonPulseCrystalsTime);
		break; }
	case UPGRADE_ID::CARRIERLAUNCHSPEEDUPGRADE:
		{double gravitonCatapult = 57;
		buildTime = calculateTime(gravitonCatapult);
		break; }
	case UPGRADE_ID::PROTOSSAIRWEAPONSLEVEL2:
		{double Level2 = 154;
		buildTime = calculateTime(Level2);
		break; }
	case UPGRADE_ID::PROTOSSAIRWEAPONSLEVEL3:
		{double Level3 = 179;
		buildTime = calculateTime(Level3);
		break; }
	case UPGRADE_ID::PROTOSSAIRARMORSLEVEL2:
		{double Level2 = 154;
		buildTime = calculateTime(Level2);
		break; }
	case UPGRADE_ID::PROTOSSAIRARMORSLEVEL3:
		{double Level3 = 179;
		buildTime = calculateTime(Level3);
		break; }
	default:
		{buildTime = 0;
		break; }
	}

	return buildTime;
}

double UnitData::getTimeToProduceUnit(UNIT_TYPEID unit_typeId)
{
	double buildTime = 0.0;

	//double Level1 = 129;
	//double Level2 = 154;
	//double Level3 = 179;

	
	switch (UNIT_TYPEID(unit_typeId))
	{
	case UNIT_TYPEID::PROTOSS_NEXUS:
	{double t = 71;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_PYLON:
	{double t = 18;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_ASSIMILATOR:
	{double t = 21;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_GATEWAY:
	{double t = 46;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_FORGE:
	{double t = 32;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_CYBERNETICSCORE:
	{double t = 36;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_PHOTONCANNON:
	{double t = 29;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY:
	{double t = 46;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_STARGATE:
	{double t = 43;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL:
	{double t = 36;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_ROBOTICSBAY:
	{double t = 46;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_FLEETBEACON:
	{double t = 43;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE:
	{double t = 36;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_DARKSHRINE:
	{double t = 71;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_ZEALOT:
	{double t = 27;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_STALKER:
	{double t = 30;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_PHOENIX:
	{double t = 25;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_VOIDRAY:
	{double t = 43;
	buildTime = calculateTime(t);
	break; }
	case UNIT_TYPEID::PROTOSS_DARKTEMPLAR:
	{double t = 39;
	buildTime = calculateTime(t);
	break; }
	default:
	{buildTime = 0;
	break; }
	}
	
	return buildTime;
}

double UnitData::calculateTime(double time)
{
	//if faster time divide by 42.86, if fast = 50, if normal time = 60
	return (time / 60);
}

#pragma endregion
