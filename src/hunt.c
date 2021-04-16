//VELEA FLORIAN GRUPA315CD



#include "hunt.h"
#include <stdio.h>

/* Task 1 - Axii */

uint16_t find_spell(uint64_t memory)
{
    /*
     * The spell is 16 bits and they are in the memory exactly after 5
     * consecutive bits of 1:
     *
     *            high                                             low
     *                [][][x]...[x][x][x][1][1][1][1][1][]...[][][]
     *                    |----16bits---|
     *                          Spell
     *
     * There is only 1 group of 5 consecutive bits of 1 and the other groups
     * have less than consecutive bits of 1
     * Steps:
     * - find 5 consecutive bits of 1
     * - the NEXT 16 bits == spell
     */

    uint64_t  mask = 0, i = 0, j = 0, spell =0, bit = 0;
    unsigned long x = 1;

    /* TODO */
        for( i = 0; i <= 63; i++) {

            mask = memory;
            bit = mask & ( x << i);
            if( bit > 0){
                ++j;

            }
            else
            {
                j = 0;
            }
            if( j == 5){
                i = i + 1;
                mask = mask >> i;
                break;
            }

        }
        for(i = 0; i <= 15; i++){

            spell = spell + (mask & (x << i));

        }
    return spell;
}



uint16_t find_key(uint64_t memory)
{
    /*
     * The key is 16 bits and they are in the memory exactly before 3
     * consecutive bits of 1:
     *
     *                high                                           low
     *                     [][][][1][1][1][x][x]...[x][x][]...[][][]
     *                                    |----16bits---|
     *                                           Key
     * Steps:
     * - find 3 consecutive bits of 1
     * - the PREVIOUS 16 bits == key
     */


    uint64_t mask =  0, bit = 0,res = 0, i = 0, j = 0, key = 0;

    /* TODO */
    mask = memory;
    for( i = 0; i <= 63; i++) {

        bit = mask & ((unsigned long)1 << i);
        if( bit >= 1)
            j++;
        else
            j = 0;

        if (j == 3) {

        mask = mask >> (i-18);
        break;
        }

    }

    for (i = 0; i <= 15; i++) {

        key = key + (mask & (1<<i));

    }

    res = key;
    return res;
}


uint16_t decrypt_spell(uint16_t spell, uint16_t key)
{
    /*
     * Find the spell knowing that
     * spell_encrypted = spell_plaintext ^ key
     */

    uint16_t res = -1;


    /* TODO */

    return res = spell ^ key;
}


/* Task 2 - Sword Play */

uint32_t choose_sword(uint16_t enemy)
{
    /*
     * Help Geralt construct a sword that will give him an advantage in battle.
     * The steps we will follow:
     * - choose the corect sword
     * - brand the sword with the correct runes such that the equation
     * for that specific enemy type is true
     *
     * How does the sword look (Sword template):
     *  [][][][] [0][0][0]...[0][0][0] [][][][][][][][][][][][][][][][]
     *  -------- --------------------- --------------------------------
     *     Type    Does not matter      The "Value" such that the equation
     *                               from 2 holds depending on the enemy type
     *    4 bits      12 bits                     16 bits
     *
     * 1. Type of the sword:
     * - 1001 - Silver Sword - for monsters
     * - 0110 - Steel Sword - for humans
     *
     *  If the number of active bits from variable "enemy" is even == Monster
     *  else == Human
     *
     * 2.
     * Monster Equation:
     *    Value ^ (Enemy & (1 - Enemy)) = 0
     *
     * Human Equation:
     *    Value + Enemy = 0
     */

    uint16_t i = 0, j = 0, monster = 0, human = 0, x = 0;
    uint16_t value = 0;
    uint32_t sword = 0;

    /* TODO */

    for( i = 0; i < 8*sizeof(enemy); i++){
        x = enemy & (1<<i);
        if( x >= 1)
            j++;

    }
    if (j%2 == 0)
        monster = 1;
    else
        human = 1;
    if ( human == 1){

        value = (1+(~enemy));

    }
    if (monster == 1) {
        value = enemy & (2 + (~enemy));
    }
        if( human == 1)
        sword = value + (6<<28);
        if( monster == 1)
        sword = value + (9<<28);

    return sword;
}


