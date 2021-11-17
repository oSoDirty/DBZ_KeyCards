class KeyCard_Config_System
{	
	protected static ref KeyCard_ConfigData_System m_KeyCard_System_ConfigData;
	protected static bool kcm_UpdateCheckComplete;
	protected static bool kcm_RecentlyUpdated = false;
	
	void KeyCard_Config_System()
	{
		LoadConfig();
	}
	
	static void CreateMainDirectory()
	{
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/"))
        {
			Print("[KCM Debug] - DNA_Keycards Config: Main directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/");
		}
	}
	
	static void CheckForConfigUpdate()
	{
		array<string> configPaths =
		{
			kcm_SystemConfigPath,
			kcm_BasicConfigPath,
			kcm_YellowConfigPath,
			kcm_GreenConfigPath,
			kcm_BlueConfigPath,
			kcm_PurpleConfigPath,
			kcm_RedConfigPath
		};
		array<string> categoties =
		{
			"system",
			"basic",
			"yellow",
			"green",
			"blue",
			"purple",
			"red"
		};
		string kcm_ConfigcppVersion;
		GetGame().ConfigGetText("CfgMods DNA_Keycards configVersion", kcm_ConfigcppVersion);
		if(FileExist(kcm_ProfilePath + kcm_ConfigFolderName) && kcm_ConfigcppVersion != DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetVersionArray().Get(0).GetConfigVersion())
		{
			if(!FileExist(kcm_BackupConfigFolderPath))
				MakeDirectory(kcm_BackupConfigFolderPath);
			
			for(int i = 0; i < categoties.Count(); i++)
			{
				string existingConfig = configPaths.Get(i);
				if(FileExist(existingConfig))
				{
					CopyFile(existingConfig, kcm_BackupConfigFolderPath + "/" + categoties.Get(i) + ".json");
					DeleteFile(existingConfig);
				}
			}
			kcm_RecentlyUpdated = true;
			Print("[KCM Debug] - Configs outdated! Creating backups in Profile/DNA_Keycards/ConfigBackups and placing new defaults. Don't forget to merge your old settings!!!");
		}
		kcm_UpdateCheckComplete = true;
	}
	
	static bool RecentlyUpdated()
	{
		return kcm_RecentlyUpdated;
	}
	
	KeyCard_ConfigData_System GetConfigData()
	{
		if(!m_KeyCard_System_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_System_ConfigData;
	}
	
	protected static void LoadConfig()
	{	
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/System/"))
        {
			Print("[KCM Debug] - DNA_Keycards System: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/System/");
		}
		
		m_KeyCard_System_ConfigData = new KeyCard_ConfigData_System();
		
		if (!FileExist(kcm_SystemConfigPath))
        {
			if(!RecentlyUpdated()) Print("[KCM Debug] - DNA_Keycards System Settings: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_System>.JsonLoadFile(kcm_SystemConfigPath, m_KeyCard_System_ConfigData);
			if(kcm_UpdateCheckComplete) Print("[KCM Debug] - DNA_Keycards System Settings: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_System_ConfigData.GetVersionArray().Insert(new KCM_Config_Version("DO NOT CHANGE THIS! IT WILL DELETE YOUR CONFIG!!!!!!(but also creates a backup ;) ) ","1.0"));
		
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(0) Use KCM To Spawn Entites (1 true, 0 false)",1)); //remove after testing
		//m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(0) Use KCM To Spawn Entites (1 true, 0 false)",0)); //uncomment after testing
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(1) Yellow Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(2) Yellow Spawn Main Weapon Extra Mags(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(3) Yellow Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(4) Yellow Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(5) Yellow Spawn Side Arm Extra Mags (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(6) Yellow Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(7) Yellow Spawn Food (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(8) Yellow Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(9) Yellow Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(10) Yellow Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(11) Yellow Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(12) Yellow Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(13) Yellow Crates Spawn Count (0 to turn off, don't set higher than number of available positions",5));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(14) Green Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(15) Green Spawn Main Weapon Extra Mags(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(16) Green Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(17) Green Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(18) Green Spawn Side Arm Extra Mags (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(19) Green Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(20) Green Spawn Food (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(21) Green Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(22) Green Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(23) Green Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(24) Green Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(25) Green Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(26) Green Crates Spawn Count (0 to turn off, don't set higher than number of available positions",4));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(27) Blue Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(28) Blue Spawn Main Weapon Extra Mags(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(29) Blue Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(30) Blue Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(31) Blue Spawn Side Arm Extra Mags (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(32) Blue Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(33) Blue Spawn Food (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(34) Blue Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(35) Blue Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(36) Blue Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(37) Blue Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(38) Blue Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(39) Blue Crates Spawn Count (0 to turn off, don't set higher than number of available positions",3));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(40) Purple Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(41) Purple Spawn Main Weapon Extra Mags(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(42) Purple Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(43) Purple Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(44) Purple Spawn Side Arm Extra Mags (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(45) Purple Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(46) Purple Spawn Food (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(47) Purple Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(48) Purple Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(49) Purple Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(50) Purple Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(51) Purple Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(52) Purple Crates Spawn Count (0 to turn off, don't set higher than number of available positions",2));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(53) Red Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(54) Red Spawn Main Weapon Extra Mags(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(55) Red Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(56) Red Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(57) Red Spawn Side Arm Extra Mags (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(58) Red Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(59) Red Spawn Food (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(60) Red Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(61) Red Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(62) Red Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(63) Red Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(64) Red Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(65) Red Crates Spawn Count (0 to turn off, don't set higher than number of available positions",1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(66) Yellow Crates Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(67) Yellow Crates Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(68) Green Crates Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(69) Green Crates Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(70) Blue Crates Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(71) Blue Crates Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(72) Purple Crates Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(73) Purple Crates Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(74) Red Crates Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(75) Red Crates Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(76) Yellow Crates Spawn Meds (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(77) Green Crates Spawn Meds (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(78) Blue Crates Spawn Meds (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(79) Purple Crates Spawn Meds (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(80) Red Crates Spawn Meds (1 true, 0 false)", 1));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(81) Yellow Card Usage Allotment", 5));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(82) Green Card Usage Allotment", 4));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(83) Blue Card Usage Allotment", 3));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(84) Purple Card Usage Allotment", 2));
		m_KeyCard_System_ConfigData.GetSystemArray().Insert(new KCM_Config_System("(85) Red Card Usage Allotment", 1));
		
		/*m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));*/
		
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("4670.778809 339.372198 9856.767578", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("4669.937012 339.372168 9848.751953", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("4667.031738 339.372198 9860.922852", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("4664.092285 339.372198 9862.980469", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Locations("4665.296875 339.372168 9860.949219", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("4659.698730 339.372198 9879.450195", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("4658.307617 339.372198 9877.361328", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("4662.786133 339.372198 9877.178711", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("4663.692383 339.372198 9879.638672", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Locations("4666.832520 339.372260 9877.065430", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("4672.081055 339.372198 9884.833008", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("4672.953613 339.372290 9887.461914", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("4675.708008 339.372229 9889.149414", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("4676.007324 339.372229 9886.689453", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Locations("4675.590820 339.372137 9883.307617", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("4682.869141 339.372168 9889.340820", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("4685.238770 339.403998 9888.849609", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("4687.677246 339.408362 9886.628906", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("4685.790527 339.372229 9884.399414", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Locations("4683.372070 339.372229 9884.746094", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("4691.393066 339.372198 9877.183594", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("4691.466797 339.372198 9879.052734", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("4691.968750 339.372198 9875.055664", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("4688.981934 339.372229 9874.983398", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Locations("4688.340820 339.372168 9877.572266", "0.000000 -0.000000 -0.000000"));
		
		JsonFileLoader<KeyCard_ConfigData_System>.JsonSaveFile(kcm_SystemConfigPath, m_KeyCard_System_ConfigData);
	}
}