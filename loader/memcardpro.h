// Apache V2 License


#ifndef MCPRO_H
#define MCPRO_H

//
// Asm functions
//

extern int MemCardPro_Ping(int port01);
extern int MemCardPro_SendGameID(int port01, int maxLen255, char *gameID);

extern int MemCardPro_NextCH(int port01);
extern int MemCardPro_PrevCH(int port01);
extern int MemCardPro_NextDIR(int port01);
extern int MemCardPro_PrevDIR(int port01);

// Not a hard and fast rule, but here as a reminder that
// there should be a decent delay between 
// e.g. back to back Ping() and SendGameID() commands
// Ideally a frame, but at least a few ms.
extern int MemcardPro_InterCommandDelay();

//
// Errors:
//

#define MCPRO_0_NO_ERROR
#define MCPRO_1_BUS_SELECT_FAIL
// e.g no ping response, failed to change channel, etc.
#define MCPRO_2_OPERATION_FAILED
#define MCPRO_3_RESERVE_FAIL
#define MCPRO_4_STRING_LENGTH_OR_SUCCESS_FAIL
#define MCPRO_5_DATA_TRANSMISSION_FAIL

#define MCPRO_PORT_0 0
#define MCPRO_PORT_1 1

#endif /* MCPRO_H */