#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_CRC 4

struct game {
	char name[32];
	unsigned int magic;
	unsigned int crcOffset[MAX_CRC];
	unsigned short (*crcCalculation[MAX_CRC])(unsigned char *data);
};

unsigned short fifa06emyclubcrc(unsigned char *data);
unsigned short fifa07ecrc(unsigned char *data);
unsigned short fifa07ucrc(unsigned char *data);
unsigned short fifa08ecrc(unsigned char *data);
unsigned short fifa09ecrc(unsigned char *data);
unsigned short fifa10ecrc(unsigned char *data);
unsigned short fifa10etournamentscrc(unsigned char *data);
unsigned short fifa10emyclubcrc(unsigned char *data);
unsigned short fifa11emyprofilecrc(unsigned char *data);
unsigned short fifa11eoptionscrc(unsigned char *data);
unsigned short fifa11edefaultrostercrc(unsigned char *data);
unsigned short fifa11ecustomformationscrc(unsigned char *data);

unsigned short fifaStreet2ecrc(unsigned char *data);
unsigned short fifaStreet2ucrc(unsigned char *data);
unsigned short fifaStreet3ecrc(unsigned char *data);

unsigned short fifaWorldCup2006e(unsigned char *data);

struct game games[] = {
	{
		name: "FIFA 06 E",
		magic: 0xF1FA06AA,
		crcOffset: { 0x10 },
		crcCalculation: { fifa06emyclubcrc, NULL },
	},
	
	{
		name: "FIFA 07 E",
		magic: 0xF1FA07BF,
		crcOffset: { 0x0A },
		crcCalculation: { fifa07ecrc, NULL },
	},
	
	{
		name: "FIFA 07 U",
		magic: 0xF1FA07BD,
		crcOffset: { 0x0A },
		crcCalculation: { fifa07ucrc, NULL },
	},
	
	{
		name: "FIFA 08 E",
		magic: 0x10071981,
		crcOffset: { 0x04 },
		crcCalculation: { fifa08ecrc, NULL },
	},
	
	{
		name: "FIFA 09 E",
		magic: 0x10071982,
		crcOffset: { 0x04 },
		crcCalculation: { fifa09ecrc, NULL },
	},
	
	{
		name: "FIFA 10 E",
		magic: 0x10071983,
		crcOffset: { 0x04, 0x06, 0x10 },
		crcCalculation: { fifa10ecrc, fifa10etournamentscrc, fifa10emyclubcrc, NULL },
	},
	
	{
		name: "FIFA 11 E",
		magic: 0x93633892,
		crcOffset: { 0x000005d2, 0x000006a4, 0x0000924a, 0x0000cb5a },
		crcCalculation: { fifa11emyprofilecrc, fifa11eoptionscrc, fifa11edefaultrostercrc, fifa11ecustomformationscrc },
	},
	
	{
		name: "FIFA Street 2 E",
		magic: 0xF1FA06AA,			// FIFA Street 2 E and FIFA 06 E use the same magic...
		crcOffset: { 0x0A },
		crcCalculation: { fifaStreet2ecrc, NULL },
	},
	
	{
		name: "FIFA Street 2 U",
		magic: 0xF1FA06EE,
		crcOffset: { 0x0A },
		crcCalculation: { fifaStreet2ucrc, NULL },
	},
	
	{
		name: "FIFA Street 3 E",
		magic: 0x0BADB00B,			// EA...
		crcOffset: { 0x06 },
		crcCalculation: { fifaStreet3ecrc, NULL },
	},
	
	{
		name: "FIFA World Cup 2006 (E)",
		magic: 0xF1FA06AC,
		crcOffset: { 0x0A },
		crcCalculation: { fifaWorldCup2006e, NULL },
	}
};

unsigned short fifa06emyclubcrc(unsigned char *data) {
	unsigned short crc = 21;
	
	int i;
	for(i = 0x000003b8; i < 0x00001150; i++) {
		crc += data[i] * (0x00001150 - (i & ~0x3));
	}
	
	return crc;
}

unsigned short fifa07ecrc(unsigned char *data) {
	unsigned short crc = 26;
	
	int i;
	for(i = 0x00000028; i < 0x0000026C; i++) {
		crc += data[i] * (0x0000026C - (i & ~0x3));
	}
	
	return crc;
}

unsigned short fifa07ucrc(unsigned char *data) {
	unsigned short crc = 24;
	
	int i;
	for(i = 0x00000028; i < 0x0000026C; i++) {
		crc += data[i] * (0x0000026C - (i & ~0x3));
	}
	
	return crc;
}

unsigned short fifa08ecrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x00000044; i < 0x000002C4; i++) {
		crc += data[i] * (0x000002C4 - (i & ~0x3));
	}
	
	return crc;
}

unsigned short fifa09ecrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x00000020; i < 0x0000010C; i++) {
		crc += data[i] * (0x0000010C - i);
	}
	
	return crc;
}

unsigned short fifa10ecrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x00000040; i < 0x00000110; i++) {
		crc += data[i] * (0x00000110 - i);
	}
	
	return crc;
}

