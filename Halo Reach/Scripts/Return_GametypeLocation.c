
// WARNING: Unknown calling convention yet parameter storage is locked

longlong Return_GametypeLocation(void)

{
    longlong lVar1;
    longlong lVar2;
    longlong in_GS_OFFSET;

    lVar1 = *(longlong*)
        (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x50
            );
    lVar2 = 0;
    if (*(int*)(lVar1 + 0x10) - 1U < 3) {
        lVar2 = lVar1 + 0x38;
    }
    return lVar2 + 4;
}

