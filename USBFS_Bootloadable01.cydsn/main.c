/*******************************************************************************
* File Name: main.c
*
* Version: 2.0
*
* Description:
*  This project displays "BootloadableTest" message on the LCD after successful 
*  loading.
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
*  The main function will be called from Bootloder after 2 sec delay and 
*  displays "BootloadableTest" message on the LCD.
*  This delay is set in the Bootloader component in USBFS_Bootloder project.
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
    LCD_PrintString("Image 1");
    
    for(;;)
    {
    }
}


/* [] END OF FILE */
