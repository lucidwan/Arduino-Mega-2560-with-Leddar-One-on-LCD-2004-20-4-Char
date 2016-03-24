# Arduino-Mega-2560-with-Leddar-One-on-LCD-2004-20-4-Char
Functional Leddar one using LCD 2004 shield for readout on Mega 2560

I'm looking to use a Leddar One lidar with my Hexacopter for rangefinding and collision avoidance.
And since there are virtually no code examples short of the vague examples included with the leddar one,
not to mention little support from the product's creators, I set out to figure this thing out.

What I want to do now is to interface the mega with my Pixhawk flight controller - which will pass-thru this
data to mavlink, or even better, incorporate it onboard Pixhawk somehow, for range and collision detection.
If you have knowledge on this PLEASE don't hesitate to get hold of me.

This is step one which as a beginner with arduino became quite an obstacle, due stictly to the crappy documentation
of this particular LCD shield.

So, as well as the leddar, I'm providing functional LCD V2004 code in the LeddarOneLCD2004 sketch.

The lcd requires the latest "NewLiquidCrystal" library and I'll scream this, as I missed it over a few attempts
YOU MUST USE THIS LIBRARY AND YOU MUST MAKE SURE TO #include LiquidCrystal_I2C.h
don't forget the "I2C"
These LCD's apparently work on several different addresses - mine is 0x27 although it appears many are 0x3F.

I'll link the connection diagram I've drawn in cad as well as a short youtube vid showing it functioning.

The Leddar One portion is from the "Simple Leddar One" Example sketch included with the Leddar One library - available from
playground or from Leddar One support site.
