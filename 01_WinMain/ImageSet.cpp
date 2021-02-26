#include "pch.h"
#include "ImageSet.h"
//사용할 이미지 입력
vector<function<void(void)>> ImageSet::SetImage() //첫 scene1 로드
{
	vector<function<void(void)>> mLoadData =
	{
		//플레이어 이미지
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Player", Resources(L"Player.bmp"), 64, 96, 4, 4, true);																		},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"SideSword", Resources(L"SideSword.bmp"), 15, 14, 1, 2, true);																	},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"UpdownSword", Resources(L"UpdownSword.bmp"), 14, 15, 2, 1, true);																},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"die", Resources(L"die.bmp"), 98, 18, 1, 7, true);																				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"UpSword", Resources(L"UpSword.bmp"), 7, 15, true);																			},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"DownSword", Resources(L"DownSword.bmp"), 7, 15, true);																		},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"RightSword", Resources(L"RightSword.bmp"), 15, 7, true);																		},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"LeftSword", Resources(L"LeftSword.bmp"), 15, 7, true);																		},
		//플랫포머플레이어 이미지																																					   
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PlatformerPlayerIdle", Resources(L"PlatformerPlayer/PlayerIdle.bmp"), 500, 310, 5, 2, true,RGB(99,92,99));					},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Dash", Resources(L"PlatformerPlayer/Dash.bmp"), 2608, 326, 8, 2, true, RGB(99, 92, 99));										},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Die", Resources(L"PlatformerPlayer/Die.bmp"), 2752, 106, 16, 1, true, RGB(99, 92, 99));										},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Duckidle", Resources(L"PlatformerPlayer/Duckidle.bmp"), 2184, 244, 13, 2, true, RGB(99, 92, 99));								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"DuckShoot", Resources(L"PlatformerPlayer/DuckShoot.bmp"), 1158, 162, 6, 2, true, RGB(99, 92, 99));							},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Groundhit", Resources(L"PlatformerPlayer/Groundhit.bmp"), 750, 442, 6, 2, true, RGB(99, 92, 99));								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"GroundSpecialAttack", Resources(L"PlatformerPlayer/GroundSpecialAttack.bmp"), 2470, 300, 13, 2, true, RGB(99, 92, 99));		},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Jump", Resources(L"PlatformerPlayer/Jump.bmp"), 704, 218, 8, 2, true, RGB(99, 92, 99));										},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Run", Resources(L"PlatformerPlayer/Run.bmp"), 2466, 336, 18, 2, true, RGB(99, 92, 99));										},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"RunShoot", Resources(L"PlatformerPlayer/RunShoot.bmp"), 2592, 350, 18, 2, true, RGB(99, 92, 99));								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"StraightShoot", Resources(L"PlatformerPlayer/StraightShoot.bmp"), 822, 340, 6, 2, true, RGB(99, 92, 99));						},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"UpspecialAttack", Resources(L"PlatformerPlayer/UpspecialAttack.bmp"), 1508, 460, 13, 2, true, RGB(99, 92, 99));				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"DiagonalUp", Resources(L"PlatformerPlayer/DiagonalUp.bmp"), 840, 328, 6, 2, true, RGB(99, 92, 99));							},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Parring", Resources(L"PlatformerPlayer/Parring.bmp"), 1120, 280, 8, 2, true, RGB(99, 92, 99));								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"RunDiagonalShoot", Resources(L"PlatformerPlayer/RunDiagonalShoot.bmp"), 2574, 350, 18, 2, true, RGB(99, 92, 99));				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"UpShoot", Resources(L"PlatformerPlayer/UpShoot.bmp"), 708, 378, 6, 2, true, RGB(99, 92, 99));									},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Upaim", Resources(L"PlatformerPlayer/Upaim.bmp"), 540, 350, 5, 2, true, RGB(99, 92, 99));										},

		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Shootaim", Resources(L"PlatformerPlayer/Shootaim.bmp"), 670, 322, 5, 2, true, RGB(99, 92, 99));								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"DiagonalUpaim", Resources(L"PlatformerPlayer/DiagonalUpaim.bmp"), 645, 302, 5, 2, true, RGB(99, 92, 99));						},
		//적 이미지																																									
																																													
		//플레이어 이미지																																							 
		//TEST																																									
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"cuphead_idle", Resources(L"Image/Player/cuphead_idle.bmp"), 490, 155, 5, 1, true);											},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Back", Resources(L"Map1.bmp"), 1280, 720,false);																				},
																																												
		//보스 이미지																																							
		//맵 이미지																																								
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"BotanicPanicBackground1", Resources(L"Boss/BotanicPanic/BotanicPanicBackGround1.bmp"), 885, 567, true);						},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"BotanicPanicBackground2", Resources(L"Boss/BotanicPanic/BotanicPanicBackGround2.bmp"), 885, 567, true);						},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"BotanicPanicBackground3", Resources(L"Boss/BotanicPanic/BotanicPanicBackground3.bmp"), 885, 567, true);						},
		//감자																																									 
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoIntro", Resources(L"Boss/BotanicPanic/Potato/Potato_Intro.bmp"), 4208, 512, 8, 1, true);								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoIntroEarth", Resources(L"Boss/BotanicPanic/Potato/Potato_Intro_Earth.bmp"), 10026, 461, 18, 1, true);					},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoIntroEarth1", Resources(L"Boss/BotanicPanic/Potato/Potato_Intro_Earth1.bmp"), 557, 461, true);							},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoIntroEarth2", Resources(L"Boss/BotanicPanic/Potato/Potato_Intro_Earth2.bmp"), 557, 461, true);							},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoIdle", Resources(L"Boss/BotanicPanic/Potato/Potato_Idle.bmp"), 3682, 512, 7, 1, true);									},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoSpitAttack", Resources(L"Boss/BotanicPanic/Potato/Potato_Spit_Attack.bmp"), 12624, 512, 24, 1, true);					},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoDeath", Resources(L"Boss/BotanicPanic/Potato/Potato_Death.bmp"), 2727, 439, 9, 1, true);								},
		//감자 투사체																																								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoParryable", Resources(L"Boss/BotanicPanic/Potato/Potato_Parryable.bmp"), 528, 142, 4, 1, true);							},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"PotatoNonParryable", Resources(L"Boss/BotanicPanic/Potato/Potato_NonParryable.bmp"), 1072, 139, 8, 1, true);					},																																					
		//당근																																									
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"CarrotIntro", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Intro.bmp"), 14800, 549, 25, 1, true);								},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"CarrotAttack", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Attack .bmp"), 10252, 501, 22, 1, true);							},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"CarrotChangeToBeam", Resources(L"Boss/BotanicPanic/Carrot/Carrot_ChangeToBeam.bmp"), 4122, 1044, 9, 2, true);					},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"CarrotBeam", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Beam.bmp"), 1832, 522, 4, 1, true);									},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"CarrotDeath", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Death.bmp"), 4199, 456, 13, 1, true);								},
		//당근 투사체																																								
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"CarrotMissile", Resources(L"Boss/BotanicPanic/Carrot/Carrot_Missile.bmp"), 492, 137, 6, 1, true);								},
																																											
		//양파																																								
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionIntro", Resources(L"Boss/BotanicPanic/Onion/Onion_Intro.bmp"), 12312, 643, 24, 1, true);									},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionIdle", Resources(L"Boss/BotanicPanic/Onion/Onion_Idle.bmp"), 7440, 563, 15, 1, true);									},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionChangeToAttack", Resources(L"Boss/BotanicPanic/Onion/Onion_ChangeToAttack.bmp"), 3776, 1140, 8, 2, true);				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionBeforeAttack", Resources(L"Boss/BotanicPanic/Onion/Onion_BeforeAttack.bmp"), 2832, 570, 6, 1, true);						},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionAttack", Resources(L"Boss/BotanicPanic/Onion/Onion_Attack.bmp"), 3376, 570, 8, 1, true);									},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionDeath", Resources(L"Boss/BotanicPanic/Onion/Onion_Death.bmp"), 2976, 599, 6, 1, true);									},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionDeathLeave", Resources(L"Boss/BotanicPanic/Onion/Onion_Death_Leave.bmp"), 16768, 596, 31, 1, true);						},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionTearEffect", Resources(L"Boss/BotanicPanic/Onion/Onion_Tears.bmp"), 5460, 407, 4, 1, true);								},
		//양파 투사체																																							
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionNonParryAbleA", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_NonParryableA.bmp"), 111, 68, 3, 1, true);				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionNonParryAbleB", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_NonParryableB.bmp"), 111, 67, 3, 1, true);				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionNonParryAbleC", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_NonParryableC.bmp"), 117, 72, 3, 1, true);				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionNonParryAbleD", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_NonParryableD.bmp"), 120, 68, 3, 1, true);				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionNonParryAbleE", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_NonParryableE.bmp"), 117, 69, 3, 1, true);				},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionParryable", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_Parryable.bmp"), 117, 69, 3, 1, true);						},
		//양파 투사체 효과																																							
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionNonParryAbleASplash", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_NonParryableASplash.bmp"), 1540, 136, 7, 1, true);	},
																																												
		//총알 Test																																								
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Testbullet", Resources(L"bullet.bmp"), 21, 21, true);																			},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OnionParryAbleSplash", Resources(L"Boss/BotanicPanic/Onion/Onion_Proj_ParryableSplash.bmp"), 1212, 126, 6, 1, true);			},
		setLambda(void) {IMAGEMANAGER->LoadFromFile(L"ElderHouse_Inside", Resources(L"/ElderHouse/ElderHouse_Inside.bmp"), 1695, 834, true);										}
	};
	return mLoadData;
}

