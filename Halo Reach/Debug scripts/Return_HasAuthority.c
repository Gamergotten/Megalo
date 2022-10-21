bool Return_HasAuthority(void)

{
    char* pcVar1;
    char** ppcVar2;
    longlong in_GS_OFFSET;

    ppcVar2 = (char**)Gamestate->unk0x418);
    pcVar1 = *ppcVar2;
    if ((pcVar1 == (char*)0x0) || ((*pcVar1 == 0 && (pcVar1[1] == 0)))) {
        ReportError(&PTR_s_game_globals_&&_(game_globals->i_141600d48);
        pcVar1 = *ppcVar2;
    }
    return *(int*)(pcVar1 + 0x14) != 4;
}