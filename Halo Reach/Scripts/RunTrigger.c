Namespace MegaloTrigger
{
    void RunTrigger(Trigger* trigger, long MegaloCodeTable)
    {
        undefined4 uVar1;
        long lVar2;
        char cVar3;
        int iVar4;
        ulong uVar5;
        uint uVar6;
        ulong uVar7;
        undefined4* puVar8;
        ulong uVar9;
        undefined4* puVar10;
        long in_GS_OFFSET;
        bool bVar11;
        undefined auStack232[32];
        undefined8 local_c8;
        long local_c0;
        undefined8 current_player;
        undefined4 current_object;
        undefined4 local_ac;
        uint local_98;
        undefined4 local_90;
        undefined4 local_8c[17];
        ulong local_48;
        long Gamestate;
        byte Trigger_type;

        local_48 = DAT_180990010 ^ (ulong)auStack232;
        uVar7 = 0;
        Gamestate = *(long*)(*(long*)(in_GS_OFFSET + 0x58) + (ulong)GametypeIndex * 8);
        Trigger_type = trigger->TriggerType;
        /* Trigger opcode 0x0: Do */
        if (Trigger_type == 0) {
            RunTriggerCode(trigger, MegaloCodeTable);
        }
        /* Trigger opcode 0x1: Foreach player do */
        else if (Trigger_type == 1) {
            current_player = 0xffffffffffffffff;
            local_c0 = *(long*)(Gamestate + 0x18);
            cVar3 = FUN_180045cf8(&local_c8);
            while (cVar3 != 0) {
                *(undefined4*)(*(long*)(Gamestate + 0x20) + 0x16c) = (undefined4)current_player;
                RunTriggerCode(trigger, MegaloCodeTable);
                cVar3 = FUN_180045cf8(&local_c8);
            }
        }
        /* Trigger opcode 0x2: Foreach player randomly do */
        else if (Trigger_type == 2) {
            current_player = 0xffffffffffffffff;
            local_98 = 0;
            local_c0 = *(long*)(Gamestate + 0x18);
            cVar3 = FUN_180045cf8(&local_c8);
            uVar5 = uVar7;
            if (cVar3 != 0) {
                while (true) {
                    local_98 = (int)uVar5 + 1;
                    *(undefined4*)((long)local_8c + ((long)(int)uVar5 + -1) * 4) =
                        (undefined4)current_player;
                    cVar3 = FUN_180045cf8(&local_c8);
                    if (cVar3 == 0) break;
                    uVar5 = (ulong)local_98;
                }
                uVar5 = (ulong)local_98;
            }
            puVar8 = (undefined4*)((long)local_8c + ((long)(int)uVar5 + -1) * 4);
            if (&local_90 != puVar8) {
                puVar10 = local_8c;
                uVar9 = (ulong)((long)puVar8 + (3 - (long)local_8c)) >> 2;
                if (puVar8 < local_8c) {
                    uVar9 = uVar7;
                }
                uVar7 = 1;
                if (uVar9 != 0) {
                    do {
                        iVar4 = FUN_1800e6814();
                        uVar5 = (ulong)iVar4;
                        if (uVar5 != uVar7) {
                            uVar1 = *puVar10;
                            *puVar10 = *(undefined4*)((long)local_8c + (uVar5 - 1) * 4);
                            *(undefined4*)((long)local_8c + (uVar5 - 1) * 4) = uVar1;
                        }
                        puVar10 = puVar10 + 1;
                        bVar11 = uVar7 != uVar9;
                        uVar7 = uVar7 + 1;
                    } while (bVar11);
                    uVar5 = (ulong)local_98;
                }
            }
            if (0 < (int)uVar5) {
                puVar8 = &local_90;
                do {
                    *(undefined4*)(*(long*)(Gamestate + 0x20) + 0x16c) = *puVar8;
                    RunTriggerCode(trigger, MegaloCodeTable);
                    puVar8 = puVar8 + 1;
                    uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
            }
        }
        /* Trigger opcode 0x3: Foreach team do */
        else if (Trigger_type == 3) {
            do {
                *(int*)(*(long*)(Gamestate + 0x20) + 0x170) = (int)uVar7;
                RunTriggerCode(trigger, MegaloCodeTable);
                uVar6 = (int)uVar7 + 1;
                uVar7 = (ulong)uVar6;
            } while ((int)uVar6 < 9);
        }
        /* Trigger opcode 0x4: Foreach object do */
        else if (Trigger_type == 4) {
            current_object = 0xffffffff;
            local_c8 = 0;
            local_ac = 0x86868686;
            local_c0 = 0x5cf;
            current_player = 0;
            cVar3 = FUN_18046f7c0();
            if (cVar3 != 0)
            {
                while (cVar3 != 0)
                {
                    *(uint*)(*(Gamestate + 0x20) + 0x168) = current_object;
                    RunTriggerCode(trigger, MegaloCodeTable);
                    cVar3 = FUN_18046f7c0(&local_c8);
                };
            }
        }
        // Trigger opcode 0x5: Foreach object with label do
        else {
            game_object NextObject = Gamestate.megalo_stuff.objects_with_labels_table[trigger.ForgeLabel];
            // while the current label list current index is not null
            while (NextObject != -1) {
                // store the current object of the iteration, to be accessed by megaloscript
                Gamestate.megalo_stuff.current_object = NextObject;
                // this array references "object_wrapper"s, its just getting the object data from the current object
                object_data NextObject_data = Gamestate.objects.array_pointer[NextObject.id].object_data;

                // TODO: debug this line at runtime, surely this cant work at all
                // my understanding: NextObject_data.labellistIndex + NextObject_data.LabelTable.start + trigger.forgeLabel * 4? that doesn't make any sense
                NextObject = *(uint*)(NextObject_data.something_ptr + NextObject_data + 0x44 + trigger.ForgeLabel * 4);
                // uVar6 = *(uint*)(*(short*)(lVar2 + 0x196) + lVar2 + 0x44 + trigger->ForgeLabel * 4);

                RunTriggerCode(trigger, MegaloCodeTable);
            }
        }
        FUN_18078a110(local_48 ^ (ulong)auStack232);
        return;
    }


}
