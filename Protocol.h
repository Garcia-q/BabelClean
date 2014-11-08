#ifndef PROTOCOL_H
#define PROTOCOL_H

#define WELCOME "salut"
#define SUCCESS	1
#define FAILURE	-1
#define ERROR_INSTRUCTION "Bad Instruction\n"

enum			PROTOCOLE_ENUM
{
    WELCOME = 0,
    AUTH,
    CONTACT_LIST,
    CONTACT_ADD,
    CONTACT_REMOVE,
    CONTACT_CALL_ME,
    CONTACT_TO_CALL,
    SEND_AUDIO,
    DISCONNECT
};

struct					Proto_Struct
{
    PROTOCOLE_ENUM		EnumId;
    char				Buffer[512];
};
typedef				Proto_Struct Struct_Proto;

#endif // PROTOCOL_H
