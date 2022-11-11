
bool EvaluateWidgetToken(astruct* WidgetToken, astruct* PrevToken)
{
    char cVar1;
    longlong AnIndex;
    char* pcVar2;
    int TokenMatchIndex;
    bool AreMatching;
    bool ArentMatching;

    AreMatching = WidgetToken->StringID == PrevToken->StringID;
    TokenMatchIndex = 0;
    if (WidgetToken->StringID == PrevToken->StringID) {
        do {
            if (1 < TokenMatchIndex) break;
            AreMatching = DoTokensMatch((astruct*)
                (&WidgetToken->VarIndex + (longlong)TokenMatchIndex * 4),
                (astruct*)
                (&PrevToken->VarIndex + (longlong)TokenMatchIndex * 4));
            TokenMatchIndex = TokenMatchIndex + 1;
        } while (AreMatching);
    }
    ArentMatching = AreMatching == false;
    if (!ArentMatching) {
        AnIndex = 2;
        pcVar2 = &WidgetToken->field10_0xb;
        do {
            if (1 < AnIndex) break;
            cVar1 = *pcVar2;
            AreMatching = cVar1 == -1;
            AnIndex = AnIndex + 1;
            pcVar2 = pcVar2 + 4;
        } while (cVar1 == -1);
        ArentMatching = AreMatching == false;
        if (!ArentMatching) {
            AnIndex = 2;
            pcVar2 = &PrevToken->field10_0xb;
            do {
                if (1 < AnIndex) break;
                cVar1 = *pcVar2;
                AreMatching = cVar1 == -1;
                AnIndex = AnIndex + 1;
                pcVar2 = pcVar2 + 4;
            } while (cVar1 == -1);
            ArentMatching = AreMatching == false;
        }
    }
    return ArentMatching;
}




bool DoTokensMatch(astruct* WidgetToken, astruct* PrevToken)
{
    bool AreMatching;
    byte NoneVarSource;
    char VarType;

    VarType = WidgetToken->VarType;
    AreMatching = PrevToken->VarType == VarType;
    if (AreMatching) {
        // none types?
        if (VarType == 0) {
            NoneVarSource = WidgetToken->VarSource;
            AreMatching = PrevToken->VarSource == NoneVarSource;
            if (AreMatching) {
                if (NoneVarSource == 0) {
                    AreMatching = PrevToken->VarIndex == WidgetToken->VarIndex;
                }
                else if (((NoneVarSource == 1) || (NoneVarSource == 2)) || (NoneVarSource == 3)) {
                    if ((PrevToken->VarIndex == WidgetToken->VarIndex) &&
                        (WidgetToken->VarSubSource == PrevToken->VarSubSource)) {
                        AreMatching = true;
                    }
                    else {
                        AreMatching = false;
                    }
                }
            }
        }
        else if (VarType == 1) {
            // player types
            AreMatching = DoPlayerTypeTokensMatch(WidgetToken, PrevToken);
        }
        else if (VarType == 2) {
            // object types
            AreMatching = DoObjectTypeTokensMatch(WidgetToken, PrevToken);
        }
        else if (2 < VarType) {
            if (VarType < 5) {
                AreMatching = DoNumericTypeTokensMatch(WidgetToken, PrevToken);
            }
            else if (VarType == 5) {
                AreMatching = DoTimerTypeTokensMatch(WidgetToken, PrevToken);
            }
        }
    }
    return AreMatching;
}

///////////////////
// SUB FUNCTIONS //
///////////////////

bool DoPlayerTypeTokensMatch(astruct* WidgetToken, astruct* PrevToken)
{
    bool DoesMatch;
    char PlayerVarSource;

    PlayerVarSource = WidgetToken->VarSource;
    DoesMatch = PrevToken->VarSource == PlayerVarSource;
    if (!DoesMatch) {
        return DoesMatch;
    }
    if (PlayerVarSource != 0) {
        if (((PlayerVarSource == 1) || (PlayerVarSource == 2)) || (PlayerVarSource == 3)) {
            if ((PrevToken->VarIndex == WidgetToken->VarIndex) &&
                (WidgetToken->VarSubSource == PrevToken->VarSubSource)) {
                return true;
            }
            return false;
        }
        if ((PlayerVarSource != 4) && (PlayerVarSource != 5)) {
            return DoesMatch;
        }
    }
    return PrevToken->VarIndex == WidgetToken->VarIndex;
}

