const u16 *const gFormSpeciesIdTables[NUM_SPECIES] =
{
    [SPECIES_VENUSAUR] = sVenusaurFormSpeciesIdTable,
    [SPECIES_CHARIZARD] = sCharizardFormSpeciesIdTable,
    [SPECIES_BLASTOISE] = sBlastoiseFormSpeciesIdTable,
    [SPECIES_BEEDRILL] = sBeedrillFormSpeciesIdTable,
    [SPECIES_PIDGEOT] = sPidgeotFormSpeciesIdTable,
    [SPECIES_RATTATA] = sRattataFormSpeciesIdTable,
    [SPECIES_RATICATE] = sRaticateFormSpeciesIdTable,
    [SPECIES_PIKACHU] = sPikachuFormSpeciesIdTable,
    [SPECIES_RAICHU] = sRaichuFormSpeciesIdTable,
    [SPECIES_SANDSHREW] = sSandshrewFormSpeciesIdTable,
    [SPECIES_SANDSLASH] = sSandslashFormSpeciesIdTable,
    [SPECIES_VULPIX] = sVulpixFormSpeciesIdTable,
    [SPECIES_NINETALES] = sNinetalesFormSpeciesIdTable,
    [SPECIES_DIGLETT] = sDiglettFormSpeciesIdTable,
    [SPECIES_DUGTRIO] = sDugtrioFormSpeciesIdTable,
    [SPECIES_MEOWTH] = sMeowthFormSpeciesIdTable,
    [SPECIES_PERSIAN] = sPersianFormSpeciesIdTable,
    [SPECIES_ALAKAZAM] = sAlakazamFormSpeciesIdTable,
    [SPECIES_GEODUDE] = sGeodudeFormSpeciesIdTable,
    [SPECIES_GRAVELER] = sGravelerFormSpeciesIdTable,
    [SPECIES_GOLEM] = sGolemFormSpeciesIdTable,
    [SPECIES_SLOWBRO] = sSlowbroFormSpeciesIdTable,
    [SPECIES_GRIMER] = sGrimerFormSpeciesIdTable,
    [SPECIES_MUK] = sMukFormSpeciesIdTable,
    [SPECIES_GENGAR] = sGengarFormSpeciesIdTable,
    [SPECIES_EXEGGUTOR] = sExeggutorFormSpeciesIdTable,
    [SPECIES_MAROWAK] = sMarowakFormSpeciesIdTable,
    [SPECIES_KANGASKHAN] = sKangaskhanFormSpeciesIdTable,
    [SPECIES_PINSIR] = sPinsirFormSpeciesIdTable,
    [SPECIES_GYARADOS] = sGyaradosFormSpeciesIdTable,
    [SPECIES_AERODACTYL] = sAerodactylFormSpeciesIdTable,
    [SPECIES_MEWTWO] = sMewtwoFormSpeciesIdTable,
    [SPECIES_PICHU] = sPichuFormSpeciesIdTable,
    [SPECIES_AMPHAROS] = sAmpharosFormSpeciesIdTable,
    [SPECIES_UNOWN] = sUnownFormSpeciesIdTable,
    [SPECIES_STEELIX] = sSteelixFormSpeciesIdTable,
    [SPECIES_SCIZOR] = sScizorFormSpeciesIdTable,
    [SPECIES_HERACROSS] = sHeracrossFormSpeciesIdTable,
    [SPECIES_HOUNDOOM] = sHoundoomFormSpeciesIdTable,
    [SPECIES_TYRANITAR] = sTyranitarFormSpeciesIdTable,
    [SPECIES_SCEPTILE] = sSceptileFormSpeciesIdTable,
    [SPECIES_BLAZIKEN] = sBlazikenFormSpeciesIdTable,
    [SPECIES_SWAMPERT] = sSwampertFormSpeciesIdTable,
    [SPECIES_GARDEVOIR] = sGardevoirFormSpeciesIdTable,
    [SPECIES_SABLEYE] = sSableyeFormSpeciesIdTable,
    [SPECIES_MAWILE] = sMawileFormSpeciesIdTable,
    [SPECIES_AGGRON] = sAggronFormSpeciesIdTable,
    [SPECIES_MEDICHAM] = sMedichamFormSpeciesIdTable,
    [SPECIES_MANECTRIC] = sManectricFormSpeciesIdTable,
    [SPECIES_SHARPEDO] = sSharpedoFormSpeciesIdTable,
    [SPECIES_CAMERUPT] = sCameruptFormSpeciesIdTable,
    [SPECIES_ALTARIA] = sAltariaFormSpeciesIdTable,
    [SPECIES_CASTFORM] = sCastformFormSpeciesIdTable,
    [SPECIES_BANETTE] = sBanetteFormSpeciesIdTable,
    [SPECIES_ABSOL] = sAbsolFormSpeciesIdTable,
    [SPECIES_GLALIE] = sGlalieFormSpeciesIdTable,
    [SPECIES_SALAMENCE] = sSalamenceFormSpeciesIdTable,
    [SPECIES_METAGROSS] = sMetagrossFormSpeciesIdTable,
    [SPECIES_LATIAS] = sLatiasFormSpeciesIdTable,
    [SPECIES_LATIOS] = sLatiosFormSpeciesIdTable,
    [SPECIES_KYOGRE] = sKyogreFormSpeciesIdTable,
    [SPECIES_GROUDON] = sGroudonFormSpeciesIdTable,
    [SPECIES_RAYQUAZA] = sRayquazaFormSpeciesIdTable,
    [SPECIES_DEOXYS] = sDeoxysFormSpeciesIdTable,
    [SPECIES_BURMY] = sBurmyFormSpeciesIdTable,
    [SPECIES_WORMADAM] = sWormadamFormSpeciesIdTable,
    [SPECIES_CHERRIM] = sCherrimFormSpeciesIdTable,
    [SPECIES_SHELLOS] = sShellosFormSpeciesIdTable,
    [SPECIES_GASTRODON] = sGastrodonFormSpeciesIdTable,
    [SPECIES_LOPUNNY] = sLopunnyFormSpeciesIdTable,
    [SPECIES_GARCHOMP] = sGarchompFormSpeciesIdTable,
    [SPECIES_LUCARIO] = sLucarioFormSpeciesIdTable,
    [SPECIES_ABOMASNOW] = sAbomasnowFormSpeciesIdTable,
    [SPECIES_GALLADE] = sGalladeFormSpeciesIdTable,
    [SPECIES_ROTOM] = sRotomFormSpeciesIdTable,
    [SPECIES_GIRATINA] = sGiratinaFormSpeciesIdTable,
    [SPECIES_SHAYMIN] = sShayminFormSpeciesIdTable,
    [SPECIES_ARCEUS] = sArceusFormSpeciesIdTable,
    [SPECIES_AUDINO] = sAudinoFormSpeciesIdTable,
    [SPECIES_BASCULIN] = sBasculinFormSpeciesIdTable,
    [SPECIES_DARMANITAN] = sDarmanitanFormSpeciesIdTable,
    [SPECIES_DEERLING] = sDeerlingFormSpeciesIdTable,
    [SPECIES_SAWSBUCK] = sSawsbuckFormSpeciesIdTable,
    [SPECIES_TORNADUS] = sTornadusFormSpeciesIdTable,
    [SPECIES_THUNDURUS] = sThundurusFormSpeciesIdTable,
    [SPECIES_LANDORUS] = sLandorusFormSpeciesIdTable,
    [SPECIES_KYUREM] = sKyuremFormSpeciesIdTable,
    [SPECIES_KELDEO] = sKeldeoFormSpeciesIdTable,
    [SPECIES_MELOETTA] = sMeloettaFormSpeciesIdTable,
    [SPECIES_GENESECT] = sGenesectFormSpeciesIdTable,
    [SPECIES_GRENINJA] = sGreninjaFormSpeciesIdTable,
    [SPECIES_VIVILLON] = sVivillonFormSpeciesIdTable,
    [SPECIES_FLABEBE] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLOETTE] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLORGES] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FURFROU] = sFurfrouFormSpeciesIdTable,
    [SPECIES_MEOWSTIC] = sMeowsticFormSpeciesIdTable,
    [SPECIES_AEGISLASH] = sAegislashFormSpeciesIdTable,
    [SPECIES_PUMPKABOO] = sPumpkabooFormSpeciesIdTable,
    [SPECIES_GOURGEIST] = sGourgeistFormSpeciesIdTable,
    [SPECIES_XERNEAS] = sXerneasFormSpeciesIdTable,
    [SPECIES_ZYGARDE] = sZygardeFormSpeciesIdTable,
    [SPECIES_DIANCIE] = sDiancieFormSpeciesIdTable,
    [SPECIES_HOOPA] = sHoopaFormSpeciesIdTable,
    [SPECIES_ORICORIO] = sOricorioFormSpeciesIdTable,
    [SPECIES_ROCKRUFF] = sRockruffFormSpeciesIdTable,
    [SPECIES_LYCANROC] = sLycanrocFormSpeciesIdTable,
    [SPECIES_WISHIWASHI] = sWishiwashiFormSpeciesIdTable,
    [SPECIES_SILVALLY] = sSilvallyFormSpeciesIdTable,
    [SPECIES_MINIOR] = sMiniorFormSpeciesIdTable,
    [SPECIES_MIMIKYU] = sMimikyuFormSpeciesIdTable,
    [SPECIES_NECROZMA] = sNecrozmaFormSpeciesIdTable,
    [SPECIES_MAGEARNA] = sMagearnaFormSpeciesIdTable,
    // Megas
    [SPECIES_MEGA_VENUSAUR] = sVenusaurFormSpeciesIdTable,
    [SPECIES_MEGA_CHARIZARD_X] = sCharizardFormSpeciesIdTable,
    [SPECIES_MEGA_CHARIZARD_Y] = sCharizardFormSpeciesIdTable,
    [SPECIES_MEGA_BLASTOISE] = sBlastoiseFormSpeciesIdTable,
    [SPECIES_MEGA_BEEDRILL] = sBeedrillFormSpeciesIdTable,
    [SPECIES_MEGA_PIDGEOT] = sPidgeotFormSpeciesIdTable,
    [SPECIES_MEGA_ALAKAZAM] = sAlakazamFormSpeciesIdTable,
    [SPECIES_MEGA_SLOWBRO] = sSlowbroFormSpeciesIdTable,
    [SPECIES_MEGA_GENGAR] = sGengarFormSpeciesIdTable,
    [SPECIES_MEGA_KANGASKHAN] = sKangaskhanFormSpeciesIdTable,
    [SPECIES_MEGA_PINSIR] = sPinsirFormSpeciesIdTable,
    [SPECIES_MEGA_GYARADOS] = sGyaradosFormSpeciesIdTable,
    [SPECIES_MEGA_AERODACTYL] = sAerodactylFormSpeciesIdTable,
    [SPECIES_MEGA_MEWTWO_X] = sMewtwoFormSpeciesIdTable,
    [SPECIES_MEGA_MEWTWO_Y] = sMewtwoFormSpeciesIdTable,
    [SPECIES_MEGA_AMPHAROS] = sAmpharosFormSpeciesIdTable,
    [SPECIES_MEGA_STEELIX] = sSteelixFormSpeciesIdTable,
    [SPECIES_MEGA_SCIZOR] = sScizorFormSpeciesIdTable,
    [SPECIES_MEGA_HERACROSS] = sHeracrossFormSpeciesIdTable,
    [SPECIES_MEGA_HOUNDOOM] = sHoundoomFormSpeciesIdTable,
    [SPECIES_MEGA_TYRANITAR] = sTyranitarFormSpeciesIdTable,
    [SPECIES_MEGA_SCEPTILE] = sSceptileFormSpeciesIdTable,
    [SPECIES_MEGA_BLAZIKEN] = sBlazikenFormSpeciesIdTable,
    [SPECIES_MEGA_SWAMPERT] = sSwampertFormSpeciesIdTable,
    [SPECIES_MEGA_GARDEVOIR] = sGardevoirFormSpeciesIdTable,
    [SPECIES_MEGA_SABLEYE] = sSableyeFormSpeciesIdTable,
    [SPECIES_MEGA_MAWILE] = sMawileFormSpeciesIdTable,
    [SPECIES_MEGA_AGGRON] = sAggronFormSpeciesIdTable,
    [SPECIES_MEGA_MEDICHAM] = sMedichamFormSpeciesIdTable,
    [SPECIES_MEGA_MANECTRIC] = sManectricFormSpeciesIdTable,
    [SPECIES_MEGA_SHARPEDO] = sSharpedoFormSpeciesIdTable,
    [SPECIES_MEGA_CAMERUPT] = sCameruptFormSpeciesIdTable,
    [SPECIES_MEGA_ALTARIA] = sAltariaFormSpeciesIdTable,
    [SPECIES_MEGA_BANETTE] = sBanetteFormSpeciesIdTable,
    [SPECIES_MEGA_ABSOL] = sAbsolFormSpeciesIdTable,
    [SPECIES_MEGA_GLALIE] = sGlalieFormSpeciesIdTable,
    [SPECIES_MEGA_SALAMENCE] = sSalamenceFormSpeciesIdTable,
    [SPECIES_MEGA_METAGROSS] = sMetagrossFormSpeciesIdTable,
    [SPECIES_MEGA_LATIAS] = sLatiasFormSpeciesIdTable,
    [SPECIES_MEGA_LATIOS] = sLatiosFormSpeciesIdTable,
    [SPECIES_MEGA_LOPUNNY] = sLopunnyFormSpeciesIdTable,
    [SPECIES_MEGA_GARCHOMP] = sGarchompFormSpeciesIdTable,
    [SPECIES_MEGA_LUCARIO] = sLucarioFormSpeciesIdTable,
    [SPECIES_MEGA_ABOMASNOW] = sAbomasnowFormSpeciesIdTable,
    [SPECIES_MEGA_GALLADE] = sGalladeFormSpeciesIdTable,
    [SPECIES_MEGA_AUDINO] = sAudinoFormSpeciesIdTable,
    [SPECIES_MEGA_DIANCIE] = sDiancieFormSpeciesIdTable,
    // Special Mega + Primals
    [SPECIES_MEGA_RAYQUAZA] = sRayquazaFormSpeciesIdTable,
    [SPECIES_PRIMAL_KYOGRE] = sKyogreFormSpeciesIdTable,
    [SPECIES_PRIMAL_GROUDON] = sGroudonFormSpeciesIdTable,
	// Alolan Forms
    [SPECIES_ALOLAN_RATTATA] = sRattataFormSpeciesIdTable,
    [SPECIES_ALOLAN_RATICATE] = sRaticateFormSpeciesIdTable,
    [SPECIES_ALOLAN_RAICHU] = sRaichuFormSpeciesIdTable,
    [SPECIES_ALOLAN_SANDSHREW] = sSandshrewFormSpeciesIdTable,
    [SPECIES_ALOLAN_SANDSLASH] = sSandslashFormSpeciesIdTable,
    [SPECIES_ALOLAN_VULPIX] = sVulpixFormSpeciesIdTable,
    [SPECIES_ALOLAN_NINETALES] = sNinetalesFormSpeciesIdTable,
    [SPECIES_ALOLAN_DIGLETT] = sDiglettFormSpeciesIdTable,
    [SPECIES_ALOLAN_DUGTRIO] = sDugtrioFormSpeciesIdTable,
    [SPECIES_ALOLAN_MEOWTH] = sMeowthFormSpeciesIdTable,
    [SPECIES_ALOLAN_PERSIAN] = sPersianFormSpeciesIdTable,
    [SPECIES_ALOLAN_GEODUDE] = sGeodudeFormSpeciesIdTable,
    [SPECIES_ALOLAN_GRAVELER] = sGravelerFormSpeciesIdTable,
    [SPECIES_ALOLAN_GOLEM] = sGolemFormSpeciesIdTable,
    [SPECIES_ALOLAN_GRIMER] = sGrimerFormSpeciesIdTable,
    [SPECIES_ALOLAN_MUK] = sMukFormSpeciesIdTable,
    [SPECIES_ALOLAN_EXEGGUTOR] = sExeggutorFormSpeciesIdTable,
    [SPECIES_ALOLAN_MAROWAK] = sMarowakFormSpeciesIdTable,
    // Misc Forms                               
    // Cosplay Pikachu
    [SPECIES_PIKACHU_COSPLAY] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_ROCK_STAR] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_BELLE] = sPikachuFormSpeciesIdTable,    
    [SPECIES_PIKACHU_POP_STAR] = sPikachuFormSpeciesIdTable, 
    [SPECIES_PIKACHU_PH_D] = sPikachuFormSpeciesIdTable,     
    [SPECIES_PIKACHU_LIBRE] = sPikachuFormSpeciesIdTable,                               
    // Cap Pikachu
    [SPECIES_PIKACHU_ORIGINAL_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_HOENN_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_SINNOH_CAP] = sPikachuFormSpeciesIdTable,    
    [SPECIES_PIKACHU_UNOVA_CAP] = sPikachuFormSpeciesIdTable, 
    [SPECIES_PIKACHU_KALOS_CAP] = sPikachuFormSpeciesIdTable,     
    [SPECIES_PIKACHU_ALOLA_CAP] = sPikachuFormSpeciesIdTable,    
    [SPECIES_PIKACHU_PARTNER_CAP] = sPikachuFormSpeciesIdTable,
    // Pichu    
    [SPECIES_PICHU_SPIKY_EARED] = sPichuFormSpeciesIdTable,    
    // Unown
    [SPECIES_UNOWN_B] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_C] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_D] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_E] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_F] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_G] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_H] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_I] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_J] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_K] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_L] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_M] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_N] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_O] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_P] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_Q] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_R] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_S] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_T] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_U] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_V] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_W] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_X] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_Y] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_Z] = sUnownFormSpeciesIdTable,    
    [SPECIES_UNOWN_EMARK] = sUnownFormSpeciesIdTable,
    [SPECIES_UNOWN_QMARK] = sUnownFormSpeciesIdTable,
    // Castform
    [SPECIES_CASTFORM_SUNNY] = sCastformFormSpeciesIdTable,
    [SPECIES_CASTFORM_RAINY] = sCastformFormSpeciesIdTable,
    [SPECIES_CASTFORM_SNOWY] = sCastformFormSpeciesIdTable,
    // Deoxys
    [SPECIES_DEOXYS_ATTACK] = sDeoxysFormSpeciesIdTable,
    [SPECIES_DEOXYS_DEFENSE] = sDeoxysFormSpeciesIdTable,
    [SPECIES_DEOXYS_SPEED] = sDeoxysFormSpeciesIdTable,
    // Burmy
    [SPECIES_BURMY_SANDY_CLOAK] = sBurmyFormSpeciesIdTable,
    [SPECIES_BURMY_TRASH_CLOAK] = sBurmyFormSpeciesIdTable,
    // Wormadam
    [SPECIES_WORMADAM_SANDY_CLOAK] = sWormadamFormSpeciesIdTable,
    [SPECIES_WORMADAM_TRASH_CLOAK] = sWormadamFormSpeciesIdTable,
    // Cherrim
    [SPECIES_CHERRIM_SUNSHINE] = sCherrimFormSpeciesIdTable,
    // Shellos
    [SPECIES_SHELLOS_EAST_SEA] = sShellosFormSpeciesIdTable,
    // Gastrodon
    [SPECIES_GASTRODON_EAST_SEA] = sGastrodonFormSpeciesIdTable,
    // Rotom
    [SPECIES_ROTOM_HEAT] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_WASH] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_FROST] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_FAN] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_MOW] = sRotomFormSpeciesIdTable,
    // Giratina
    [SPECIES_GIRATINA_ORIGIN] = sGiratinaFormSpeciesIdTable,
    // Shaymin
    [SPECIES_SHAYMIN_SKY] = sShayminFormSpeciesIdTable,
    // Arceus
    [SPECIES_ARCEUS_FIGHTING] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_FLYING] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_POISON] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_GROUND] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_ROCK] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_BUG] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_GHOST] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_STEEL] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_FIRE] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_WATER] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_GRASS] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_ELECTRIC] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_PSYCHIC] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_ICE] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_DRAGON] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_DARK] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_FAIRY] = sArceusFormSpeciesIdTable,
    // Basculin
    [SPECIES_BASCULIN_BLUE_STRIPED] = sBasculinFormSpeciesIdTable,
    // Darmanitan
    [SPECIES_DARMANITAN_ZEN_MODE] = sDarmanitanFormSpeciesIdTable,
    // Deerling
    [SPECIES_DEERLING_SUMMER] = sDeerlingFormSpeciesIdTable,
    [SPECIES_DEERLING_AUTUMN] = sDeerlingFormSpeciesIdTable,
    [SPECIES_DEERLING_WINTER] = sDeerlingFormSpeciesIdTable,
    // Sawsbuck
    [SPECIES_SAWSBUCK_SUMMER] = sSawsbuckFormSpeciesIdTable,
    [SPECIES_SAWSBUCK_AUTUMN] = sSawsbuckFormSpeciesIdTable,
    [SPECIES_SAWSBUCK_WINTER] = sSawsbuckFormSpeciesIdTable,
    // Therian Forms
    [SPECIES_TORNADUS_THERIAN] = sTornadusFormSpeciesIdTable,
    [SPECIES_THUNDURUS_THERIAN] = sThundurusFormSpeciesIdTable,
    [SPECIES_LANDORUS_THERIAN] = sLandorusFormSpeciesIdTable,
    // Kyurem
    [SPECIES_KYUREM_WHITE] = sKyuremFormSpeciesIdTable,
    [SPECIES_KYUREM_BLACK] = sKyuremFormSpeciesIdTable,
    // Keldeo
    [SPECIES_KELDEO_RESOLUTE] = sKeldeoFormSpeciesIdTable,
    // Meloetta
    [SPECIES_MELOETTA_PIROUETTE] = sMeloettaFormSpeciesIdTable,
    // Genesect
    [SPECIES_GENESECT_DOUSE_DRIVE] = sGenesectFormSpeciesIdTable,
    [SPECIES_GENESECT_SHOCK_DRIVE] = sGenesectFormSpeciesIdTable,
    [SPECIES_GENESECT_BURN_DRIVE] = sGenesectFormSpeciesIdTable,
    [SPECIES_GENESECT_CHILL_DRIVE] = sGenesectFormSpeciesIdTable,
    // Greninja
    [SPECIES_GRENINJA_BATTLE_BOND] = sGreninjaFormSpeciesIdTable,
    [SPECIES_GRENINJA_ASH] = sGreninjaFormSpeciesIdTable,
    // Vivillon
    [SPECIES_VIVILLON_POLAR] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_TUNDRA] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_CONTINENTAL] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_GARDEN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_ELEGANT] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MEADOW] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MODERN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MARINE] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_ARCHIPELAGO] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_HIGH_PLAINS] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_SANDSTORM] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_RIVER] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MONSOON] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_SAVANNA] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_SUN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_OCEAN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_JUNGLE] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_FANCY] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_POKE_BALL] = sVivillonFormSpeciesIdTable,
    // Flabébé
    [SPECIES_FLABEBE_YELLOW_FLOWER] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLABEBE_ORANGE_FLOWER] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLABEBE_BLUE_FLOWER] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLABEBE_WHITE_FLOWER] = sFlabebeFormSpeciesIdTable,
    // Floette
    [SPECIES_FLOETTE_YELLOW_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_ORANGE_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_BLUE_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_WHITE_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_ETERNAL_FLOWER] = sFloetteFormSpeciesIdTable,
    // Florges
    [SPECIES_FLORGES_YELLOW_FLOWER] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FLORGES_ORANGE_FLOWER] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FLORGES_BLUE_FLOWER] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FLORGES_WHITE_FLOWER] = sFlorgesFormSpeciesIdTable,
    //Furfrou
    [SPECIES_FURFROU_HEART_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_STAR_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_DIAMOND_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_DEBUTANTE_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_MATRON_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_DANDY_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_LA_REINE_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_KABUKI_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_PHARAOH_TRIM] = sFurfrouFormSpeciesIdTable,
    // Meowstic
    [SPECIES_MEOWSTIC_F] = sMeowsticFormSpeciesIdTable,
    // Aegislash
    [SPECIES_AEGISLASH_BLADE] = sAegislashFormSpeciesIdTable,
    // Pumpkaboo
    [SPECIES_PUMPKABOO_SMALL] = sPumpkabooFormSpeciesIdTable,
    [SPECIES_PUMPKABOO_LARGE] = sPumpkabooFormSpeciesIdTable,
    [SPECIES_PUMPKABOO_SUPER] = sPumpkabooFormSpeciesIdTable,
    // Gourgeist
    [SPECIES_GOURGEIST_SMALL] = sGourgeistFormSpeciesIdTable,
    [SPECIES_GOURGEIST_LARGE] = sGourgeistFormSpeciesIdTable,
    [SPECIES_GOURGEIST_SUPER] = sGourgeistFormSpeciesIdTable,
    // Xerneas
    [SPECIES_XERNEAS_ACTIVE] = sXerneasFormSpeciesIdTable,
    // Zygarde
    [SPECIES_ZYGARDE_10] = sZygardeFormSpeciesIdTable,
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = sZygardeFormSpeciesIdTable,
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = sZygardeFormSpeciesIdTable,
    [SPECIES_ZYGARDE_COMPLETE] = sZygardeFormSpeciesIdTable,
    // Hoopa
    [SPECIES_HOOPA_UNBOUND] = sHoopaFormSpeciesIdTable,
    // Oricorio
    [SPECIES_ORICORIO_POM_POM] = sOricorioFormSpeciesIdTable,
    [SPECIES_ORICORIO_PA_U] = sOricorioFormSpeciesIdTable,
    [SPECIES_ORICORIO_SENSU] = sOricorioFormSpeciesIdTable,
    // Rockruff
    [SPECIES_ROCKRUFF_OWN_TEMPO] = sRockruffFormSpeciesIdTable,
    // Lycanroc
    [SPECIES_LYCANROC_MIDNIGHT] = sLycanrocFormSpeciesIdTable,
    [SPECIES_LYCANROC_DUSK] = sLycanrocFormSpeciesIdTable,
    // Wishiwashi
    [SPECIES_WISHIWASHI_SCHOOL] = sWishiwashiFormSpeciesIdTable,
    // Silvally
    [SPECIES_SILVALLY_FIGHTING] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_FLYING] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_POISON] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_GROUND] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_ROCK] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_BUG] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_GHOST] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_STEEL] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_FIRE] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_WATER] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_GRASS] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_ELECTRIC] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_PSYCHIC] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_ICE] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_DRAGON] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_DARK] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_FAIRY] = sSilvallyFormSpeciesIdTable,
    // Minior
    [SPECIES_MINIOR_METEOR_ORANGE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_YELLOW] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_GREEN] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_BLUE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_INDIGO] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_VIOLET] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_RED] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_ORANGE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_YELLOW] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_GREEN] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_BLUE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_INDIGO] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_VIOLET] = sMiniorFormSpeciesIdTable,
    // Mimikyu
    [SPECIES_MIMIKYU_BUSTED] = sMimikyuFormSpeciesIdTable,
    // Necrozma
    [SPECIES_NECROZMA_DUSK_MANE] = sNecrozmaFormSpeciesIdTable,
    [SPECIES_NECROZMA_DAWN_WINGS] = sNecrozmaFormSpeciesIdTable,
    [SPECIES_NECROZMA_ULTRA] = sNecrozmaFormSpeciesIdTable,
    // Magearna
    [SPECIES_MAGEARNA_ORIGINAL_COLOR] = sMagearnaFormSpeciesIdTable,
};
