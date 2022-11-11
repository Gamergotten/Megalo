
enum conditions
{
    None = 0,
    _if = 1,
    object_in_area = 2,
    player_died = 3,
    team_disposition = 4,
    timer_expired = 5,
    object_is_type = 6,
    team_is_active = 7,
    object_out_of_bounds = 8,
    player_is_fire_team_leader = 9,
    player_assisted_with_kill = 10,
    object_matches_filter = 11,
    player_is_active = 12,
    equipment_is_active = 13,
    player_is_spartan = 14,
    player_is_elite = 15,
    player_is_editor = 16,
    game_is_forge = 17
};




char Evaluate_Condition(Condition* Condition_Address)

{
    uint uVar1;
    undefined4 uVar2;
    int iVar3;
    int iVar4;
    longlong* plVar5;
    uint* puVar6;
    ulonglong uVar7;
    longlong lVar8;
    byte bVar9;
    longlong in_GS_OFFSET;
    char CounditionTrue;

    bVar9 = Condition_Address->function_id;
    CounditionTrue = true;

    switch (Condition_Address->function_id)
    {
        case conditions.none:
            
            break;
        case conditions._if:
            uVar1 = Evaluate_IF(Condition_Address);
            CounditionTrue = (char)uVar1;
            break;
        case conditions.object_in_area:
            CounditionTrue = FUN_1801cc0c0();
            break;
        case conditions.player_died:
            iVar3 = GetMegaloPlayer((longlong)Condition_Address);
            uVar7 = FUN_1801cd8a8(*(longlong*)(*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20) + 0x168, iVar3);
            if ((uVar7 != 0) && ((Condition_Address->param_slots[3] & 1 << (*(byte*)(uVar7 + 10) & 0x1f)) != 0))
                goto Complete_Condition_Evaluation; // idk where this lead to, musta forgot to copy paste it here whoops
            break;
        case conditions.team_disposition:
            iVar3 = GetMegaloTeam((longlong)Condition_Address);
            iVar4 = GetMegaloTeam((longlong)(Condition_Address->param_slots + 3));
            if ((iVar3 == 8) || (iVar4 == 8)) {
                bVar9 = 0;
            }
            else if ((iVar3 == -1) || (iVar4 == -1)) {
                bVar9 = 2;
            }
            else {
                bVar9 = (iVar3 != iVar4) + 1;
            }
            CounditionTrue = bVar9 == Condition_Address->param_slots[6];
            break;
        case conditions.timer_expired:
            CounditionTrue = 0;
            iVar3 = GetMegaloTimer((longlong)Condition_Address);
            if ((-1 < iVar3) &&
                (puVar6 = (uint*)FUN_1801cb92c(Condition_Address,
                    uVar7 & 0xffffffffffffff00 | 1),
                    puVar6 != (uint*)0x0)) {
                CounditionTrue = (*puVar6 & 0xffffff) == 0;
            }
            break;
        case conditions.object_is_type:
            CounditionTrue = 0;
            uVar1 = GetMegaloObject((longlong)Condition_Address);
            uVar7 = (ulonglong)uVar1;
            if (uVar1 != 0xffffffff) {
                iVar3 = FUN_1801242c8(*(undefined4*)(Condition_Address->param_slots + 4)
                );
                CounditionTrue = **(int**)(*(longlong*)(*(longlong*)(*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) +(ulonglong)GametypeIndex * 8) + 8) + 0x50) + 0x10 + (uVar7 & 0xffff) * 0x18) == iVar3;
            }
            break;
        case conditions.team_is_active:
            uVar1 = GetMegaloTeam((longlong)Condition_Address);
            plVar5 = (longlong*)Return_GametypeLocation();
            CounditionTrue = (**(code**)(*plVar5 + 0x40))(plVar5);
            if (CounditionTrue == 0) {
                uVar2 = FUN_180039efc(uVar1);
                CounditionTrue = FUN_180039d30(uVar2);
            }
            else {
                CounditionTrue = uVar1 < 2;
            }
            break;
        case conditions.object_out_of_bounds:
            CounditionTrue = FUN_1801cc1ac();
            break;
        case conditions.player_is_fire_team_leader:
            GetMegaloPlayer((longlong)Condition_Address);
            CounditionTrue = 0;
            break;
        case conditions.player_assisted_with_kill:
            lVar8 = *(longlong*)
                (*(longlong*)
                    (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20);
            iVar3 = GetMegaloPlayer((longlong)(Condition_Address->param_slots + 3));
            uVar7 = FUN_1801cd8a8(lVar8 + 0x168, iVar3);
            CounditionTrue = '\0';
            if ((uVar7 != 0) &&
                (uVar1 = GetMegaloPlayer((longlong)Condition_Address), uVar1 != 0xffffffff)) {
                CounditionTrue = (*(uint*)(uVar7 + 0xc) >> (uVar1 & 0x1f) & 1) != 0;
            }
            break;
        case conditions.object_matches_filter:
            CounditionTrue = '\0';
            uVar1 = GetMegaloObject((longlong)Condition_Address);
            uVar7 = (ulonglong)uVar1;
            if ((uVar1 != 0xffffffff) && (*(int*)(Condition_Address->param_slots + 4) != -1)) {
                lVar8 = Return_GametypeLocation();
                CounditionTrue =
                    FUN_1801ce110(((longlong) * (int*)(Condition_Address->param_slots + 4) + 0xe4e
                        ) * 0x10 + lVar8, uVar7 & 0xffffffff);
            }
            break;
        case conditions.player_is_active:
            iVar3 = GetMegaloPlayer((longlong)Condition_Address);
            CounditionTrue = '\0';
            if (iVar3 != -1) {
                CounditionTrue = FUN_180045b7c((ushort)iVar3);
            }
            break;
        case conditions.equipment_is_active:
            uVar1 = GetMegaloObject((longlong)Condition_Address);
            CounditionTrue = '\0';
            if (uVar1 != 0xffffffff) {
                lVar8 = *(longlong*)
                    (*(longlong*)
                        (*(longlong*)
                            (*(longlong*)(in_GS_OFFSET + 0x58) +
                                (ulonglong)GametypeIndex * 8) + 8) + 0x50);
                if (*(char*)(lVar8 + 4 + (ulonglong)(uVar1 & 0xffff) * 0x18) == 3) {
                    CounditionTrue =
                        *(int*)(*(longlong*)
                            (lVar8 + 0x10 + (ulonglong)(uVar1 & 0xffff) * 0x18) +
                            0x1d8) != -1;
                }
            }
            break;
        case conditions.player_is_spartan:
            iVar3 = GetMegaloPlayer((longlong)Condition_Address);
            CounditionTrue = '\0';
            if (iVar3 != -1) {
                iVar3 = FUN_180044128(iVar3);
                CounditionTrue = iVar3 == 0;
            }
            break;
        case conditions.player_is_elite:
            iVar3 = GetMegaloPlayer((longlong)Condition_Address);
            CounditionTrue = '\0';
            if (iVar3 != -1) {
                iVar3 = FUN_180044128(iVar3);
                CounditionTrue = iVar3 == 1;
            }
            break;
        case conditions.player_is_editor:
            iVar3 = GetMegaloPlayer((longlong)Condition_Address);
            CounditionTrue = '\0';
            if (iVar3 != -1) {
                CounditionTrue = FUN_180060c74(iVar3, 0);
                CounditionTrue = CounditionTrue != '\0';
            }
            break;
        case conditions.game_is_forge:
            CounditionTrue = Game.IsForge();
            break;
    }
    // if condition is NOT, then flip the value
    if (Condition_Address->inverted != 0) {
        CounditionTrue = CounditionTrue == 0;
    }
    // take all of the bytes from outInt except the last which we add from outbyte
    return CounditionTrue;
}