bool DoObjectTypeTokensMatch(astruct* WidgetToken, astruct* PrevToken)
{
    bool AreMatching;
    char ObjectVarSource;

    ObjectVarSource = WidgetToken->VarSource;
    AreMatching = PrevToken->VarSource == ObjectVarSource;
    if (!AreMatching) {
        return AreMatching;
    }
    if (ObjectVarSource == 0) {
    VarSource__0or4:
        AreMatching = PrevToken->VarIndex == WidgetToken->VarIndex;
    }
    else {
        if (((ObjectVarSource != 1) && (ObjectVarSource != 2)) && (ObjectVarSource != 3)) {
            if (ObjectVarSource == 4) goto VarSource__0or4;
            if (((ObjectVarSource != 5) && (ObjectVarSource != 6)) && (ObjectVarSource != 7)) {
                return AreMatching;
            }
        }
        if ((PrevToken->VarIndex == WidgetToken->VarIndex) &&
            (WidgetToken->VarSubSource == PrevToken->VarSubSource)) {
            AreMatching = true;
        }
        else {
            AreMatching = false;
        }
    }
    return AreMatching;
}

// manually fixup this one
bool DoNumericTypeTokensMatch(astruct* WidgetToken, astruct* PrevToken)

{
    bool bVar1;
    bool AreMatching;
    bool bVar2;
    byte NumericVarSource;

    NumericVarSource = WidgetToken->VarSource;
    AreMatching = PrevToken->VarSource == NumericVarSource;
    if (!AreMatching) {
        return AreMatching;
    }
    if (NumericVarSource < 0xf) {
        if (NumericVarSource != 0xe) {
            if (6 < NumericVarSource) {
                if ((9 < NumericVarSource) && (NumericVarSource != 10)) {
                    bVar1 = NumericVarSource - 0xb < 2;
                    bVar2 = NumericVarSource - 0xb == 2;
                    goto LAB_18020adc7;
                }
                goto LAB_18020adc9;
            }
            if (3 < NumericVarSource) {
                return WidgetToken->VarSubSource == PrevToken->VarSubSource;
            }
            if (NumericVarSource == 0) {
                return *(short*)WidgetToken == *(short*)PrevToken;
            }
            if (((NumericVarSource != 1) && (NumericVarSource != 2)) && (NumericVarSource != 3)) {
                return AreMatching;
            }
        }
    LAB_18020ad5e:
        if ((PrevToken->VarIndex == WidgetToken->VarIndex) &&
            (WidgetToken->VarSubSource == PrevToken->VarSubSource)) {
            AreMatching = true;
        }
        else {
            AreMatching = false;
        }
    }
    else {
        if (NumericVarSource < 0x19) {
            if (NumericVarSource != 0x18) {
                if (NumericVarSource == 0xf) goto LAB_18020ad5e;
                if ((NumericVarSource != 0x16) && (NumericVarSource != 0x17)) {
                    return AreMatching;
                }
            }
        }
        else if ((0x1b < NumericVarSource) && (0x1e < NumericVarSource)) {
            bVar1 = NumericVarSource < 0x20;
            bVar2 = NumericVarSource == 0x20;
        LAB_18020adc7:
            if (!bVar1 && !bVar2) {
                return AreMatching;
            }
        }
    LAB_18020adc9:
        AreMatching = PrevToken->VarIndex == WidgetToken->VarIndex;
    }
    return AreMatching;
}

bool DoTimerTypeTokensMatch(astruct* WidgetToken, astruct* PrevToken)

{
    bool AreMatching;
    char TimerVarSource;

    TimerVarSource = WidgetToken->VarSubSource;
    AreMatching = PrevToken->VarSubSource == TimerVarSource;
    if (AreMatching) {
        if (TimerVarSource == 0) {
            AreMatching = WidgetToken->VarSource == PrevToken->VarSource;
        }
        else if (((TimerVarSource == 1) || (TimerVarSource == 2)) || (TimerVarSource == 3)) {
            if ((PrevToken->VarIndex == WidgetToken->VarIndex) &&
                (WidgetToken->VarSource == PrevToken->VarSource)) {
                AreMatching = true;
            }
            else {
                AreMatching = false;
            }
        }
    }
    return AreMatching;
}

