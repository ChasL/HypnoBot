/*
#define PtInRectAddy    0x01272D3C
#define ItemHookCMPAddy 0x005A338C

#define HPMPBase 0x01267C0C
#define HPOff 0x00002200
#define MPOff 0x00002204
#define ExpOff 0x00002130

#define AlertBase 0x01267B34
#define HPAlertOff 0x00000050
#define MPAlertOff 0x00000054

#define CharBase 0x012632FC
#define CharXOff 0x00008AE8
#define CharYOff 0x00008AEC
#define TeleOff 0x0
#define TeleXOff 0x0
#define TeleYOff 0x0
#define FAOff 0x78B8
#define ItemIDOff 0x00007860
#define AtkCountOff 0x00007B40
#define BuffCountOff 0x00007B50
#define MorphOff 0x0
#define BreathOff 0x00000718
#define CharAnimOff 0x0000071C

#define MobBase 0x01267B3C
#define MobCountOff 0x10 
#define Mob1Off 0x00000028
#define Mob2Off 0x00000004
#define Mob3Off 0x0000016C
#define Mob4Off 0x00000024
#define MobXOff 0x00000058
#define MobYOff 0x0000005C
#define MobDeathOff 0x00000560

#define MouseBase 0x01267FD0
#define MouseAnimOff 0x000009CC
#define MouseLocOff 0x00000978
#define MouseXOff 0x0000008C
#define MouseYOff 0x00000090

#define ServerBase 0x012632F8
#define WorldOff 0x000020A4
#define ChannelOff 0x000020AC
#define TubiOff 0x00002118

#define MapInfoBase 0x012683B0
#define MapIDOff 0x000011E4

#define PeopleBase 0x01267B38
#define PeopleAmtOff 0x00000018

#define WallBase 0x01267AA8
#define LeftWallOff 0x1C 
#define TopWallOff 0x20 
#define RightWallOff 0x24 
#define BottomWallOff 0x28 

#define ItemBase 0x0126BE48
#define ItemAmtOff 0x00000014

#define FMAAddy 0x0079CD81
#define FGMAddy 0x0079C3CC
#define Silence1Addy 0x00792335
#define Silence2Addy 0x0079235E
#define Silence3Addy 0x00792383
#define Silence4Addy 0x007923B4
#define Silence5Addy 0x0076F772

#define UnlimKaiserCast			  0x00CE0804 // 81 FE E0 7A A4 03 74 ? 81 FE 08 9E A4 03 75
#define UnlimKaiserGauge		  0x00CE0F95 // 3B C8 7D ? 8D
#define FullGodMode 0x0
#define FLEnterMap 0x0
#define MultiDamage 0x00DC894C
#define HideLoginInfo 0x00550F2C
#define InstantAirLoot 0x005A3339
#define NoKnockBack 0x00933FEB
#define InstantDrop 0x005A0EC5
#define UnlimAttack 0x00C6DD60
#define SlowMobs 0x007BC66B
#define NoMobLag 0x007BD664
#define HideDamage 0x00771343
#define NoLootAnimation 0x00460259
#define CPUBackGround1 0x0074095B
#define CPUBackGround2 0x00741269
#define CPUPlatforms 0x00745FE9
#define NoAtkLimit 0x00C6DD80
#define NDFAAddy 0x00CD651D
#define ItemVacAddy 0x0075D594

#define StatHook 0x0

/*#define CClientSocket  0x011668A4		 // 8B 0D ? ? ? ? 8D 44 24 ? 50 E8 ? ? ? 00 83 BE ? 00 00 00 00 75
#define MSSendPacket   0x004F3A90		 // 4 bytes below SendClassAddy
#define SendRet        0x00435978		 // 03 C0 C3 CC CC CC CC CC 8B 44 24 ? 8B 4C 24 ? 8B 54 24 ? 56 8B
#define LastThreadID   0x00EC5B38		 // 3B 05 ? ? ? ? 68 ? ? ? ? 8D 64 24 ? 0F 85 ? ? ? ? 60 64 A1 ? ? ? ? E8 | 0110EA53

#define ItemHookCMPAddy 0x0059EEBC       // 85 C0 75 4E 8D 4C ? ? C7 44 24 ? ? ? ? ? E8
#define PtInRectAddy    0x012473EC       // Go to address PtInRect and then 4 byte scan it

#define HPMPBase       0x0123C9E4		 // 8B 0D ? ? ? ? 52 6A ? 56 E8 ? ? ? ? 8B BF
#define HPOff           0x2200			 // 89 8E ? ? 00 00 80 BE ? ? 00 00 00 75 52 8B
#define MPOff           0x2204			 // HPOff + 4
#define ExpOff			0x2130			 // DD 9E ? ?  00 00 33 FF 66 89 4C 24 ? 89

#define AlertBase      0x0123C90C		 // 8B 15 ? ? ? ? 8B 4A ? 8D 0C 89 85 C9 74 27 8B
#define HPAlertOff      0x50			 // 8B 48 ? 8d 0C 89 85 C9 74 27 8B ? ? 8B
#define MPAlertOff      0x54			 // HPAlertOff + 4

#define CharBase       0x012380D4        // 8B ? ? ? ? ? 85 C9 74 ? 83 B8 ? ? ? ? 00 74 ? 8B ? ? ? ? ? 85 C0 7E ? 8B
#define CharXOff        0x8998			 // 89 8E ? ? ? ? 8B 50 ? 8B 06 89 96 ? ? ? ? 8B 50
#define CharYOff        0x899C			 // CharXOff + 4
#define TeleOff         0x77B8			 // 83 BE ? ? ? ? 00 89 44 ? ? 0F 84 ? ? ? ? 8B
#define TeleXOff        0x77C0			 // 8B 8E ? ? 00 00 51 6A 00 ? ? FF D2 8B ? ? ? 00 00 8D BE ? ? ? ? 8D ? ? 50 8B
#define TeleYOff        0x77C4			 // TeleXOff + 4
#define FAOff			0x7788
#define ItemIDOff       0x7730			 // 89 A9 ? ? 00 00 8B 40 ? C7 44 24 ? ? ? ? ? 85 C0
#define AtkCountOff     0x79F0			 // 89 ? ? ? 00 00 C7 ? ? ? 00 00 ? 00 00 00 89 ? ? ? 00 00 89 ? ? ? 00 00 89 ? ? ? 00 00 C7 ? ? ? 00 00 ? 00 00 00 89 ? ? ? 00 00 8D
#define BuffCountOff    0x7A00			 // Attack Count + 16
#define MorphOff		0x69C            // 8B 81 ? ? ? ? 56 8D B1 ? ? ? ? 85 C0 74 ? 50 E8
#define BreathOff       0x710			 // 83 B8 ? ? ? ? 00 7E ? 6A 00 6A 00 6A 00 6A 00
#define CharAnimOff		0x714			 // Breath + 4
#define PIDOff			0x2B44			 // 89 9E ? ? 00 00 89 9E ? ? 00 00 FF D7 8D 4C 24 ? 68 ? ? ? ? 51
#define FaceDirOff		0x2608

#define MobBase        0x0123C914        // 8B 0D ? ? ? ? E8 ? ? ? ? 8B F8 89 7C 24 ? 85 FF
#define MobCountOff     0x10
#define Mob1Off         0x28             // 89 7E ? 89 7E ? ? ? ? ? ? 89 46 ? 89 46 ? 89 7E ? 89 7E ? 89 7E ? 89 ? ? 89
#define Mob2Off			 0x4			 // 89 7B ? 89 5C 24 ? E8 ? ? ? ? C7 ? ? ? FF FF FF FF 85 FF 74 ? 6A 00 8D
#define Mob3Off			  0x16C			 // 89 9E ? ? 00 00 89 9E ? ? 00 00  89 9E ? ? 00 00 89 9E ? ? 00 00 89 9E ? ? 00 00 C7 86 ? ? 00 00 ? ? ? ? 89 9E ? ? 00 00 89 9E ? ? 00 00 89 9E ? ? 00 00 8B 44 24 ? 8D
#define Mob4Off			   0x24			 // 89 5C ? ? C7 01 ? ? ? ? 89 59 ? C7
#define MobXOff             0x58		 // 89 ? ? DD ? ? 39 ? ? 75 ? 6A ? 8D ? ? 00 00 00 52 ? ? E8 ? ? ? ? EB ? 33
#define MobYOff				0x5C		 // MobX + 4
#define MobDeathOff     0x560			 // 89 86 ? ? ? ? 89 86 ? ? ? ? 33 C0 89 86

#define MouseBase      0x0123CDA8        // 8B 0D ? ? ? ? 74 12 83 B9 ? ? ? ? ? 74 09 6A ? 6A ? E8
#define MouseAnimOff    0x9CC			 // 8B 87 ? ? ? ? 8B 4C 24 ? 3B C1
#define MouseLocOff     0x978			 // 8B B1 ? ? ? ? 85 F6 75 ? 68 ? ? ? ? E8 ? ? ? 00 8B 4C 24 ? 8B 06 8B 90 ? ? ? ? F7 D9
#define MouseXOff        0x8C			 // 8B 88 ? ? ? ? 6A ? 57 83 C5 ? 55
#define MouseYOff        0x90			 // MouseX + 4

#define ServerBase     0x012380D0		 // 8B ? ? ? ? ? A1 ? ? ? ? 8D ? ? ? 51 8B CD 89 44 24 ? E8 ? ? ? ? 8B 70
#define WorldOff        0x20A4			 // 8B 8F ? ? ? ? 8B 00 51 50 6A ? 8B CE C7 44 24 ? ? ? ? ? E8 << 1st
#define ChannelOff      0x20AC			 // WorldOff + 8 (Or 2nd addy from WorldOff AoB)
#define TubiOff         0x2118			 // 83 ? ? ? ? ? 00 75 ? 83 7C ? ? 00 75 ? 8B ? ? ? ? ? 8B ? ? 51 83 C0 ? 50

#define MapInfoBase    0x0123D178        // 8B ? ? ? ? ? 53 E8 ? ? ? ? 8B 44 ? ? C7 44 24 1C FF FF FF FF 85 C0 74 ? 83 C0
#define MapIDOff        0x11E4           // 8B ? ? ? ? ? 50 51 8B 0D ? ? ? ? 8D ? ? ? 52 C6 84 ? ? ? ? ? 03 E8
#define CharXOff2		0xFE8
#define CharYOff2		0xFEC

#define PeopleBase     0x0123C910        // 8B ? ? ? ? ? 50 E8 ? ? ? ? ? ? ? ? 0F 84 ? ? ? ? 39 ? ? ? ? ? 0F 85
#define PeopleAmtOff    0x18			 // 8B ? ? ? ? 7C ? 83 ? ? 7D ? 8B ? ? ? ? ? 8B 74 ? ? ? ? 74 ? 8B ? ? 8B

#define WallBase       0x0123C888        // 8B ? ? ? ? ? 8B ? ? 8B ? ? ? ? ? 85 C0 74 ? 8B ? ? 48 ? ? 76 ? 6A
#define LeftWallOff     0x1C			 // 8B ? ? ? 50 E8 ? ? ? ? ? ? 75 ? 8B 44 ? ? C7 40 ? 00 00 00 00 ? ? ? 0F 82
#define TopWallOff      0x20			 // LeftWall + 4
#define RightWallOff    0x24			 // TopWall + 4
#define BottomWallOff   0x28			 // RightWall + 4

#define ItemBase       0x01240BD0		 // 89 0D ? ? ? ? EB 06 89 3D ? ? ? ? 8D 4E ? C7 06
#define ItemAmtOff      0x14			 // 8B 4C 24 ? 83 C1 F8 83 F9 50 77 ? 0F ? ? ? ? ? ? FF

#define PortalBase     0x0116D1B8		 // 8B 3D ? ? ? ? 8B 47 ? 85 C0
#define PortalAmtOff    0x18
*/

