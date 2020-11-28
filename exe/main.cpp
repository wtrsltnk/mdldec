/*
==============================================================

	Half-Life MDL Decompiler
	2002, Kratisto. Based on code from HL SDK

==============================================================
*/


#define WIN32_LEAN_AND_MEAN 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "..\class\mdldec.h"

int main(int argc, char *argv[])
{
	CMDLDecompiler *mdl = new CMDLDecompiler;

	printf("\nHalf-Life MDL Decompiler v1.01.\n");
	printf("2002, Kratisto. Based on code from Valve's HL SDK.\n");
	printf("--------------------------------------------------\n");

	if (argc == 1)
	{
		printf("Usage: mdldec.exe <path\\mdlfile.mdl> [<destpath>]\n");
		printf("--------------------------------------------------\n");
	
		return 1;
	}

	if (argc == 3)
		strcpy(mdl->DestPath, argv[2]);

	if (mdl->LoadModel(argv[1]))
	{
		//mdl.DumpInfo();
		mdl->FixRepeatedSequenceNames();
		mdl->QC_GenerateScript();
		mdl->SMD_GenerateReferences();
		mdl->SMD_GenerateSequences();
		mdl->BMP_GenerateTextures();
		mdl->LogMessage(MDLDEC_MSG_INFO,"Done.\r\n");
	}

	printf("--------------------------------------------------\n");

	delete mdl;
	return 0;
}
