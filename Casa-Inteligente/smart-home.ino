// Constant pins definition
int BEDROOM1_LIGHT = 2;
int BEDROOM2_LIGHT = 3;
int KITCHEN_LIGHT = 4;
int LIVING_ROOM_LIGHT = 5;

int BEDROOM1_SWITCH = 6;
int BEDROOM2_SWITCH = 7;
int KITCHEN_SWITCH = 8;
int LIVING_ROOM_SWITCH = 9;

int ALARM1 = 10;
int ALARM2 = 11;

int MAIN_DOOR = 12;
int BACK_DOOR = 13;


void setup()
{
    // Initialize pins modes
    pinMode(BEDROOM1_LIGHT, OUTPUT);
    pinMode(BEDROOM2_LIGHT, OUTPUT);
    pinMode(KITCHEN_LIGHT, OUTPUT);
    pinMode(LIVING_ROOM_LIGHT, OUTPUT);
    pinMode(BEDROOM1_SWITCH, INPUT);
    pinMode(BEDROOM2_SWITCH, INPUT);
    pinMode(KITCHEN_SWITCH, INPUT);
    pinMode(LIVING_ROOM_SWITCH, INPUT);
    pinMode(ALARM1, INPUT);
    pinMode(ALARM2, INPUT);
    pinMode(MAIN_DOOR, INPUT);
    pinMode(BACK_DOOR, INPUT);
}

void loop()
{
    // Check bedroom 1 switch
    if (digitalRead(BEDROOM1_SWITCH) == 1)
    {
        digitalWrite(BEDROOM1_LIGHT, HIGH);
    }
    else
    {
        digitalWrite(BEDROOM1_LIGHT, LOW);
    }

    // Check bedroom 2 switch
    if (digitalRead(BEDROOM2_SWITCH) == 1)
    {
        digitalWrite(BEDROOM2_LIGHT, HIGH);
    }
    else
    {
        digitalWrite(BEDROOM2_LIGHT, LOW);
    }

    // Check kitchen switch
    if (digitalRead(KITCHEN_SWITCH) == 1)
    {
        digitalWrite(KITCHEN_LIGHT, HIGH);
    }
    else
    {
        digitalWrite(KITCHEN_LIGHT, LOW);
    }

    // Check living room switch
    if (digitalRead(LIVING_ROOM_SWITCH) == 1)
    {
        digitalWrite(LIVING_ROOM_LIGHT, HIGH);
    }
    else
    {
        digitalWrite(LIVING_ROOM_LIGHT, LOW);
    }

    // Check if the main door is open
    if (digitalRead(MAIN_DOOR) == 1)
    {
        digitalWrite(ALARM1, HIGH);
    }
    else
    {
        digitalWrite(ALARM1, LOW);
    }

    // Check if the back door is open
    if (digitalRead(BACK_DOOR) == 1)
    {
        digitalWrite(ALARM2, HIGH);
    }
    else
    {
        digitalWrite(ALARM2, LOW);
    }
}
