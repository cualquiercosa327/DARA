DARA
====
An attempt to exploit every single FIFA game on the DS (all regions) to run unsigned code through its save file.

Currently there is complete support for running code through the following games:

- FIFA 06 (E),
- FIFA 07 (E and U),
- FIFA 08 (E),
- FIFA 09 (E),
- FIFA 10 (E),
- FIFA Street 2 (E and U),
- FIFA Street 3 (E),

### Usage

Run `make` on the `CRCFix` directory to build CRCFix. This will be used to fix the checksum of a save file to stop it from showing up as corrupt in the game.

Run `make` on the `Exploit` directory to build the exploitable save games.

### Activating the exploit

For FIFA 06, activate the exploit by going to "My Club", "Edit My Club".

For FIFA 10, activate the exploit by going to "My FIFA 10", "Creation Zone", and then "My Custom Club".

For FIFA Street 2, activate the exploit by going to "My Street", "Profile", and then "Edit Profile".

For FIFA Street 3, activate the exploit by going to "Multiplayer", "Host Game", and then "Yes".

For all other supported games, activate the exploit by going to "My FIFA (year)", and then "My Profile".

### Partially supported games

FIFA 11 (E) CRC fixing support is added.

You can place about 160 - 170 bytes of thumb code that does not contain any 0 bytes at `0x000005d4` in CRCFix/FIFA11E.sav.

Hopefully this will be enough to load an ARM payload from EEPROM into RAM and jump to it.

To activate this exploit, go to "MULTIPLAYER", "NINTENDO WI-FI CONNECTION", and then "CONNECT TO NINTENDO WFC".

### Problem games

FIFA World Cup 2006 (E) CRC fixing support is added, but the game doesn't crash with a large name.