unsigned short fifa10etournamentscrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x00000110; i < 0x000005f8; i++) {
		crc += data[i] * (0x000005f8 - i);
	}
	
	return crc;
}

unsigned short fifa10emyclubcrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x0000d8fc; i < 0x0000e1b8; i++) {
		crc += data[i] * (0x0000e1b8 - i);
	}
	
	return crc;
}

unsigned short fifa11emyprofilecrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x000005d4; i < 0x000006a4; i++) {
		crc += data[i] * (0x000006a4 - i);
	}
	
	return crc;
}

unsigned short fifa11eoptionscrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x000006a6; i < 0x00000716; i++) {
		crc += data[i] * (0x00000716 - i);
	}
	
	return crc;
}

unsigned short fifa11edefaultrostercrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x00000924c; i < 0x0000c370; i++) {
		crc += data[i] * (0x0000c370 - i);
	}
	
	return crc;
}

unsigned short fifa11ecustomformationscrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x0000cb5c; i < 0x0000cd0c; i++) {
		crc += data[i] * (0x0000cd0c - i);
	}
	
	return crc;
}

unsigned short fifaStreet2ecrc(unsigned char *data) {
	unsigned short crc = 49491;
	
	int i;
	for(i = 0x00000010; i < 0xFD4; i++) {
		crc += data[i] * (0xFD4 - (i & ~0x3));
	}
	
	return crc;
}

unsigned short fifaStreet2ucrc(unsigned char *data) {
	unsigned short crc = 49485;
	
	int i;
	for(i = 0x00000010; i < 0x00000FD4; i++) {
		crc += data[i] * (0x00000FD4 - (i & ~0x3));
	}
	
	return crc;
}

unsigned short fifaStreet3ecrc(unsigned char *data) {
	unsigned short crc = 19;
	
	int i;
	for(i = 0x00000010; i < 0x00000E24; i++) {
		crc += data[i] * (0x00000E24 - i);
	}
	
	return crc;
}

unsigned short fifaWorldCup2006e(unsigned char *data) {
	unsigned short crc = 61929;
	
	int i;
	for(i = 0x00000040; i < 0x00000290; i++) {
		crc += data[i] * (0x00000290 - (i & ~0x3));
	}
	
	return crc;
}

int main(int argc, char **argv) {
	bool askBeforeFixing = true;
	
	if(argc < 2) {
		printf("FIFA DS save CRC fixer\n");
		printf("Usage:\n");
		printf("CRCFix save.sav [-f]\n");
		printf(" -f: fix CRC without asking confirmation\n");
		return 1;
	}
	
	if(argc == 3 && !strcmp(argv[2], "-f")) {
		askBeforeFixing = false;
	}
	
	printf("File: %s\n", argv[1]);
	
	FILE *f = fopen(argv[1], "r+wb");
	
	if(!f) {
		printf("Failed to open\n");
		fclose(f);
		return 1;
	}
	
	unsigned int magic;
	fread(&magic, sizeof(unsigned int), 1, f);
	
	unsigned char street2eIdentifier; // Since FIFA 06 E and FIFA Street 2 E have the same magic, we have to do check this byte as well
	fseek(f, 0x00000034, SEEK_SET);
	fread(&street2eIdentifier, sizeof(unsigned char), 1, f);
	
	int i;
	for(i = 0; i < sizeof(games) / sizeof(struct game); i++) {
		if(magic == games[i].magic) {
			if(strcasecmp(games[i].name, "FIFA 06 E") == 0) {
				if(street2eIdentifier != 0x01) break; // not Street 2 E
			}
			else {
				break;
			}
		}
		else if(i == sizeof(games) / sizeof(struct game) - 1) {
			printf("Unrecognised game save\n");
			printf("(magic %p)\n", magic);
			fclose(f);
			return 1;
		}
	}
	
	printf("%s save file detected\n", games[i].name);
	
	fseek(f, 0, SEEK_END);
	size_t length = ftell(f);
	unsigned char *data = malloc(length);
	
	if(!data) {
		printf("Couldn't allocate %d bytes\n", length);
		fclose(f);
		return 1;
	}
	
	rewind(f);
	fread(data, length, 1, f);
	
	int j;
	for(j = 0; j < MAX_CRC; j++) {
		if(!games[i].crcCalculation[j]) break;
		
		unsigned short currentCrc = *(unsigned short *)(data + games[i].crcOffset[j]);
		
		printf("Current CRC (%d)    : 0x%p\n", j, currentCrc);
		
		unsigned short crc = games[i].crcCalculation[j](data);
		
		printf("Calculated CRC (%d) : 0x%p\n", j, crc);
		
		printf("Difference : %d\n", currentCrc - crc);
		
		if(currentCrc != crc) {
			if(askBeforeFixing) {
				printf("Incorrect CRC, press enter to fix\n");
				getchar();
			}
			
			fseek(f, games[i].crcOffset[j], SEEK_SET);
			fwrite(&crc, sizeof(unsigned short), 1, f);
		}
	}
	
	free(data);
	fclose(f);
	return 0;
}
