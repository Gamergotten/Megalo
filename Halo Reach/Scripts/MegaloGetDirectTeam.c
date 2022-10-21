
int MegaloGetDirectTeam(char* param_1)

{
    longlong lVar1;
    longlong lVar2;
    ulonglong uVar3;
    longlong* plVar4;
    int ResultingTeamIndex;
    longlong in_GS_OFFSET;
    byte teamIndex;

    teamIndex = *param_1;
    if ((byte)(teamIndex + 1) < 10) {
        ResultingTeamIndex = (int)(char)teamIndex;
    }
    else {
        uVar3 = (ulonglong)GametypeIndex;
        lVar1 = *(longlong*)(in_GS_OFFSET + 0x58);
        if ((byte)(teamIndex - 9) < 8) {
            ResultingTeamIndex =
                (int)*(char*)(*(longlong*)(*(longlong*)(lVar1 + uVar3 * 8) + 0x20) + 0x1db +
                    (longlong)(char)teamIndex);
        }
        else if (teamIndex == 17) {
            ResultingTeamIndex =
                *(int*)(*(longlong*)(*(longlong*)(lVar1 + uVar3 * 8) + 0x20) + 0x170);
        }
        else {
            // hud_player_team
            if (teamIndex == 18) {
                lVar2 = *(longlong*)(*(longlong*)(lVar1 + uVar3 * 8) + 0x20);
                if (*(int*)(lVar2 + 0x178) == -1) {
                    return -1;
                }
            }
            else {
                // hud_target_player_team
                lVar1 = *(longlong*)(lVar1 + uVar3 * 8);
                lVar2 = *(longlong*)(lVar1 + 0x20);
                if (*(int*)(lVar2 + 0x17c) == -1) {
                    if (*(uint*)(lVar2 + 0x180) == 0xffffffff) {
                        return -1;
                    }
                    lVar1 = *(longlong*)
                        (*(longlong*)(*(longlong*)(lVar1 + 8) + 0x50) + 0x10 +
                            (ulonglong)(*(uint*)(lVar2 + 0x180) & 0xffff) * 0x18);
                    return (int)*(char*)((longlong) * (short*)(lVar1 + 0x196) + 0x19 + lVar1);
                }
            }
            if (*(int*)(lVar2 + 0x841c) - 1U < 4) {
                plVar4 = *(longlong**)(&DAT_180a274b8 + (longlong) * (int*)(lVar2 + 0x841c) * 8);
            }
            else {
                plVar4 = (longlong*)0x0;
            }
            ResultingTeamIndex = (**(code**)(*plVar4 + 400))();
        }
    }
    return ResultingTeamIndex;
}