#define StatHook       0x00AFC54C        // 8D 0C ? 85 C9 74 27 8B ? ? 8B ? 6B C0 ? 99

#define FMAAddy		   0x00790851		 // 85 C0 75 0C 8B 5C 24 ? 45 83 44 24 ? ? EB C2
#define FGMAddy        0x0078FF4C		 // 85 C0 75 35 8D 4C 24 ? C7 44 24 ? ? ? ? ? E8
#define Silence1Addy   0x00786968		 // 85 C0 75 ? ? ? 24 ? 0F 85 ? ? ? ? 8D 44 24 ? 50
#define Silence2Addy   0x00786991
#define Silence3Addy   0x007869B6
#define Silence4Addy   0x007869E7
#define Silence5Addy   0x00767652		 // 85 C0 0F 84 ? ? ? ? 5F 5E 5D B8 (2nd)

#define FullGodMode               0x00CB352B // 0F 85 ? ? ? ? 8B 16 8B 52 ? 6A ? 8D ? ? 50
#define MultiDamage               0x00DAEA5C // 75 23 57 8B CE E8 ? ? ? ? 85 C0
#define UnlimKaiserCast			  0x00CE0804 // 81 FE E0 7A A4 03 74 ? 81 FE 08 9E A4 03 75
#define UnlimKaiserGauge		  0x00CE0F95 // 3B C8 7D ? 8D
#define InstantAirLoot            0x0059EE69 // 75 68 2B 56 ? 81 FA ? ? ? ? 7C ? 8B ? ? 3D
#define NoKnockBack               0x00923B8B // 01 00 00 00 D8 ? DF ? F6
#define InstantDrop               0x0059C9F5 // 0D ? ? ? ? 83 C4 ? E9 ? ? ? ? DD
#define UnlimAttack               0x00C56B00 // 7E 33 83 F8 06 7D 2E 8B 41 ? 2B C2 3D ? ? ? ? 7E 22
#define FLEnterMap                0x00492D7B // 83 E1 ? 83 C9 ? C6 44 24 ? ? 89
#define SlowMobs                  0x007AEAAB // B8 ? ? ? ? 39 41 ? 7C 37 85 D2
#define NoMobLag                  0x007AFAA4 // B8 ? ? ? ? 5F 5E 5B 8B E5 5D C2 ? ? 8D 4E
#define HideDamage                0x007690A3 // 7E ? 8B 4C 24 ? 51 6A 00 6A 00 EB
#define NoLootAnimation           0x0045E939 // 81 FE ? ? ? ? 0F 8D ? ? ? ? 85 ED 0F 84
#define CPUBackGround1			  0x00738BBB // E8 ? ? ? FF C6 45 ? 17 85 F6 74 08
#define CPUBackGround2			  0x007394C9 // E8 ? ? ? FF 8B 06 8B 48 ? 56 C6 45 ? 03 FF D1 8B 75
#define CPUPlatforms			  0x0073DFE9 // E8 ? ? ? FF 8B 0E 8B 51 ? 56 C6 45 ? 07 FF D2
#define NoAtkLimit                0x00C56B20 // 8B 01 8B 54 24 ? 56 8B 74 24 ? 2B C6 //jnge below
#define NDFAAddy				  0x00CBCF4D // 83 BE ? ? 00 00 00 0F 84 ? ? 00 00 2B AE ? ? 00 00
#define ItemVacAddy				  0x007555B4 // E8 ? ? ? ? 8B C8 8B 44 24 ? 89 38 5F 89 48 ? 5E C2 04 00 CC CC CC CC CC CC CC 56 (5th)

