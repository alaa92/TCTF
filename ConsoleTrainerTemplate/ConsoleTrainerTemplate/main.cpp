#include "Traxo.h"


void TrainerInitializer(Trainer * tn);

int main()
{	
	Trainer trainer = Trainer();
	Menu menu(trainer, "Traxo's Awesome Haxo");
	menu.Init();
	TrainerInitializer(&trainer);
	menu.Update();
	while (true)
	{
		if (trainer.Update()) //If you toggle a hack it returns true.
			menu.Update();
		if (!trainer.IsRunning())
		{
			menu.Update();
			trainer.ReInit();
			menu.Update();
		}
	}

	system("pause");
	return 0;
}

void TrainerInitializer(Trainer * tn)
{
	//Initialize the trainer.
	tn->Init(L"ac_client.exe");

	//Create hack, set hotkey, add it to trainer.
	static Hack InfAmmo = tn->make.MakePatchHack(L"Inf Ammo", 0x4637E9, 2);
	InfAmmo.SetHotkey(VK_NUMPAD1);
	tn->AddOption(InfAmmo);

	Pointer pHealth = Pointer(0x50f4f4, std::vector<UINT>{0x358, 0x48, 0x1e8, 0x8, 0xf8});
	static Hack InfHealth = tn->make.MakeFreezePtrHack(L"Inf Health", pHealth, 999);
	InfHealth.SetHotkey(VK_NUMPAD2);
	tn->AddOption(InfHealth);

	std::vector<byte>vCaveData = { 0x50, 0xA1, 0xF4, 0xF4, 0x50, 0x00, 0x8B, 0x80, 0x58, 0x03, 0x00, 0x00, 0x8B, 0x40, 0x48, 0x8B, 0x80, 0xE8, 0x01, 0x00, 0x00, 0x8B, 0x40, 0x08, 0x05, 0xF4, 0x00, 0x00, 0x00, 0x39, 0xD8, 0x58, 0x0F, 0x84, 0x05, 0x00, 0x00, 0x00, 0xBF, 0x90, 0x00, 0x00, 0x00, 0x29, 0x7B, 0x04, 0x8B, 0xC7 };
	static Hack OHK = tn->make.MakeInjectionHack(L"One-Hit Kill", 0x00429D1F, 5, vCaveData);
	OHK.SetHotkey(VK_NUMPAD3);
	tn->AddOption(OHK);

	// =========================

	//tn->Init(L"DOOMx64.exe");
	//Pointer healthPtr = Pointer(0x1434D84C0, std::vector<UINT>{0x0, 0x18, 0x6c});
	//static Hack FreezeHealth = tn->make.MakeFreezePtrHack(L"Inf Health", healthPtr, 999.0f);
	//FreezeHealth.SetHotkey(VK_NUMPAD1);
	//tn->AddOption(FreezeHealth);

	//Pointer armorPtr = Pointer(0x1434D84C0, std::vector<UINT>{0x0, 0x18, 0xb8});
	//static Hack FreezeArmor = tn->make.MakeFreezePtrHack(L"Inf Armor", armorPtr, 999.0f);
	//FreezeArmor.SetHotkey(VK_NUMPAD2);
	//tn->AddOption(FreezeArmor);

	//std::vector<byte> vAmmoPat = { 0x01, 0x51, 0x00, 0x8B, 0x71, 0x00, 0x45, 0x84, 0xC0, 0x74, 0x2A, 0x48, 0x8B, 0x01, 0xFF, 0x90, 0x00, 0x00, 0x00, 0x00, 0x85, 0xF6, 0x78, 0x07, 0x89, 0xF7, 0x39, 0xC6, 0x0F, 0x4F, 0xF8, 0x89, 0x7B, 0x00 };
	//Pattern patAmmo = Pattern(vAmmoPat, std::string("xx?xx?xxxxxxxxxx????xxxxxxxxxxxxx?"));
	//static Hack PatchAmmo = tn->make.MakePatchHack(L"Inf Ammo", patAmmo, 3);
	//PatchAmmo.SetHotkey(VK_NUMPAD3);
	//tn->AddOption(PatchAmmo);

	//std::vector<byte> vCaveData = { 0x50, 0x51, 0x48, 0xA1, 0xC0, 0x84, 0x4D, 0x43, 0x01, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x08, 0x48, 0x8B, 0x41, 0x18, 0x48, 0x83, 0xC0, 0x6C, 0x48, 0x8B, 0xCB, 0x48, 0x01, 0xF1, 0x48, 0x83, 0xC1, 0x1C, 0x48, 0x39, 0xC1, 0x59, 0x58, 0x75, 0x18, 0x90, 0x90, 0x90, 0x90, 0xF3, 0x0F, 0x11, 0x44, 0x33, 0x1C, 0xEB, 0x16, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xF3, 0x0F, 0x10, 0xC1, 0xF3, 0x0F, 0x11, 0x44, 0x33, 0x1C };
	//std::vector<byte> vOHK = { 0xF3, 0x0F, 0x11, 0x44, 0x00, 0x00, 0x0F, 0xB6, 0x74, 0x24, 0x00, 0xF3, 0x0F, 0x11, 0x75, 0x00, 0x40, 0x84, 0xF6, 0x74, 0x40 };
	//Pattern patOHK = Pattern(vOHK, std::string("xxxx??xxxx?xxxxxxxxxx"));
	//static Hack OHK = tn->make.MakeInjectionHack(L"One-Hit Kill", patOHK, 6, vCaveData);
	//OHK.SetHotkey(VK_NUMPAD4);
	//tn->AddOption(OHK);
}