# Current Mayan Date

What's the first piece of information any programmer needs to see upon opening their terminal emulator? 

The last login time? The working directory?

Wrong! It's the auspices of a long-dead jungle-dwelling civilization who hadn't the slightest notion of electronic computing.

...at least that's the case for some of us.
If you, too, feel the need to know what the Mayans would have called the current date, then this widget is for you.



*Want to see the associated hieroglyphs? Check out [my calculator website](https://polar-gorge-17146.herokuapp.com/)!*

*For an old Java applet date-calculation suite, see [here](https://github.com/pinkavat/MayanDateCalculator).*

## Installation

Download [currentMayanDate.c](currentMayanDate.c) and compile it with any C compiler.
There are no dependencies beyond the standard libraries.

## Usage

Running the resulting executable will compute Mayan Calendar information for the 
current date and print it to `stdout`, formatted thus:

```
===== [Long Count] <Tzolk'in><Haab'> <Lord of the Night> =====
<Modern Yucatec prophecy associated with the Tzolk'in day>
```

for example:

```
===== [13.0.7.4.11] 2 Chuwen 19 Pax G1 =====
It is The Day of The Artist: Favorable to augment all things.
```