const DWORD ADDRESS_SetMapleStoryData = 0x005BDAE0; //56 8B ? 8B ? ? ? ? ? 41 [4th Result]
const DWORD ADDRESS_CHATLOG_ADD = 0x00501BE0; //51 83 3D ? ? ? ? 00 74
const DWORD ItemHookCMPAddy = 0x00694B1A; //85 C0 75 ? 8D ? 24 ? C7 ? 24 ? ? ? ? ? E8 ? ? ? ? EB [1st Result]
const DWORD PtInRectAddy = 0x019C5E9C; //In Cheat Engine -> Memory Viewer, go to address "PtInRect" Scan that address(Tick hex -> 4 Bytes -> Exact Value) 
const DWORD InterlockInc = 0x750DA4D0;

const DWORD GUIBase = 0x019B3C38; //8B 0D ? ? ? ? 89 ? 24 ? ? ? 6A
const DWORD HPOff = 0x00002574; //89 8E ? ? 00 00 80 BE ? ? 00 00 00 75
const DWORD MPOff = HPOff + 4;
const DWORD ExpOff = 0x000024A0; //DD 9E ? ? ? ? 66 89 ? 24 ? 89 ? 24 [Double]
 
const DWORD AlertBase = 0x019B838C; //8B 15 ? ? ? ? 8B 4A ? 8D 0C 89
const DWORD HPAlertOff = 0x00000050; //Under AlertBase
const DWORD MPAlertOff = HPAlertOff + 4;
 
