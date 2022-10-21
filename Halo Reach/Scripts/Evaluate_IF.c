
uint Evaluate_IF(Condition* Condition)

{
    uint var2;
    uint _var2;
    uint var1;
    bool Is_True;
    byte Operator;
    byte var1_Type;

    Is_True = false;
    var1_Type = Condition->param_slots[3];
    if (var1_Type == 0) {
        var1 = GetMegaloNumber((short)Condition);
        // if number ?? number
        if (Condition->param_slots[7] == 0) {
        var2_number:
            _var2 = GetMegaloNumber((short)Condition + 4);
        }
        else {
        var2_timer:
            _var2 = GetMegaloTimer_butweird();
        }
        Operator = Condition->param_slots[8];
        if (Operator == 0) {
            var2 = _var2 & 0xffffff00 | (uint)((int)var1 < (int)_var2);
        }
        else if (Operator == 1) {
            var2 = _var2 & 0xffffff00 | (uint)((int)_var2 < (int)var1);
        }
        else if (Operator == 2) {
            var2 = _var2 & 0xffffff00 | (uint)(var1 == _var2);
        }
        else if (Operator == 3) {
            var2 = _var2 & 0xffffff00 | (uint)((int)var1 <= (int)_var2);
        }
        else if (Operator == 4) {
            var2 = _var2 & 0xffffff00 | (uint)((int)_var2 <= (int)var1);
        }
        else {
            var2 = _var2 & 0xffffff00 | (uint)(var1 != _var2);
        }
        Is_True = SUB41(var2, 0);
    }
    else {
        // if player ?? player
        if (var1_Type == 1) {
            var1_Type = Condition->param_slots[8];
            var1 = GetMegaloPlayer((longlong)(Condition->param_slots + 4));
            var2 = GetMegaloPlayer((longlong)Condition);
        }
        else {
            // if object ?? object
            if (var1_Type == 2) {
                var1_Type = Condition->param_slots[8];
                var1 = GetMegaloObject((longlong)(Condition->param_slots + 4));
                var2 = GetMegaloObject((longlong)Condition);
            }
            else {
                // if timer ?? timer/number
                if (var1_Type != 3) {
                    // if out of range - go to end
                    if (var1_Type != 4) goto skip_to_end;
                    var1 = GetMegaloTimer_butweird();
                    if (Condition->param_slots[7] != 4) goto var2_number;
                    goto var2_timer;
                }
                // if team ?? team
                // var1_type = operation_type
                var1_Type = Condition->param_slots[8];
                var1 = GetMegaloTeam((longlong)(Condition->param_slots + 4));
                var2 = GetMegaloTeam((longlong)Condition);
            }
        }
        // if var1 == var2
        if (var1_Type == 2) {
            Is_True = var2 == var1;
        }
        else {
            Is_True = var2 != var1;
        }
    }
skip_to_end:
    return var2 & 0xffffff00 | (uint)Is_True;
}

