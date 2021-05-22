/**
 * @file music_player.c
 * @author Starman
 * @brief Music processor and player
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdint.h>
#include "./notes.h"
#include "./systick.c"

#include "./songs/megalovania.h"

uint16_t calculatePeriodEnd(uint16_t number)
{
  return (number + currentMicroseconds());
}

uint16_t calculateNoteEnd(uint16_t duration)
{
  return ((duration * tickLengthMs) + currentMilliseconds());
}