const DWORD CharBase = 0x019B3C34; //A1 ? ? ? ? 85 C0 75 ? 5F C3 8D 48
const DWORD CharPID = 0x000044F4; //8B 86 ? ? 00 00 6A D8
const DWORD CharXOff = 0x0000B73C; //89 8E ? ? ? ? 8B 50 ? 8B 06 89 96 ? ? ? ? 8B 50
const DWORD CharYOff = CharXOff + 4;
const DWORD BreathOff = 0x00000770; //83 B8 ? ? ? ? 00 7E ? 6A 00 6A 00 6A 00 6A 00 [Any Result]
const DWORD CharAnimOff = BreathOff + 4;
const DWORD CharAnimFrameOff = CharAnimOff + 0xC;
const DWORD CharAnimDelayOff = CharAnimOff + 0x10;
const DWORD CharAnimTotalDurationOff = CharAnimOff + 0x14;
const DWORD CharFreezeAnimToggleOff = CharAnimOff + 0x1C;
const DWORD AtkCountOff = 0x0000A61C; //89 ? ? ? ? 00 C7 ? ? ? ? 00 ? ? ? 00 8D ? ? ? ? 00 C6
const DWORD BuffCountOff = 0x0000A62C;
const DWORD LastAtkXOff = AtkCountOff - 8;
const DWORD LastAtkYOff = AtkCountOff - 4;
const DWORD MobMovementOff = 0x00000340; //83 ? ? ? ? ? ? 0F 85 ? ? ? ? 8B ? ? 8B ? ? ? ? 00 8D ? ? 8B
const DWORD AggroOffset = MobMovementOff + 8;
 
