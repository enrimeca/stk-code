//  $Id: race_track_time.cpp 1259 2007-09-24 12:28:19Z hiker $
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2008 Joerg Henrichs
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be ruseful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <algorithm>
#include "challenges/race_track_time.hpp"
#include "world.hpp"
#include "race_manager.hpp"

RaceTrackTime::RaceTrackTime() : Challenge("racetracktime", "Finish Race track in 1:15")
{
    setChallengeDescription("Finish 3 laps in the Race track\nwith 3 AI karts\nin under 1:15 minutes.");
    setFeatureDescription("New game mode\n'Follow Leader'\nnow available");
    setFeature("followleader");
}   // RaceTrackTime

//-----------------------------------------------------------------------------
void RaceTrackTime::setRace() const {
    race_manager->setRaceMode(RaceManager::RM_QUICK_RACE);
    race_manager->setTrack("race");
    race_manager->setDifficulty(RaceManager::RD_EASY);
    race_manager->setNumLaps(3);
    race_manager->setNumKarts(4);
    race_manager->setNumPlayers(1);
}   // setRace

//-----------------------------------------------------------------------------
bool RaceTrackTime::raceFinished()
{
    std::string track_name = world->getTrack()->getIdent();
    if(track_name!="race"      ) return false;    // wrong track
    Kart* kart=world->getPlayerKart(0);
    if(kart->getFinishTime()>75) return false;    // too slow
    if(kart->getLap()!=3       ) return false;    // wrong number of laps
    if(race_manager->getNumKarts()<4) return false; //not enough AI karts
    return true;
}   // raceFinished
//-----------------------------------------------------------------------------
