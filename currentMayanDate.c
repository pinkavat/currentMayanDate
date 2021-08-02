#include <stdio.h>
#include <time.h>

/*
 * currentMayanDate.c
 *
 * Prints the current date expressed in Classical Mayan,
 * Including a five-radix long count, calendar round, 
 * and tzolk'in day prophecy.
 * 
 * Example output:
 *
 * ===== [13.0.7.4.11] 2 Chuwen 19 Pax G1 =====
 * It is The Day of The Artist: Favorable to augment all things.
 *
 * written February 2020 by Thomas Pinkava 
*/

// The Goodman-Martinez-Thompson conversion constant
#define CONVERSION_CONSTANT 584283

const char* const tzolNames[] = {"Ajaw","Imix","Ik'","Ak'bal","K'an","Chikchan","Kimi",
                                "Manik","Lamat","Muluk","Ok","Chuwen","Eb'","Ben","Ix","Men","Kib'","Kab'an","Etz'nab'","Kawak"};
const char* const haabNames[] = {"Pop","Wo","Sip","Sots'","Sek","Xul","Yaxk'in","Mol","Ch'en","Yax","Sak","Keh","Mak","K'ank'in","Muwan","Pax","K'ayab","Kumk'u","Wayeb"};
const char* const prophecies[] = {"The Day of Rulers: Favorable for offering candles.",
    "The Day of Earth: Favorable for praying on behalf of home and family.",
    "The Day of Wind: Favorable for sowing corn.",
    "The Day of Darkness: Favorable for doing evil to others.",
    "The Day of Ripeness: Favorable for harming others.",
    "The Day of the Serpent: Favorable for requesting wealth.",
    "The Day of Death: Favorable for the 'yellow cornfield'.",
    "The Day of The Hunt: Very Favorable.",
    "The Day of Seas: Favorable for all crops.",
    "The Day of Rain: Favorable for recognizing sins.",
    "The Day of The Dog: A bad day favored by sorcerers.",
    "The Day of The Artist: Favorable to augment all things.",
    "The Day of Mist: Favorable for the administration of justice.",
    "The Day of Growth: Favorable for blessing children.",
    "The Day of the Underworld: Favorable for prayers of multiplication.",
    "The Day of the Moon: Favorable for prayers for chickens and benefits.",
    "The Day of Wax: Favorable for the 'white cornfield'.",
    "The Day of Honey: Favorable for domestic animal prayers.",
    "The Day of Sacrifice: Favorable for sacrificing animals.",
    "The Day of Guardians: Favorable for compensating for damage."};

int main(void){
    // Get current Gregorian Date
    time_t t = time(NULL);
    struct tm * curTime = localtime(&t);
    int day = curTime->tm_mday;
    int month = curTime->tm_mon + 1;
    int year = curTime->tm_year + 1900;

    // Convert Gregorian Date to Mayan Day
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + (12 * a) - 3;
    int mdc = day + (((153*m)+2)/5)+(365*y)+(y/4)-(y/100)+(y/400)-32045 - CONVERSION_CONSTANT;

    // Compute Long Count
    int mdcTemp = mdc;
    int lcKin = mdcTemp % 20;
    mdcTemp /= 20;
    int lcWinal = mdcTemp % 18; // Bloody Winals ruining simple algorithms
    mdcTemp /= 18;
    int lcTun = mdcTemp % 20;
    mdcTemp /= 20;
    int lcKatun = mdcTemp % 20;
    mdcTemp /= 20;
    int lcBaktun = mdcTemp % 20;

    // Compute Calendar Round
    int tzolPos = (mdc + 159) % 260;
    int tzolTrecena = (tzolPos % 13) + 1;
    int tzolVeintena = (tzolPos + 1) % 20;

    int haabPos = (mdc + 348) % 365;
    int haabDay = haabPos % 20;
    int haabMonth = haabPos / 20;

    // Get the lord of the night
    int nightLord = mdc % 9;             
    if(nightLord == 0) nightLord = 9;

    // Finally, print result.
    printf("===== [%d.%d.%d.%d.%d] %d %s %d %s G%d =====\nIt is %s\n", lcBaktun, lcKatun, lcTun, lcWinal, lcKin, tzolTrecena, tzolNames[tzolVeintena], haabDay, haabNames[haabMonth], nightLord, prophecies[tzolVeintena]);
}