const DWORD MobBase = 0x019B82D8; //8B 0D ? ? ? ? ? E8 ? ? ? ? 8B ? 85 ? 74 ? 8B ? ? 8B ? ? 8D
const DWORD MobCountOff = 0x00000010; //8B 52 ? 83 C7 ? 8D 44 24 ? 50 8B CF FF D2 8B 00 89
const DWORD MobDeathOff = 0x00000560; //89 86 ? ? ? ? 89 86 ? ? ? ? 33 C0 89 86
const DWORD Mob1Off = 0x00000028; //89 7E ? 89 7E ? ? ? ? ? ? 89 46
const DWORD Mob2Off = 0x00000004; //89 7B ? 89 ? 24 ? 0F ? D6
const DWORD Mob3Off = 0x00000194; //89 ? ? ? ? 00 89 ? ? ? ? 00 89 ? ? ? ? 00 89 ? ? ? ? 00 89 ? ? ? ? 00 89 ? ? ? ? 00 89 ? ? ? ? 00 C7 ? ? ? ? 00 ? ? ? ? 89 ? ? ? ? 00 89 ? ? ? ? 00 89 ? ? ? ? 00 8B ? 24 [1st Result]
const DWORD Mob4Off = 0x00000024; //89 ? 24 ? C7 01 ? ? ? ? 89 59 ? C7
const DWORD MobXOff = 0x00000058; //89 ? ? 8D ? ? 89 ? 8D ? ? 89 ? 8D
const DWORD MobYOff = MobXOff + 4;
 
