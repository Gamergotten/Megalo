
void HandleAction(longlong Action)

{
    byte ActionID;
    bool Has_Auth;
    char cVar1;
    undefined4 uVar2;
    char* pcVar3;
    ulonglong uVar4;
    byte bVar5;
    undefined auStack232[32];
    undefined8* local_c8;
    undefined8 local_c0;
    int local_b8;
    undefined local_a8[128];
    ulonglong local_28;

    local_28 = DAT_14222db28 ^ (ulonglong)auStack232;
    ActionID = Action->ID;
    // if index is out of range: report error
    if (0x62 < ActionID) {
        ReportError(&PTR_s_VALID_INDEX(m_action_type,_k_num_1417bdeb0);
        ActionID = Action->ID;
    }
    if (ActionID == 0) goto Action_SkipToEnd;
    Has_Auth = Return_HasAuthority();
    if ((!Has_Auth) && (Has_Auth = DetermineAction_DoesntNeedAuth(Action), !Has_Auth)) {
        ReportError(&PTR_s_game_is_authoritative()_||_execu_1417bdf00);
    }
    if (DAT_1446b77b0 != 0) {
        local_b8 = DAT_142009f60;
        local_c8 = &local_c0;
        local_c0 = 2;
        cVar1 = FUN_1400a1b10(&local_c0);
        if (cVar1 != 0) {
            ActionID = Action->ID;
            local_a8[0] = 0;
            if (ActionID < 99) {
            LAB_1405d620a:
                if (0x62 < ActionID) {
                    ReportError(&PTR_s_(long)value_ < _(long)get_max_coun_1417bde98);
                }
                bVar5 = ActionID;
                if (ActionID == 0) {
                    bVar5 = 0;
                }
                if (bVar5 < 0x62) {
                    uVar4 = (ulonglong)ActionID;
                    if (ActionID == 0) {
                        uVar4 = 0;
                    }
                }
                else {
                    uVar4 = 0x62;
                }
                pcVar3 = (&PTR_DAT_142009c30)[uVar4];
            }
            else {
                ReportError(&PTR_s_in_range()_1417be198);
                ActionID = Action->ID;
                if (ActionID < 99) goto LAB_1405d620a;
                pcVar3 = "enum_out_of_range";
            }
            FUN_1400a0f20(local_a8, pcVar3, 0x80);
            uVar2 = FUN_14009de80(&local_c8, "megalo: executing action %s", local_a8);
            if (local_b8 == -1) {
                FUN_1400a1b50(uVar2);
            }
        }
    }
    switch (*(undefined*)(Action + 0x10)) {
    case 1:
        FUN_1407b0300(Action);
        break;
    case 2:
        FUN_1407ab650(Action);
        break;
    case 3:
        FUN_1407abd20(Action);
        break;
    case 4:
        FUN_1407ad1b0(Action);
        break;
    case 5:
        FUN_1407acf50(Action);
        break;
    case 6:
        FUN_1407acff0(Action);
        break;
    case 7:
        FUN_1407ad140(Action);
        break;
    case 8:
        FUN_1407ad230(Action);
        break;
    case 9:
        FUN_1407afc30(Action);
        break;
    case 10:
        FUN_1407af800(Action);
        break;
    case 0xb:
        FUN_1407ab1d0(Action);
        break;
    case 0xc:
        FUN_1407b00a0(Action);
        break;
    case 0xd:
        FUN_1407b0180(Action);
        break;
    case 0xe:
        FUN_1407afb50(Action);
        break;
    case 0xf:
        FUN_1407b0110(Action);
        break;
    case 0x10:
        FUN_1407ac7a0(Action);
        break;
    case 0x11:
        FUN_1407b0750(Action);
        break;
    case 0x12:
        FUN_1407af620(Action);
        break;
    case 0x13:
        FUN_1407ac5a0(Action);
        break;
    case 0x14:
        FUN_1407ac470(Action);
        break;
    case 0x15:
        FUN_1407ac460(Action);
        break;
    case 0x16:
        FUN_1407ab600(Action);
        break;
    case 0x17:
        FUN_1407adc80(Action);
        break;
    case 0x18:
        FUN_1407ae550(Action);
        break;
    case 0x19:
        FUN_1407af670(Action);
        break;
    case 0x1a:
        FUN_1407ab640(Action);
        break;
    case 0x1b:
        FUN_1407ae140(Action);
        break;
    case 0x1c:
        FUN_1407ae490(Action);
        break;
    case 0x1d:
        FUN_1407aec30(Action);
        break;
    case 0x1e:
        FUN_1407aebf0(Action);
        break;
    case 0x1f:
        FUN_1407aec70(Action);
        break;
    case 0x20:
        FUN_1407abd10(Action);
        break;
    case 0x21:
        FUN_1407ad890(Action);
        break;
    case 0x22:
        FUN_1407add10(Action);
        break;
    case 0x23:
        FUN_1407aee30(Action);
        break;
    case 0x24:
        FUN_1407b0470(Action);
        break;
    case 0x25:
        FUN_1407aee00(Action);
        break;
    case 0x26:
        FUN_1407aeb80(Action);
        break;
    case 0x27:
        FUN_1407aecb0(Action);
        break;
    case 0x28:
        FUN_1407aef00(Action);
        break;
    case 0x29:
        FUN_1407af5a0(Action);
        break;
    case 0x2a:
        FUN_1407af4d0(Action);
        break;
    case 0x2b:
        FUN_1407b0700(Action);
        break;
    case 0x2c:
        FUN_1407b0790(Action);
        break;
    case 0x2d:
        FUN_1407adae0(Action);
        break;
    case 0x2e:
        FUN_1407acce0(Action);
        break;
    case 0x2f:
        FUN_1407acda0(Action);
        break;
    case 0x30:
        FUN_1407acc20(Action);
        break;
    case 0x31:
        FUN_1407acb70(Action);
        break;
    case 0x32:
        FUN_1407ace60(Action);
        break;
    case 0x33:
        FUN_1407aeaf0(Action);
        break;
    case 0x34:
        FUN_1407aea70(Action);
        break;
    case 0x35:
        FUN_1407ad060(Action);
        break;
    case 0x36:
        FUN_1407ae420(Action);
        break;
    case 0x37:
        FUN_1407ae0b0(Action);
        break;
    case 0x38:
        FUN_1407af2c0(Action);
        break;
    case 0x39:
        FUN_1407af210(Action);
        break;
    case 0x3a:
        FUN_1407af190(Action);
        break;
    case 0x3b:
        FUN_1407b04a0(Action);
        break;
    case 0x3c:
        FUN_1407b05b0(Action);
        break;
    case 0x3d:
        FUN_1407af360(Action);
        break;
    case 0x3e:
        FUN_1407aedd0(Action);
        break;
    case 0x3f:
        FUN_1407af150(Action);
        break;
    case 0x40:
        FUN_1407ad720(Action);
        break;
    case 0x41:
        FUN_1407ad350(Action);
        break;
    case 0x42:
        FUN_1407adfd0(Action);
        break;
    case 0x43:
        FUN_1407ad5f0(Action);
        break;
    case 0x44:
        FUN_1407ad480(Action);
        break;
    case 0x45:
        FUN_1407af410(Action);
        break;
    case 0x46:
        FUN_1407ac360(Action);
        break;
    case 0x47:
        FUN_1407abfc0(Action);
        break;
    case 0x48:
        FUN_1407ac1a0(Action);
        break;
    case 0x49:
        FUN_1407abee0(Action);
        break;
    case 0x4a:
        FUN_1407ab030(Action);
        break;
    case 0x4b:
        FUN_1407b0420(Action);
        break;
    case 0x4c:
        FUN_1407b0440(Action);
        break;
    case 0x4d:
        FUN_1407afbe0(Action);
        break;
    case 0x4e:
        FUN_1407ac2a0(Action);
        break;
    case 0x4f:
        FUN_1407abd70(Action);
        break;
    case 0x50:
        FUN_1407ac0a0(Action);
        break;
    case 0x51:
        FUN_1407af780(Action);
        break;
    case 0x52:
        FUN_1407af6f0(Action);
        break;
    case 0x53:
        FUN_1407aefc0(Action);
        break;
    case 0x54:
        FUN_1407aed60(Action);
        break;
    case 0x55:
        FUN_1407ae5b0(Action);
        break;
    case 0x56:
        FUN_1407aee60(Action);
        break;
    case 0x57:
        FUN_1407abaf0(Action);
        break;
    case 0x58:
        FUN_1407abcf0(Action);
        break;
    case 0x59:
        FUN_1407af060(Action);
        break;
    case 0x5a:
        FUN_1407af0e0(Action);
        break;
    case 0x5b:
        FUN_1407ae690(Action);
        break;
    case 0x5c:
        FUN_1407add30(Action);
        break;
    case 0x5d:
        FUN_1407ab3b0(Action);
        break;
    case 0x5e:
        FUN_1407ab310(Action);
        break;
    case 0x5f:
        FUN_1407b0220(Action);
        break;
    case 0x60:
        FUN_1407ac630(Action);
        break;
    case 0x61:
        FUN_1407ac550(Action);
        break;
    case 0x62:
        FUN_1407ab5d0(Action);
    }
Action_SkipToEnd:
    FUN_140edc990(local_28 ^ (ulonglong)auStack232);
    return;
}