void ImageSet::SetFxImage() {
	for (int a = 0; a < 127; a++) {
		wstring file = L"FX/cuphead_screen_fx_0";
		wstring key = L"FX_";
		key = key + to_wstring(a);
		if (a / 100) {
			file = file + to_wstring(a) + L".bmp";

		}
		else if (a / 10) {
			file = file +L"0" +to_wstring(a) + L".bmp";
		}
		else {
			file = file + L"00" + to_wstring(a) + L".bmp";
		}
		IMAGEMANAGER->LoadFromFile(key, ResourcesImage(file), 1024, 517, false);
	}
	IMAGEMANAGER->LoadFromFile(L"LoadingHourGlass", ResourcesImage(L"Loading/LoadingHourGlass.bmp"), 8142, 306, 46,1,false);
	IMAGEMANAGER->LoadFromFile(L"BlackGround", ResourcesImage(L"Loading/BlackGround.bmp"), 1024, 517, false);
}


vector<function<void(void)>> ImageSet::SetOverWorldImage() {
	vector<function<void(void)>> mLoadData =
	{
		//이미지
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"FadeOut", Resources(L"/FadeOut.bmp"), 12800, 720, 10, 1, true);},
	//월드맵이미지
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"CupHead_OverWolrd", Resources(L"/overworld/Cuphead/CupHead_OverWorld.bmp"), 1649, 1130, 16, 10, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"NPC_Apple", Resources(L"/overworld/NPC/NPC_Apple.bmp"), 2600, 100, 26, 1, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OverWorld", Resources(L"/overworld/OverWorld.bmp"), 4000, 2200, true);},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OverWorld_CanMove", Resources(L"/overworld/OverWorld_CanMove.bmp"), 4000, 2200, true);},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OverWorld_Front", Resources(L"/overworld/OverWorld_Front.bmp"), 4000, 2200, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OverWorld_Building_ElderHouse", Resources(L"/overworld/Buildings/ElderHouse.bmp"), 300, 350, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OverWorld_Building_Flatformer", Resources(L"/overworld/Buildings/flatformer.bmp"), 63, 46, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"OverWorld_Building_BotanicPanic", Resources(L"/overworld/Buildings/BotanicPanic.bmp"), 330, 270, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"Dust_OverWolrd", Resources(L"/overworld/Cuphead/Dust_Overworld.bmp"), 1622, 498, 20, 6, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"ZPopUp", Resources(L"/overworld/Z.bmp"), 42, 52, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk1", Resources(L"/overworld/NPC/Talk1.bmp"), 1016, 263, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk2", Resources(L"/overworld/NPC/Talk2.bmp"), 899, 335, true, RGB(99, 92, 99)); },
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk3", Resources(L"/overworld/NPC/Talk3.bmp"), 693, 265, true, RGB(99, 92, 99)); },
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk4", Resources(L"/overworld/NPC/Talk4.bmp"), 903, 339, true, RGB(99, 92, 99)); },
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"NPC_Apple_Talk5", Resources(L"/overworld/NPC/Talk5.bmp"), 881, 285, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"ElderHouse_Talk", Resources(L"/overworld/buildings/ElderHouse_Title.bmp"), 785, 418, true, RGB(99, 92, 99));},
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"BotanicPanic_Talk1", Resources(L"/overworld/buildings/BotanicPanic_Title_Simple.bmp"), 1165, 834, true, RGB(99, 92, 99));},
	setLambda(void) { IMAGEMANAGER->LoadFromFile(L"BotanicPanic_Talk2", Resources(L"/overworld/buildings/BotanicPanic_Title_Regular.bmp"), 1165, 834, true, RGB(99, 92, 99)); },
	setLambda(void) { IMAGEMANAGER->LoadFromFile(L"Black", Resources(L"/overworld/buildings/Black.bmp"), 1280, 720, false); },

	setLambda(void) { IMAGEMANAGER->LoadFromFile(L"OverWorld_Flag", Resources(L"/overworld/Flag.bmp"), 1788, 220, 12, 1, true, RGB(99, 92, 99)); },

	//장로집 이미지
	setLambda(void) {IMAGEMANAGER->LoadFromFile(L"ElderHouse_Inside", Resources(L"/ElderHouse/ElderHouse_Inside.bmp"), 1695, 834, true);}
	};

	

	return mLoadData;
}