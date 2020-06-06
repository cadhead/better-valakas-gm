/*==============================================================================
		Delayed Kick/Ban for SA-MP v1.3.4
			by Daniel_Cortez

This include replaces Kick, Ban and BanEx functions with its own versions
that call the original functions with a 0.5-second delay.
You can set the delay time by defining DC_KICKFIX_INTERVAL macro
before #including this file.


Copyright (c) 2014-2018 Stanislav Gromov (Daniel_Cortez)

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the
use of this software.

Permission is granted to anyone to use this software for
any purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1.	The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software in
	a product, an acknowledgment in the product documentation would be
	appreciated but is not required.

2.	Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.

3.	This notice may not be removed or altered from any source distribution.
==============================================================================*/


#if defined DC__KICKFIX_INC
	#endinput
#endif
#define	DC__KICKFIX_INC


#include <a_samp>

#if	!defined	DC_KICKFIX_INTERVAL
	#define		DC_KICKFIX_INTERVAL	500
#endif


// Reserve extra names for the original functions, so it would be
// still possible to call those functions without delay.
native ImmediateKick(playerid) = Kick;
native ImmediateBan(playerid) = Ban;
native ImmediateBanEx(playerid, const reason[]) = BanEx;

// Also make const-correct definitions of GetPVarString(), SetPVarString() and DeletePVar()
// because Kalcor is too busy counting money from the Hosted tab to fix the const-correctness issue.
native __dc_kickfix__GetPVarString(playerid, const varname[], string_return[], len) = GetPVarString;
native __dc_kickfix__SetPVarString(playerid, const varname[], const string_value[]) = SetPVarString;
native __dc_kickfix__DeletePVar(playerid, const varname[]) = DeletePVar;

// Define these strings once, so there won't be multiple copies of them.
static const str__dc_kickfix__d[] = !"d";
static const str__dc_kickfix__reason[] = !"dc_kickfix__reason";


// Delayed kick function for calling via SetTimerEx.
@__dc_kickfix__DoKick(const playerid);
@__dc_kickfix__DoKick(const playerid)
	return Kick(playerid);

// Kick hook.
stock dc_kickfix__Kick(playerid)
{
	if(0 == IsPlayerConnected(playerid))
		return 0;
	SetTimerEx(
		!"@__dc_kickfix__DoKick", DC_KICKFIX_INTERVAL, false,
		str__dc_kickfix__d, playerid
	);
	return 1;
}
#if defined _ALS_Kick
	#undef Kick
#else
	#define _ALS_Kick
#endif
#define	Kick(%0)	dc_kickfix__Kick(%0)


// Delayed ban function for calling via SetTimerEx.
@__dc_kickfix__DoBan(const playerid);
@__dc_kickfix__DoBan(const playerid)
	return Ban(playerid);

// Ban hook.
stock dc_kickfix__Ban(playerid)
{
	if(0 == IsPlayerConnected(playerid))
		return 0;
	SetTimerEx(
		!"@__dc_kickfix__DoBan", DC_KICKFIX_INTERVAL, false,
		str__dc_kickfix__d, playerid
	);
	return 1;
}
#if defined _ALS_Ban
	#undef Ban
#else
	#define _ALS_Ban
#endif
#define	Ban(%0)	dc_kickfix__Ban(%0)


// Delayed ban (extended) function for calling via SetTimerEx.
@__dc_kickfix__DoBanEx(const playerid);
@__dc_kickfix__DoBanEx(const playerid)
{
	goto skip_array_init;
	new reason[128];
skip_array_init:
	// There's a bug in GetPVarString, GetSVarString and some other functions
	// that leads to OOB write if the buffer is too small to fit the string.
	// The list of affected functions can be found in the following article:
	// http://pro-pawn.ru/showthread.php?16186
	// As a workaround we can specify "sizeof(<array>) - 1" instead of
	// "sizeof(<array>)", so no data would be written out of bounds.
	__dc_kickfix__GetPVarString(playerid, str__dc_kickfix__reason, reason, sizeof(reason) - 1);
	__dc_kickfix__DeletePVar(playerid, str__dc_kickfix__reason);
	// Also GetPVarString, GetSVarString and other SA-MP functions convert
	// characters (byte values) to Pawn cells incorrectly, with sign extension.
	// If a character code is greater than 127, bytes 1-3 are set to 0xFF,
	// e.g. instead of 0x000000C0 (#192, 'A' in cyrillic keyboard layout)
	// the character code becomes 0xFFFFFFC0.
	// Some functions like BanEx and fwrite can't save such corrupted symbols
	// into a file properly, so we have to correct them.
	// More information about this bug: http://pro-pawn.ru/showthread.php?13007
	static i; i = -1;
	do {} while((reason[++i] &= 0xFF) != '\0');
	return BanEx(playerid, reason);
}

// BanEx hook.
stock dc_kickfix__BanEx(playerid, const reason[])
{
	if(0 == IsPlayerConnected(playerid))
		return 0;
	__dc_kickfix__SetPVarString(playerid, str__dc_kickfix__reason, reason);
	SetTimerEx(
		!"@__dc_kickfix__DoBanEx", DC_KICKFIX_INTERVAL, false,
		str__dc_kickfix__d, playerid
	);
	return 1;
}
#if defined _ALS_BanEx
	#undef BanEx
#else
	#define _ALS_BanEx
#endif
#define	BanEx(%0)	dc_kickfix__BanEx(%0)