/* Task 3 - The Witcher Trials */

uint32_t trial_of_the_grasses(uint16_t cocktail)
{
    /*
     * To become a witcher one must survive a cocktail of different
     * herbs. The body should generate the correct antibodies to
     * neutralize the given cocktail.
     *
     *
     * The antibodies need to respect the following properties:
     *   (antibodies_high & cocktail) ^ (antibodies_low | cocktail) = 0
     *   antibodies_low & antibodies_high = 0
     *   antibodies_low | antibodies_high = cocktail
     *
     * Where:
     *  [][][]...[][][] | [][][]...[][][]
     *  ---------------   ---------------
     *  antibodies_high    antibodies_low
     *      16 bits           16 bits
     *      -------------------------
     *              antibodies
     */

    uint32_t res = -1;

    /* TODO */

    res = cocktail<<16;

    return res;
}


uint8_t trial_of_forrest_eyes(uint64_t map)
{
    /*
     * For the next trail, the candidate is tied up and blindfolded.
     * They are also taken to a forest and they should return until
     * the next morning.
     *
     * The candidate knows that there are 4 possibilities for the forest:
     * Brokilon, Hindar, Wolven Glade and Caed Dhu.
     *
     * The candidate also knows those forests by heart, but first you
     * need to identify the forest.
     *
     * The characteristics for 3 of the forests are as follows:
     * - Brokilon - has ONLY groups of 4 trees (or a forest without any tree)
     *   Ex: a group of 4 trees: "...00111100..."
     * - Hindar - has ONLY 2 trees in the MIDDLE
     * - Wolven Glade - FULL of trees
     *
     * The "map" variable encodes the following information:
     * - 1 tree
     * - 0 patch of grass
     *
     * You should put in the "res" variable the index for the identified
     * forrest.
     * - Brokilon - index 0
     * - Hindar - index 1
     * - Wolven Glade - index 2
     * - Caed Dhu - index 3
     */
    uint64_t mask = map, i=0, j = 0, k = 0;
    for( i = 0; i <= 63; i++) {

        if ((mask & (1 << i)) >= 1)
            j++;
        if ( j == 64)
            return 2;
            if((mask & (1 << i)) >= 1)
            k++;
    }
    j = 0;

    for( i = 0; i <=63; i++) {

        if((mask & (1 << i)) >= 1) {
            if ((mask & (1<< (i+1))) >= 1){
                if( (mask & (1 <<(i+2))) >= 1){
                    if( (mask & (1 <<(i+3))) >=1)
                        j = 1;
                }
                else break;
            }
            else break;
        }

    }
    if (mask == 0)
        return 0;
    if (j == 1)
            return 0;

    if ( (mask & (1 << 31)) >= 1 && (mask & (1UL <<32)) >= 1 && k == 2)
        return 1;

    return 3;


    uint8_t res = -1;

    /* TODO */


    return res;
}


uint8_t trial_of_the_dreams(uint32_t map)
{
    /*
     * For this final trial, the candidates go into a trance and when
     * they woke up they would be a fully fledged witcher.
     *
     * For this task, you need to help the witcher find the number
     * of steps that would take the candidate from the dream realm to
     * the real world.
     *
     * The "map" variable would have only 2 bits of 1:
     * - candidate location
     * - portal location
     *
     * You should put in the "res" variable the distance from the
     * candidate position to the portal.
     *
     *  Ex:
     *  [0][0][0][0][0][0]....[1][0][0][0][0][1][0]....[0][0][0]
     *
     *  res = 5
     */
    uint32_t i = 0, j = 0;
    for( i = 0; i <= 31; i++) {

        if ((map & (1<<i)) >= 1){

            for(j = i+1; j <= 31; j++){

                if((map & (1<<j)) >= 1)
                    return j-i;
            }

        }



    }

    uint8_t res = -1;

    /* TODO */

    return res;
}
