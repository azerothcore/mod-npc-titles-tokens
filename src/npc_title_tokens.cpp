/*
<--------------------------------------------------------------------------->
- Developer(s): NuskyDev and VhiperDev
- Complete: 100%
- Atualizado: 14/05/2018
<--------------------------------------------------------------------------->
*/

#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "DBCStores.h"

enum eTitles
{
    JUSTICAR = 48,
    PROPHET = 89,
    STALKER = 91,
    ASSASSIN = 95,
    DOCTOR = 101,
    THE_FORSAKEN = 119,
    AMBASSADOR = 130,
    THE_IMMORTAL = 141,
    THE_UNDYING = 142,
    JENKINS = 143,
    THE_INSANE = 145,
    THE_NOBLE = 155,
    STARCALLER = 164,
};

enum eTokens
{
    // Item ID
    TOKEN_ID = 37829,

    // Cost
    TITLE1_COST = 100,
    TITLE2_COST = 500,
    TITLE3_COST = 1250,
    TITLE4_COST = 2500,
    TITLE5_COST = 3000,
    TITLE6_COST = 4500,
    TITLE7_COST = 6000,
    TITLE8_COST = 7500,
    TITLE9_COST = 10000,
    TITLE10_COST = 12500,
    TITLE11_COST = 15000,
    TITLE12_COST = 17500,
    TITLE13_COST = 20000
};

class NPC_Title_Tokens : public CreatureScript
{
public:
    NPC_Title_Tokens() : CreatureScript("NPC_Title_Tokens") {}

    bool OnGossipHello(Player *player, Creature *creature) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_01:24:24:-18:0|tJusticar (100 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_02:24:24:-18:0|tProphet (500 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_03:24:24:-18:0|tStalker (1250 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_04:24:24:-18:0|tAssassin (2500 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_05:24:24:-18:0|tDoctor (3000 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_06:24:24:-18:0|tThe Forsaken (4500 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_07:24:24:-18:0|tAmbassador (6000 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_08:24:24:-18:0|tThe Imortal (7500 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_09:24:24:-18:0|tThe Undying (10000 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_10:24:24:-18:0|tJenkins (12500 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_11:24:24:-18:0|tThe Insane (15000 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_12:24:24:-18:0|tThe Noble (17500 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface/ICONS/Achievement_PVP_P_13:24:24:-18:0|tStarcaller (20000 Tokens)|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
        AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "|TInterface/ICONS/Ability_Spy:24:24:-18:0|t|r Sair|r", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 999);
        SendGossipMenuFor(player, 1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *creature, uint32 /*senders*/, uint32 actions) override
    {
        switch (actions)
        {
        case GOSSIP_ACTION_INFO_DEF + 0:
            AddTitle(player, TOKEN_ID, TITLE1_COST, JUSTICAR);
            break;

        case GOSSIP_ACTION_INFO_DEF + 1:
            AddTitle(player, TOKEN_ID, TITLE2_COST, PROPHET);
            break;

        case GOSSIP_ACTION_INFO_DEF + 2:
            AddTitle(player, TOKEN_ID, TITLE3_COST, STALKER);
            break;

        case GOSSIP_ACTION_INFO_DEF + 3:
            AddTitle(player, TOKEN_ID, TITLE4_COST, ASSASSIN);
            break;

        case GOSSIP_ACTION_INFO_DEF + 4:
            AddTitle(player, TOKEN_ID, TITLE5_COST, DOCTOR);
            break;

        case GOSSIP_ACTION_INFO_DEF + 5:
            AddTitle(player, TOKEN_ID, TITLE6_COST, THE_FORSAKEN);
            break;

        case GOSSIP_ACTION_INFO_DEF + 6:
            AddTitle(player, TOKEN_ID, TITLE7_COST, AMBASSADOR);
            break;

        case GOSSIP_ACTION_INFO_DEF + 7:
            AddTitle(player, TOKEN_ID, TITLE8_COST, THE_IMMORTAL);
            break;

        case GOSSIP_ACTION_INFO_DEF + 8:
            AddTitle(player, TOKEN_ID, TITLE9_COST, THE_UNDYING);
            break;

        case GOSSIP_ACTION_INFO_DEF + 9:
            AddTitle(player, TOKEN_ID, TITLE10_COST, JENKINS);
            break;

        case GOSSIP_ACTION_INFO_DEF + 10:
            AddTitle(player, TOKEN_ID, TITLE11_COST, THE_INSANE);
            break;

        case GOSSIP_ACTION_INFO_DEF + 11:
            AddTitle(player, TOKEN_ID, TITLE12_COST, THE_NOBLE);
            break;

        case GOSSIP_ACTION_INFO_DEF + 12:
            AddTitle(player, TOKEN_ID, TITLE13_COST, STARCALLER);
            break;

        case GOSSIP_ACTION_INFO_DEF + 999:
            creature->Whisper("Check back often!", LANG_UNIVERSAL, player);

            player->PlayerTalkClass->SendCloseGossip();
            break;
        }
        return true;
    }

    void AddTitle(Player* player, uint32 token, uint32 quantity, uint32 title)
    {
        if (player->HasItemCount(token, quantity, true))
        {
            if (player->HasTitle(title))
            {
                player->GetSession()->SendNotification("|cffe84118[ERRO] \n |cfff5f6faYou can not buy titles you already own.");
            }
            else
            {
                CharTitlesEntry const *titleInfo = sCharTitlesStore.LookupEntry(title);
                player->SetTitle(titleInfo, false);
                player->DestroyItemCount(token, quantity, true, false);
                player->GetSession()->SendNotification("|cff44bd32Congratulations! \n |cfff5f6faTitle successfully purchased.");
            }
            player->PlayerTalkClass->SendCloseGossip();
        }
        else
        {
            player->GetSession()->SendNotification("|cffe84118[ERRO] \n |cfff5f6faYou do not have enough tokens.");
            player->PlayerTalkClass->SendCloseGossip();
        }
    }
};

void AddSC_NPC_Title_Tokens()
{
    new NPC_Title_Tokens();
}
