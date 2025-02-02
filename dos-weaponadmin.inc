
/*----------------------------------------------------------------------------------------------------*-

										  Weapon Admin
										Official Script

										Author & Developer:
								   	  Thiradev Byp (dosuser)
							        https://discord.gg/HNxzGaJu

-*----------------------------------------------------------------------------------------------------*/

enum E_WEAPON_DATA
{
    WeaponID,
    WeaponNameENG[64],
    WeaponNameTHA[64],
};

new WeaponData[][E_WEAPON_DATA] =
{
    {1, "Brass Knuckles", "สนับมือ"},
    {2, "Golf Club", "ไม้กอล์ฟ"},
    {3, "Nightstick", "ไม้เคาะ"},
    {4, "Knife", "มีด"},
    {5, "Baseball Bat", "ไม้เบสบอล"},
    {6, "Shovel", "พลั่ว"},
    {7, "Pool Cue", "ไม้พูล"},
    {8, "Katana", "ดาบคาตานะ"},
    {9, "Chainsaw", "เลื่อยโซ่"},
    {10, "Purple Dildo", "ดิลโด้ม่วง"},
    {11, "Dildo", "ดิลโด้"},
    {12, "Vibrator", "ไวเบรเตอร์"},
    {13, "Silver Vibrator", "ไวเบรเตอร์เงิน"},
    {14, "Flowers", "ดอกไม้"},
    {15, "Cane", "ไม้เท้า"},
    {16, "Grenade", "ระเบิดมือ"},
    {17, "Tear Gas", "แก๊สน้ำตา"},
    {18, "Molotov Cocktail", "มอลอทอฟ ค็อกเทล"},
    {22, "9MM", "ปืนพก 9 มม."},
    {23, "Silenced 9MM", "ปืนพก 9 มม. ซิลินเซอร์"},
    {24, "Desert Eagle", "เดสเซิร์ต อีเกิล"},
    {25, "Shotgun", "ช็อตกัน"},
    {26, "Sawnoff Shotgun", "ช็อตกันซอว์น็อฟ"},
    {27, "Combat Shotgun", "ช็อตกันต่อสู้"},
    {28, "Micro SMG", "ไมโคร เอสเอ็มจี"},
    {29, "MP5", "เอ็มพี 5"},
    {30, "AK-47", "เอเค 47"},
    {31, "M4", "เอ็ม 4"},
    {32, "TEC-9", "เทค 9"},
    {33, "Country Rifle", "ไรเฟิลชนบท"},
    {34, "Sniper Rifle", "สไนเปอร์ไรเฟิล"},
    {35, "RPG", "อาร์พีจี"},
    {36, "HS Rocket", "จรวด HS"},
    {37, "Flamethrower", "ปืนไฟ"},
    {38, "Knuckles", "สนับมือ"},
    {39, "Satchel Charge", "ระเบิดกระเป๋า"},
    {40, "Detonator", "ตัวจุดระเบิด"},
    {41, "Spraycan", "กระป๋องสเปรย์"},
    {42, "Fire Extinguisher", "ถังดับเพลิง"},
    {43, "Camera", "กล้อง"},
    {44, "Night Vision Goggles", "แว่นตาไนท์วิชั่น"},
    {45, "Thermal Goggles", "แว่นตาความร้อน"},
    {46, "Parachute", "ร่มชูชีพ"}
};

new UseWeaponID[MAX_PLAYERS];

alias:weaponadmin("เสกอาวุธ")
CMD:weaponadmin(playerid, params[])
{
    if (playerData[playerid][pAdmin] < 1)
        return 0;

	static string[2048];

	if (!strlen(string))
	{
		for (new i = 0; i < sizeof(WeaponData); i ++)
		{
			format(string, sizeof(string), "%s%d\t%s\t%s\n", string, WeaponData[i][WeaponID], WeaponData[i][WeaponNameENG], WeaponData[i][WeaponNameTHA]);
		}
	}

	return Dialog_Show(playerid, DIALOG_WEAPON_ADMIN, DIALOG_STYLE_TABLIST, "[ รายการอาวุธ ]", string, "เลือก", "ตกลง");
}

Dialog:DIALOG_WEAPON_ADMIN(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        UseWeaponID[playerid] = WeaponData[listitem][WeaponID];

        new str[256];
        format(str, sizeof str, "คุณได้เลือกอาวุธ '%s' กรุณากรอกจำนวนที่คุณต้องการ", WeaponData[listitem][WeaponNameTHA]);
        Dialog_Show(playerid, DIALOG_WEAPON_ADMIN_GIVE, DIALOG_STYLE_INPUT, "Weapon Give", str, "ตกลง", "ยกเลิก");
        // printf("test: %d", WeaponData[listitem][WeaponID]);
        // GivePlayerWeaponEx(playerid, WeaponData[listitem][WeaponID], 1);
    }
    return 1;
}

Dialog:DIALOG_WEAPON_ADMIN_GIVE(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        new 
            str[256], 
            amount;

		if (sscanf(inputtext, "d", amount))
		{
            format(str, sizeof str, "คุณได้เลือกอาวุธ '%s' กรุณากรอกจำนวนที่คุณต้องการ", WeaponData[listitem][WeaponNameTHA]);
            Dialog_Show(playerid, DIALOG_WEAPON_ADMIN_GIVE, DIALOG_STYLE_INPUT, "Weapon Give", str, "ตกลง", "ยกเลิก");
	    	return 1;
		}
        else
        {
            GivePlayerWeaponEx(playerid, UseWeaponID[playerid], amount);
        }
    }
    return 1;
}