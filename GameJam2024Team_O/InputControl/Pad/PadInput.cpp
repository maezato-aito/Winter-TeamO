#include "PadInput.h"

char PadInput::now_key1[BUTTON];
char PadInput::now_key2[BUTTON];
char PadInput::old_key1[BUTTON];
char PadInput::old_key2[BUTTON];
XINPUT_STATE PadInput::input1;
XINPUT_STATE PadInput::input2;
Stick PadInput::l_stick1;
Stick PadInput::l_stick2;
Stick PadInput::r_stick1;
Stick PadInput::r_stick2;