const DWORD MouseBase = 0x019B3C40; //8B 0D ? ? ? ? 74 12 83 B9 ? ? ? ? ? 74 09 6A ? 6A ? E8 [Any Result]
const DWORD MouseAnimOff = 0x00000A2C; //cmp below MouseBase
const DWORD MouseLocOff = 0x00000978; //8B ? ? ? ? ? 85 ? 75 ? 68 ? ? ? ? E8 ? ? ? 00 8B ? 24 ? 8B ? 8B ? ? ? ? ? F7
const DWORD MouseXOff = 0x0000008C; //8B 88 ? ? ? ? 6A ? 57 83 C5 ? 55 [Any Result]
const DWORD MouseYOff = MouseXOff + 4;
 
const DWORD ServerBase = 0x019B3C30; //8B 2D ? ? ? ? A1 ? ? ? ? 8D ? 24 ? ? 8B
const DWORD WorldOff = 0x000020CC; //8B 8F ? ? 00 00 8B ? 51 50 6A ? 8B ? C7 ? 24 ? 01
const DWORD ChannelOff = WorldOff + 8;
const DWORD TubiOff = 0x00002148; //83 ? ? ? ? ? 00 75 ? 83 7C ? ? 00 75 ? 8B
const DWORD GlobalDelayOff = TubiOff + 4;
const DWORD KeyPressOff = 0x000000A4; //
 
const DWORD WallBase = 0x019B82E0; //A1 ? ? ? ? 8B 50 ? 83 C0
const DWORD LeftWallOff = 0x0000001C; //mov below MapBase
const DWORD TopWallOff = LeftWallOff + 4;
const DWORD RightWallOff = TopWallOff + 4;
const DWORD BottomWallOff = RightWallOff + 4;
 
const DWORD MapInfoBase = 0x019B8908; //8B 0D ? ? ? ? E8 ? ? ? ? 8B 0D ? ? ? ? 85 C9 ? ? ? ? ? ? E8
const DWORD MapIDOff = 0x00001378; //8B 8F ? ? ? ? ? ? 8B 0D ? ? ? ? 8D 54
const DWORD MapCharXOff = 0x00001180; //8B 8F ? ? 00 00 ? E8 ? ? FF FF ? ? ? C2
const DWORD MapCharYOff = MapCharXOff + 4;
const DWORD NPCCountOff = MapCharXOff + 0x38;
const DWORD RopeLadderCount = 0x00001340; //
 
const DWORD PeopleBase = 0x019B82D4; //8B ? ? ? ? ? ? E8 ? ? ? ? ? ? ? ? 0F 84 ? ? ? ? 39
const DWORD PeopleCountOff = 0x00000018; //Second mov below PeopleBase
 
const DWORD ItemBase = 0x019B8888; //89 3D ? ? ? ? 8D 4E ? C7
const DWORD ItemCountOff = 0x00000014; //8B ? 24 ? 83 C1 ? 83 ? ? 77 ? 0F
const DWORD ItemIDOff = 0x00001424; //89 A9 ? ? ? ? 8B ? 8B ? ? ? C6
 
const DWORD PortalBase = 0x019BF8BC; //8B 3D ? ? ? ? 8B 47 ? 85 C0
const DWORD PortalCountOff = 0x0000001C; //8B ? 24 ? ? ? 8B 0D ? ? ? ? ? ? E8 ? ? ? ? 83
 
const DWORD TeleportX = 0x0000A3FC; //8D 8E ? ? ? ? C7 44 24 14 0A 00 00 00 E8 ? ? ? ? 68
const DWORD TeleportY = 0x0000A3F0; //TeleportX - 0x0C;
const DWORD TeleportToggle = 0x0000A3D8; //TeleportY - 0x18 or TeleportX - 0x24
 
const DWORD TimeStampBase = 0x019B3E9C; //A1 ? ? ? ? 8B 40 ? C3
const DWORD TimeStampOff = 0x00000034; //below TimeStampBase
 
const DWORD PlatformBase = 0x019B82E0; //8B ? ? ? ? ? E8 ? ? ? ? 89 ? ? ? E8 ? ? ? ? 8D
const DWORD PlatformOff = 0x00000080; //