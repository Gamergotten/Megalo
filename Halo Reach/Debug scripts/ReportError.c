void ReportError(undefined8* param_1)

{
    char cVar1;
    longlong* plVar2;
    undefined auStack120[32];
    undefined local_58[64];
    ulonglong local_18;

    local_18 = DAT_14222db28 ^ (ulonglong)auStack120;
    if (param_1 != (undefined8*)0x0) {
        FUN_1400a1360(local_58, &DAT_1415b1504, *(undefined4*)(param_1 + 2));
        FUN_1400a9300("assert_handle_slim_constant :: ");
        FUN_1400a9300(*param_1);
        FUN_1400a9300(&DAT_1415b151c);
        FUN_1400a9300(param_1[1]);
        FUN_1400a9300(&DAT_1415b151c);
        FUN_1400a9300(local_58);
        FUN_1400a9300(&DAT_1415b1524);
        FUN_1400a0330("%s(%d): assert_handle_slim_constant :: %s\n", param_1[1],
            *(undefined4*)(param_1 + 2), *param_1);
    }
    cVar1 = FUN_1400a1f90();
    if (cVar1 != '\0') {
        plVar2 = (longlong*)FUN_1400a2020();
        (**(code**)(*plVar2 + 0x28))(plVar2, param_1);
    }
    FUN_140edc990(local_18 ^ (ulonglong)auStack120);
    return;
}