/*******************************************************************************
* File Name: main.c
*
* Version: 2.0
*
* Description:
*  This project enumerates as a HID device and waits for command from 
*  Bootloader Host Tool.
*  To test bootloader:
*   1. Build the USBFS_Bootloader project. Add the USBFS_Bootloadable 
*      Example Project to current workspace. Add dependency of the bootloadable 
*      project to the latest bootloader hex file. Build USBFS_Bootloadable 
*      project and program the Bootloader hex file on to the target device.
*   2. Connect USB cable from the computer to the CY8CKIT-001.
*   3. Select 3.3V in SW3 and plug-in power to the CY8CKIT-001
*   4. Run Bootloader Host Tool from PSoC Creator/Tools menu.
*   5. Select USB Human Interface Device[04B4_B71D] in Ports window. 
*   6. Open Bootloadable.cyacd file and press Program button.
*   7. Observe correct message on LCD: "BootloadableTest".   
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  The main code starts boot loader.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void main()
{
	LCD_Start();
	LCD_Position(0,0);
	LCD_PrintString("Btldr");
	
	if(SW_Read() == 0)
	{
		 /* Initialize Flash subsystem for non-PSoC 4 devices */
	    #if(!CY_PSOC4)
			uint8 flashBuffer[Bootloader_FROW_SIZE];
			
	        if (CYRET_SUCCESS != CySetTemp())
	        {
	            CyHalt(0x00u);
	        }

	        if (CYRET_SUCCESS != CySetFlashEEBuffer(flashBuffer))
	        {
	            CyHalt(0x00u);
	        }
	    #endif  /* (CY_PSOC4) */
	
		LCD_ClearDisplay();
		LCD_Position(0,0);
		if(Bootloader_MD_BTLDB_ACTIVE_VALUE(0u) == Bootloader_MD_BTLDB_IS_ACTIVE)
		{
			LCD_PrintString("1");
			Bootloader_SetFlashByte((uint32)Bootloader_MD_BTLDB_ACTIVE_OFFSET(0), 0);
			Bootloader_SetFlashByte((uint32) Bootloader_MD_BTLDB_ACTIVE_OFFSET(1), 1);
		}
		else
		{
			LCD_PrintString("0");
			Bootloader_SetFlashByte((uint32) Bootloader_MD_BTLDB_ACTIVE_OFFSET(0), 1);
			Bootloader_SetFlashByte((uint32) Bootloader_MD_BTLDB_ACTIVE_OFFSET(1), 0);
		}
	}
    /* Start Boot loader */
    Bootloader_Start();

    /* Code will never be executed here */    
    for(;;)
    {
    }
}


/* [] END OF FILE */
