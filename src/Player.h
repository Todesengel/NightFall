#pragma once
#include "Event.h"
#include "ClassDef.h"
#include "CustomEventResponseSet.h"
#include "Sentient.h"
#include "DM_Team.h"
#include "dgamex86.h"
#define BUTTONS_OFFSET 1724
#define NUM_DEATHS_OFFSET 2108
#define PLAYER_SIZE 2404

class Player : public Sentient //1504
{
	// can't bother to fix the offsets, I'll use direct offests & dummies
	// for info about offsets, check Player.txt
	// 
	
	uint8_t pfiller1[BUTTONS_OFFSET - sizeof(Sentient)];
	int buttons;
	uint8_t pfiller2[NUM_DEATHS_OFFSET - BUTTONS_OFFSET - sizeof(buttons)];
	int num_deaths;
	int num_kills;
	uint8_t pfiller3[PLAYER_SIZE - sizeof(num_kills) - sizeof(num_deaths) - NUM_DEATHS_OFFSET];
public:
	Player();
	~Player();
	static ResponseDef<Player>	*Responses;
	static CustomEventResponseSet<Player> cerSet;
	static void PrintOffsets();
	static void Init();
	static void Shutdown();

	static void(__thiscall *Respawn_Orignal)(Player*_this, Event *ev);
	static void(__thiscall *Killed_Orignal)(Player*_this, Event *ev);

	void Test(Event * ev);
	
	static void		MiscInit();

	void GetKillsEvent(Event * ev);
	void GetDeathsEvent(Event * ev);
	void GetConnStateEvent(Event * ev);
	void GetActiveWeapEvent(Event * ev);
	void SecFireHeldEvent(Event * ev);
	void GetUserInfoEvent(Event * ev);
	void GetInventoryEvent(Event * ev);
};

void __fastcall Respawn(Player *_this, void * edx, Event * ev);
void __fastcall Killed(Player *_this, void * edx, Event * ev);
